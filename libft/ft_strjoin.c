/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:18:48 by mshabano          #+#    #+#             */
/*   Updated: 2024/05/05 18:37:37 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1)
	{
		p = ft_strdup(s2);
		return (p);
	}
	if (!s2)
	{
		p = ft_strdup(s1);
		return (p);
	}
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	p = (char *) malloc((len_s1 + len_s2 + 1) * sizeof (char));
	if (!p)
		return (NULL);
	ft_memcpy(p, s1, len_s1);
	ft_memcpy(p + len_s1, s2, len_s2 + 1);
	return (p);
}
