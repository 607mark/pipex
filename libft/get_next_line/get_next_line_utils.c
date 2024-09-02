/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:05:36 by mshabano          #+#    #+#             */
/*   Updated: 2024/08/22 14:59:26 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	copy_mem(char *dst, char *src, size_t n)
{
	while (n--)
		*(dst++) = *(src++);
}

char	*join_gnl(char *s1, char *s2, int len)
{
	char	*p;
	size_t	len_s1;

	if (!s1)
		len_s1 = 0;
	else
		len_s1 = gnl_strlen(s1);
	p = (char *) malloc((len_s1 + len + 1) * sizeof (char));
	if (!p)
	{
		if (s1)
			free (s1);
		return (NULL);
	}
	copy_mem(p, s1, len_s1);
	copy_mem(p + len_s1, s2, len);
	*(p + len_s1 + len) = '\0';
	if (s1)
		free(s1);
	return (p);
}

size_t	gnl_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*find_nl(char *s)
{
	while (*s)
	{
		if (*s == '\n')
			return (s);
		s++;
	}
	return (NULL);
}

void	gnl_bzero(void *s, size_t n)
{
	char	*temp_s;

	temp_s = (char *)s;
	while (n > 0)
	{
		*(temp_s++) = 0;
		n--;
	}
}
