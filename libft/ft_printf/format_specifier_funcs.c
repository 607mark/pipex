/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_specifier_funcs.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:48:56 by mshabano          #+#    #+#             */
/*   Updated: 2024/06/20 18:19:17 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_ptr(unsigned long ptr)
{
	int	ret_value;
	int	tmp;

	ret_value = 0;
	tmp = 0;
	if (!ptr)
		return ((write(1, "(nil)", 5)));
	if (write(1, "0x", 2) == -1)
		return (-1);
	if (ptr > 15)
	{
		tmp = put_hex(ptr / 16, 'x');
		if (tmp == -1)
			return (-1);
	}
	ret_value += tmp + 2;
	if (write(1, &HEX_LOW[ptr % 16], 1) == -1)
		return (-1);
	ret_value++;
	return (ret_value);
}

int	put_hex(long long num, char c)
{
	int		i;
	int		ret_value;
	int		tmp;
	char	hex_num[16];

	tmp = 0;
	ret_value = 0;
	i = 15;
	if (num == 0)
		return (write (1, "0", 1));
	while (num > 0)
	{
		if (c == 'x')
			hex_num[i--] = HEX_LOW[num % 16];
		else if (c == 'X')
			hex_num[i--] = HEX_UPP[num % 16];
		num /= 16;
	}
	tmp = write(1, &hex_num[i + 1], 15 - i);
	if (tmp == -1)
		return (-1);
	return (ret_value + tmp);
}

int	put_int(long long n)
{
	char	dec_num[19];
	int		i;
	int		ret_value;

	ret_value = 0;
	i = 18;
	if (n == 0)
		return (write(1, "0", 1));
	if (n < 0)
	{
		if (write (1, "-", 1) == -1)
			return (-1);
		n = -n;
		ret_value++;
	}
	while (n > 0)
	{
		dec_num[i--] = HEX_LOW[n % 10];
		n /= 10;
	}
	if (write(1, &dec_num[i + 1], 18 - i) == -1)
		return (-1);
	return (ret_value + 18 - i);
}
