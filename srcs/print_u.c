/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 02:20:09 by knishiok          #+#    #+#             */
/*   Updated: 2023/09/28 02:33:09 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_printulen(t_format info, unsigned int n)
{
	int	res;

	res = 0;
	if (n < 0 || info.flags.sign)
		res++;
	res += digit_count(n, 10);
	return (res);
}

void	ft_putunbr(t_format *info, unsigned int n, int *len)
{
	long long	lnb;
	long long	weight;
	int			print_len;

	lnb = (long)n;
	weight = 1;
	print_len = get_printulen(*info, n);
	 if (lnb < 0)
	// {
	 	lnb *= -1;
	// 	(*len) += ft_putchar('-');
	// }
	// else 
	// {
	// 	if ((*info).flags.sign)
	// 		(*len) += ft_putchar('+');
	// 	else if ((*info).flags.space)
	// 		(*len) += ft_putchar(' ');
	// }
	while (lnb >= 10LL * weight)
		weight *= 10LL;
	if (info->precision + (n < 0) > print_len)
	{
		while (--(*info).precision + (n < 0) >= print_len)
		{
			(*len) += ft_putchar('0');
			info->width--;
		}
		if (n == 0)
			info->precision++;
	}
	if (n == 0 && info->precision == 0)
		return ;
	while (weight)
	{
		(*len) += ft_putchar(lnb / weight + '0');
		lnb %= weight;
		weight /= 10LL;
	}
}

void	printf_u(t_format info, unsigned int n, int *len)
{
	char	fill;
	char	putsign;
	int		print_len;

	fill = ' ';
	if (!info.flags.precision && info.flags.zero_padding && !(n == 0 && info.precision == 0))
		fill = '0';
	print_len = ft_max(info.precision + (n < 0), get_printulen(info, n));
	putsign = 'z';
	if (n < 0)
		putsign = '-';
	else if (info.flags.sign)
		putsign = '+';
	// ここは空白または空文字列
	else if (info.flags.space)
		putsign = ' ';
	if (!info.flags.left_align)
	{
		if (fill == '0' && putsign != 'z')
		{
			*len += ft_putchar(putsign);
			putsign = 'z';
		}
		if (info.width && n == 0 && info.precision == 0)
			*len += ft_putchar(fill);
		while (info.width-- > print_len)
			*len += ft_putchar(fill);
		if (fill == ' ' && putsign != 'z')
		{
			*len += ft_putchar(putsign);
			// if (putsign == '-')
			// 	*len += ft_putchar(putsign);
			// else if (putsign == ' ')
			// && info.width >= get_printlen(info, n))
			// 	*len += ft_putchar(putsign);
		}
	}
	else if (putsign != 'z')
		*len += ft_putchar(putsign);
	ft_putunbr(&info, n, len);
	if (info.flags.left_align)
	{
		if (info.width > 0 && n == 0 && info.precision == 0)
			*len += ft_putchar(fill);
		while (info.width-- > get_printulen(info, n))
		{
			*len += ft_putchar(fill);
		}
	}
}
