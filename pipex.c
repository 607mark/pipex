/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 23:55:23 by mshabano          #+#    #+#             */
/*   Updated: 2024/09/02 17:48:10 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int ac, char **av, char **env)
{
	int	pipe_fd[2];
	pid_t	ch_1;
	pid_t	ch_2;

	if (av != 5)
		exit(1);
	if (pipe(pipe_fd) < 0)
		exit(1)
}
