/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 02:21:01 by knishiok          #+#    #+#             */
/*   Updated: 2023/09/28 04:39:17 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_printhlen(t_format info, unsigned int n)
{
	int	res;

	res = 0;
	if (n < 0 || info.flags.sign)
		res++;
	res += digit_count(n, 16);
	return (res);
}

void	ft_puthnbr(t_format *info, unsigned int n, int is_large, int *len)
{
	long long	lnb;
	long long	weight;
	int			print_len;

	lnb = (long)n;
	weight = 1;
	print_len = get_printhlen(*info, n);
	if (lnb < 0)
	 	lnb *= -1;
	while (lnb >= 16LL * weight)
		weight *= 16LL;
	if ((*info).precision + (n < 0) > print_len)
	{
		while (--(*info).precision + (n < 0) >= print_len)
		{
			(*len) += ft_putchar('0');
			(*info).width--;
		}
		if (n == 0)
			(*info).precision++;
	}
	if (info->flags.sharp)
	{
		if (n == 0)
		{
			*(len) += ft_putchar('0');
			return ;
		}
		else if (!is_large)
			*(len) += ft_putstr("0x");
		else
			*(len) += ft_putstr("0X");
	}
	if (n == 0 && (*info).precision == 0)
		return ;
	while (weight)
	{
		if (is_large)
			(*len) += ft_putchar(UPPER_HEX[lnb / weight]);
		else
			(*len) += ft_putchar(LOWER_HEX[lnb / weight]);
		lnb %= weight;
		weight /= 16LL;
	}
}

void	printf_x(t_format info, unsigned int n, int is_large, int *len)
{
	char	fill;
	char	putsign;
	int		print_len;

	fill = ' ';
	if (!info.flags.precision && info.flags.zero_padding && !(n == 0 && info.precision == 0))
		fill = '0';
	print_len = ft_max(info.precision + (n < 0), get_printhlen(info, n));
	if (info.flags.sharp)
		print_len -= 2;
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
			*len += ft_putchar(putsign);
		if (info.width && n == 0 && info.precision == 0)
			*len += ft_putchar(fill);
		while (info.width-- > print_len)
			*len += ft_putchar(fill);
		if (fill == ' ' && putsign != 'z')
			*len += ft_putchar(putsign);
	}
	else if (putsign != 'z')
		*len += ft_putchar(putsign);
	ft_puthnbr(&info, n, is_large, len);
	if (info.flags.left_align)
	{
		if (info.width > 0 && n == 0 && info.precision == 0)
			*len += ft_putchar(fill);
		while (info.width-- > get_printhlen(info, n))
		{
			*len += ft_putchar(fill);
		}
	}
}
