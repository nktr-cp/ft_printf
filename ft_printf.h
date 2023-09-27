/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:29:28 by knishiok          #+#    #+#             */
/*   Updated: 2023/09/27 19:28:56 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>
# include <limits.h>
// debug
# include <stdio.h>

# define LOWER_HEX "0123456789abcdef"
# define UPPER_HEX "0123456789ABCDEF"
# define SPECIFIER "cspdiuxX%"

typedef struct s_flags
{
	// '-'
	bool	left_align;
	// '0'
	bool	zero_padding;
	// '+'
	bool	sign;
	// '#'
	bool	sharp;
	// '.'
	bool	period;
	// ' '
	bool	space;
	// 'number'
	bool	set_width;
}	t_flags;

typedef struct s_format
{
	t_flags	flags;
	int		width;
	int		precision;
	char	specifier;
}	t_format;

void		printf_c(t_format info, int c, int *len);
void		printf_s(t_format info, char *s, int *len);
void		printf_d_i(t_format info, int n, int *len);
void		printf_u(t_format info, unsigned int n, int *len);
void		printf_x(t_format info, unsigned int n, int is_large, int *len);
void		printf_p(t_format info, void *ptr, int *len);
void		printf_percent(t_format info, int *len);
int			ft_strlen(const char *s);
int			ft_putchar(char c);
int			ft_printf(const char *s, ...);
int			ft_atoi(const char **str);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *src);
int			ft_min(int a, int b);
int			digit_count(unsigned long value, int base_size)
char		*ft_itoa_decimal(int value);
char		*ft_itoa_positive_hex(unsigned long value);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
t_format	parse_flags(const char **s);

#endif