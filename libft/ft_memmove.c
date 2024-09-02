/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:30:13 by mshabano          #+#    #+#             */
/*   Updated: 2024/04/25 15:49:27 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	void	*dst_p;

	dst_p = dst;
	if ((!dst && !src) || (dst == src))
		return (dst);
	if (dst > src)
	{
		while (n-- > 0)
			((unsigned char *)dst)[n] = ((unsigned char *)src)[n];
	}
	else
	{
		while (n-- > 0)
			*(unsigned char *)dst++ = *(unsigned char *)src++;
	}
	return (dst_p);
}
