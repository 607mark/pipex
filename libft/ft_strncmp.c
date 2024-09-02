/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:59:57 by mshabano          #+#    #+#             */
/*   Updated: 2024/04/25 16:35:37 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	if (*s1 == '\0' && *s2 == '\0')
		return (0);
	while (*(char *)s1++ == *(char *)s2++ && --n && (*s1 || *s2))
		;
	s1--;
	s2--;
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
