/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:58:56 by mshabano          #+#    #+#             */
/*   Updated: 2024/05/05 17:39:34 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	sub_s = (char *)ft_calloc ((len + 1), sizeof(char));
	if (!sub_s)
		return (NULL);
	if (len == 0)
	{
		sub_s[0] = '\0';
		return (sub_s);
	}
	ft_memcpy(sub_s, s + start, len);
	sub_s[len] = '\0';
	return (sub_s);
}
