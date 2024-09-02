/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:46:22 by mshabano          #+#    #+#             */
/*   Updated: 2024/04/28 17:27:19 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long int	num;
	char			s[11];
	int				i;

	num = n;
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (n < 0)
	{
		num *= -1;
		ft_putchar_fd('-', fd);
	}
	s[10] = '\0';
	i = 9;
	while (num > 0)
	{
		s[i--] = (num % 10) + '0';
		num /= 10;
	}
	ft_putstr_fd(&s[0] + i + 1, fd);
}
