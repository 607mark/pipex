/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:33:12 by mshabano          #+#    #+#             */
/*   Updated: 2024/08/22 15:00:54 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
void	gnl_bzero(void *s, size_t n);
size_t	gnl_strlen(const char *s);
char	*find_nl(char *s);
char	*join_gnl(char *s1, char *s2, int len);
void	copy_mem(char *dst, char *src, size_t n);
#endif
