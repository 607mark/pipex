/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:18:19 by mshabano          #+#    #+#             */
/*   Updated: 2024/08/17 16:28:30 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft.h"
# define HEX_UPP "0123456789ABCDEF"
# define HEX_LOW "0123456789abcdef"

# include <unistd.h>
# include <stdarg.h>

void	print_format(const char **specifier, va_list args, int *printed);
char	*pr_strchr(const char *s, int c);
int		pr_strlen(const char *s);
int		put_str(const char *s, int len, int *printed);
int		put_ptr(unsigned long ptr);
int		put_hex(long long n, char c);
int		put_int(long long n);
int		ft_printf(const char *s, ...);
#endif
