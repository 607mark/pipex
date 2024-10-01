/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 23:55:23 by mshabano          #+#    #+#             */
/*   Updated: 2024/10/01 14:07:45 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_error(char *s, int n, t_pipex *p)
{
	if (n == 1)
		ft_printf("-pipex: %s: %s\n", s, strerror(errno));
	else if (n == 0)
		ft_printf("-pipex: %s\n", s);
	if (p->path)
	{
		free_arr(p->path);
		free(p->path);
	}
	fd_close(&p->infile_fd);
	fd_close(&p->infile_fd);
	fd_close(&p->pipe_fd[0]);
	fd_close(&p->pipe_fd[1]);
	exit(1);
}

void	parent_process(t_pipex *p)
{
	fd_close(&p->pipe_fd[1]);
	if (dup2(p->outfile_fd, 1) == -1)
		exit_error("dup2()", 1, p);
	if (dup2(p->pipe_fd[0], 0) == -1)
		exit_error("dup2()", 1, p);
	fd_close(&p->outfile_fd);
	execute_cmd(p->cmd2, p);
}

void	child_process(t_pipex *p)
{
	p->infile_fd = open(p->infile_name, O_RDWR);
	if (p->infile_fd < 0)
		exit_error(p->infile_name, 1, p);
	fd_close(&p->pipe_fd[0]);
	if (dup2(p->infile_fd, 0) == -1)
		exit_error("dup2()", 1, p);
	if (dup2(p->pipe_fd[1], 1) == -1)
		exit_error("dup2()", 1, p);
	fd_close(&p->infile_fd);
	execute_cmd(p->cmd1, p);
}

void	pipex_init(t_pipex *p, char **av, char **env)
{
	if (pipe(p->pipe_fd) == -1)
		exit_error("pipe()", 1, p);
	p->env = env;
	p->infile_name = av[1];
	p->cmd1 = av[2];
	p->cmd2 = av[3];
	p->outfile_name = av[4];
	p->infile_fd = -1;
	p->outfile_fd = -1;
	getenv_path(p);
	if (p->path == NULL)
		exit_error("PATH not found", 0, p);
	p->outfile_fd = open(p->outfile_name, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (p->outfile_fd == -1)
		exit_error(p->outfile_name, 1, p);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	p;
	pid_t	pid;

	ft_bzero(&p, sizeof(p));
	if (ac != 5)
		exit_error("wrong number of arguments", 0, &p);
	pipex_init(&p, av, env);
	pid = fork();
	if (pid < 0)
		exit_error("fork()", 1, &p);
	else if (pid == 0)
		child_process(&p);
	else
		parent_process(&p);
}
