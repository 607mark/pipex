/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:03:30 by mshabano          #+#    #+#             */
/*   Updated: 2024/04/18 15:15:02 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	s;

	s = 0;
	while (src[s])
		s++;
	if (!dstsize)
		return (s);
	while (dstsize > 1 && *src != '\0')
	{
		*(dst++) = *(src++);
		dstsize--;
	}
	*dst = '\0';
	return (s);
}
