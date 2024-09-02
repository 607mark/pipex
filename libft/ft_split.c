/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 22:11:30 by mshabano          #+#    #+#             */
/*   Updated: 2024/04/28 22:20:06 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	n;

	if (!(*s))
		return (0);
	n = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			n++;
		while (*s != c && *s)
			s++;
	}
	return (n);
}

static void	free_arr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
}

static int	skip_define_len(char const **s, char c, size_t *w_len)
{
	while (**s == c && *s)
		(*s)++;
	if (!**s)
		return (0);
	if (!ft_strchr(*s, c))
		*w_len = ft_strlen(*s);
	else
		*w_len = ft_strchr(*s, c) - *s;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	w_len;
	size_t	i;

	if (!s)
		return (NULL);
	arr = (char **)ft_calloc((count_words(s, c) + 1), sizeof (char *));
	if (!arr)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (!(skip_define_len(&s, c, &w_len)))
			break ;
		arr[i] = ft_substr(s, 0, w_len);
		if (!*(arr + i++))
		{
			free_arr(arr);
			free(arr);
			return (NULL);
		}
		s += w_len;
	}
	arr[i] = NULL;
	return (arr);
}
