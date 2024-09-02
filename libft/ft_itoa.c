/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:15:42 by mshabano          #+#    #+#             */
/*   Updated: 2024/04/30 18:46:45 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*count_n_alloc(long long int n, unsigned int *count)
{
	int		sign;
	char	*p_str;

	sign = 0;
	if (n < 0)
	{
		n *= -1;
		sign++;
	}
	if (n == 0)
		(*count)++;
	while (n)
	{
		(*count)++;
		n /= 10;
	}
	*count += sign;
	p_str = (char *)malloc ((*count + 1) * sizeof(char));
	if (p_str == NULL)
		return (NULL);
	if (sign)
		p_str[0] = '-';
	p_str[(*count)--] = '\0';
	return (p_str);
}

char	*ft_itoa(int n)
{
	long long int	copy;
	char			*str;
	unsigned int	count;

	copy = n;
	count = 0;
	str = count_n_alloc(copy, &count);
	if (str == NULL)
		return (NULL);
	if (n < 0)
		copy *= -1;
	if (copy == 0)
		str[0] = '0';
	while (copy)
	{
		str[count--] = copy % 10 + '0';
		copy /= 10;
	}
	return (str);
}
