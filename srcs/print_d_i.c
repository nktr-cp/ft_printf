/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 04:49:39 by knishiok          #+#    #+#             */
/*   Updated: 2023/09/28 04:35:35 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_printlen(t_format info, int n)
{
	int	res;

	res = 0;
	if (n < 0 || info.flags.sign)
		res++;
	res += digit_count(n, 10);
	return (res);
}

void	ft_putnbr(t_format *info, int n, int *len, char putsign)
{
	long long	lnb;
	long long	weight;
	int			print_len;

	lnb = (long)n;
	weight = 1;
	print_len = get_printlen(*info, n);
	 if (lnb < 0)
	 	lnb *= -1;
	while (lnb >= 10LL * weight)
		weight *= 10LL;
	if (info->precision + (n < 0) > print_len - (putsign == '+'))
	{
		while (--info->precision + (n < 0) >= print_len - (putsign == '+'))
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

void	printf_d_i(t_format info, int n, int *len)
{
	char	fill;
	char	putsign;
	int		print_len;

	fill = ' ';
	if (!info.flags.precision && info.flags.zero_padding && !(n == 0 && info.precision == 0))
		fill = '0';
	putsign = 'z';
	if (n < 0)
		putsign = '-';
	else if (info.flags.sign)
		putsign = '+';
	else if (info.flags.space)
		putsign = ' ';
	print_len = ft_max(info.precision + (putsign == '+') + (n < 0), get_printlen(info, n));
	if (!info.flags.left_align)
	{
		if (fill == '0' && putsign != 'z')
		{
			*len += ft_putchar(putsign);
			putsign = 'z';
		}
		if (info.width && n == 0 && info.precision == 0)
			*len += ft_putchar(fill);
		while (info.width-- - (putsign == ' ')  > print_len)
			*len += ft_putchar(fill);
		if (putsign != 'z')
			*len += ft_putchar(putsign);
	}
	else if (putsign != 'z')
		*len += ft_putchar(putsign);
	ft_putnbr(&info, n, len, putsign);
	if (info.flags.left_align)
	{
		if (info.width > 0 && n == 0 && info.precision == 0)
			*len += ft_putchar(fill);
		while (info.width-- - (putsign == ' ') > get_printlen(info, n))
			*len += ft_putchar(fill);
	}
}
