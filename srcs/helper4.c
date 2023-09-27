/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 05:20:27 by knishiok          #+#    #+#             */
/*   Updated: 2023/09/28 05:56:25 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_sub(int n, long long *weight, long long *lnb)
{
	*lnb = (long)n;
	*weight = 1LL;
	if (*lnb < 0)
		*lnb *= -1;
	while (*lnb >= 10LL * *weight)
		*weight *= 10LL;
}

void	ft_putunbr_sub(unsigned int n, long long *weight, long long *lnb)
{
	*lnb = (long)n;
	*weight = 1LL;
	if (*lnb < 0)
		*lnb *= -1;
	while (*lnb >= 10LL * *weight)
		*weight *= 10LL;
}

void	ft_putxnbr_sub(unsigned int n, long long *weight, long long *lnb)
{
	*lnb = (long)n;
	*weight = 1LL;
	if (*lnb < 0)
		*lnb *= -1;
	while (*lnb >= 16LL * *weight)
		*weight *= 16LL;
}