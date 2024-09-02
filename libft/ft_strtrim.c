/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:19:01 by mshabano          #+#    #+#             */
/*   Updated: 2024/04/27 15:59:22 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	checker(const char *s1, const char *set)
{
	while (*set != '\0')
	{
		if (*s1 == *set)
			return (1);
		else
			set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*new_str;

	if (!s1)
		return (NULL);
	if (*s1 == '\0')
	{
		new_str = ft_substr(s1, 0, 1);
		return (new_str);
	}
	start = 0;
	end = ft_strlen(s1) - 1;
	while (checker((s1 + start), set))
		start++;
	while (checker((s1 + end), set))
		end--;
	end++;
	new_str = ft_substr(s1, start, end - start);
	return (new_str);
}
