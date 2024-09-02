/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:01:36 by mshabano          #+#    #+#             */
/*   Updated: 2024/04/27 16:54:03 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	space_check(const char *str)
{
	if (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int				sign;
	long long int	res;
	long long int	check;

	sign = 1;
	res = 0;
	if (*str == '\0')
		return (0);
	while (space_check(str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*(str++) == '-')
			sign = -1;
	}
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		check = res;
		res = res * 10 + (sign *(*(str++) - '0'));
		if (res > check && sign == -1)
			return (0);
		if (res < check && sign == 1)
			return (-1);
	}
	return (res);
}
