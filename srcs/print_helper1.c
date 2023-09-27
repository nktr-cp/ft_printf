/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_helper1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:34:32 by knishiok          #+#    #+#             */
/*   Updated: 2023/09/26 13:18:34 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_c(t_format info, int c, int *len)
{
	char	fill;

	if (info.flags.left_align)
		*len += ft_putchar((char)c);
	if (info.flags.set_width)
	{
		if (info.flags.zero_padding)
			fill = '0';
		else
			fill = ' ';
		while (--info.width)
			*len += ft_putchar(fill);
	}
	if (!info.flags.left_align)
		*len += ft_putchar((char)c);
}

void	printf_s(t_format info, char *s, int *len)
{
	int		s_len;
	int		i;
	char	fill;

	if (s == NULL)
		ft_strlcpy(s, "(null)", 7);
	s_len = ft_min(info.precision, ft_strlen(s));
	if (info.flags.zero_padding)
		fill = '0';
	else
			fill = ' ';
	while (!info.flags.left_align && info.width-- > s_len)
		*len += ft_putchar(fill);
	i = 0;
	while (i < s_len)
		*len += ft_putchar(s[i++]);
	while (info.flags.left_align && info.width-- > s_len)
		*len += ft_putchar(fill);
}

void	printf_p(t_format info, void *ptr, int *len)
{
	unsigned char	*addr;
	char			*display;

	if (ptr == NULL)
	{
		display = (char *)malloc(sizeof(char) * 4);
		ft_strlcpy(display, "0x0", 4);
	}
	else
	{
		addr = (unsigned char *)ptr;
		display = ft_itoa_positive_hex((unsigned long)addr);
	}
	printf_s(info, display, len);
	free(display);
}

void	printf_percent(t_format info, int *len)
{
	char	fill;

	if (info.flags.left_align)
		*len += ft_putchar('%');
	if (info.flags.set_width)
	{
		if (info.flags.zero_padding)
			fill = '0';
		else
			fill = ' ';
		while (--info.width)
			*len += ft_putchar(fill);
	}
	if (!info.flags.left_align)
		*len += ft_putchar('%');	
}
