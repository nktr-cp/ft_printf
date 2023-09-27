/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_helper2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 04:49:39 by knishiok          #+#    #+#             */
/*   Updated: 2023/09/27 19:29:59 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*create_nbr(t_format info, int n, int *len)
{
}

int	get_printlen(t_format info, int n)
{
	int	res;

	res = 0;
	if (n < 0 || info.flags.sign)
		res++;
	res += digit_count(n);
	
}

void	printf_d_i(t_format info, int n, int *len)
{
	char	fill;

	fill = ' ';
	if (info.flags.zero_padding)
		fill = '0';
	if (n < 0)
		*len += ft_putchar('-');
}

void	printf_u(t_format info, unsigned int n, int *len)
{
	long	lnb;
	long	weight;

	(void)info;
	lnb = (long)n;
	weight = 1L;
	while (lnb >= 10L * weight)
		weight *= 10L;
	while (weight)
	{
		ft_putchar(lnb / weight + '0');
		(*len)++;
		lnb %= weight;
		weight /= 10L;
	}
}

void	printf_x(t_format info, unsigned int n, int is_large, int *len)
{
	long	lnb;
	long	weight;

	(void)info;
	lnb = (long)n;
	weight = 1L;
	while (lnb >= 16L * weight)
		weight *= 16L;
	while (weight)
	{
		if (is_large)
			ft_putchar(UPPER_HEX[lnb / weight]);
		else
			ft_putchar(LOWER_HEX[lnb / weight]);
		(*len)++;
		lnb %= weight;
		weight /= 16L;
	}
}
