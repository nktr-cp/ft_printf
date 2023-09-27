/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:42:46 by knishiok          #+#    #+#             */
/*   Updated: 2023/09/28 04:44:43 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	write (STDOUT_FILENO, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	res;

	res = 0;
	while (s[res])
		write (STDOUT_FILENO, s + res++, 1);
	return (res);
}

static long	ft_strtol_decimal(char **str)
{
	long	res;
	int		neg;

	res = 0;
	neg = 0;
	while (**str == 32 || (**str >= 9 && **str <= 13))
		str++;
	if (**str == '+' || **str == '-')
	{
		if (**str++ == '-')
			neg = 1;
	}
	while (**str >= '0' && **str <= '9')
	{
		if (!neg && (res > (LONG_MAX - (**str - '0')) / 10))
			return (LONG_MAX);
		if (neg && (-res < (LONG_MIN + (**str - '0')) / 10))
			return (LONG_MIN);
		res = res * 10 + (**str - '0');
		(*str)++;
	}
	if (neg)
		res *= -1;
	return (res);
}

int	ft_atoi(const char **str)
{
	return ((int)ft_strtol_decimal((char **)str));
}
