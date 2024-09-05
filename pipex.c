/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 23:55:23 by mshabano          #+#    #+#             */
/*   Updated: 2024/09/04 02:18:53 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void error_exit(str *s, int n)
{
	if (n)
		ft_printf("-pipex: %s: %s\n", s, strerror(errno));
	else
		ft_printf("-pipex: %s\n", s,);
	exit;
}

int main(int ac, char **av, char **env)
{
	int	pipe_fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (av != 5)
		error_exit();
	if (pipe(pipe_fd) < 0)
		error_exit();
	*/
	int i = 0;
	while(env[i] != NULL)
		ft_printf("%s\n", env[i++]);
}
