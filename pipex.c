/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 23:55:23 by mshabano          #+#    #+#             */
/*   Updated: 2024/09/05 23:42:50 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void exit_error(char *s, int n, t_pipex *p)
{
	if (n)
		ft_printf("-pipex: %s: %s\n", s, strerror(errno));
	else
		ft_printf("-pipex: %s\n", s);
	if(p->path)
	{	
		free_arr(p->path);
		free(p->path);
	}
	if (fd_is_open(p->infile_fd))
		close(p->infile_fd);
	if (fd_is_open(p->outfile_fd))
		close(p->outfile_fd);
	exit(1);
}

void parent_process(t_pipex *p)
{
	p->outfile_fd = open(p->outfile_name, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (p->outfile_fd == -1)
		exit_error(p->outfile_name, 1, p);
	if(dup2(p->outfile_fd, 1) == -1)
		exit_error("dup2()", 1, p);
	if(dup2(p->pipe_fd[0], 0) == -1)
		exit_error("dup2()", 1, p);
	close(p->pipe_fd[1]);
	execute_cmd(p->cmd2, p);
}

void child_process(t_pipex *p)
{
	p->infile_fd = open(p->infile_name, O_RDWR);
	if (p->infile_fd < 0)
		exit_error(p->infile_name, 1, p);
	if(dup2(p->infile_fd, 0) == -1)
		exit_error("dup2()", 1, p);
	if(dup2(p->pipe_fd[1], 1) == -1)
		exit_error("dup2()", 1, p);
	close(p->pipe_fd[0]);
	execute_cmd(p->cmd1, p);
}

void pipex_init(t_pipex *p, char **av, char **env)
{
	ft_bzero(p, sizeof(p));
	if (pipe(p->pipe_fd) < 0)
		exit_error("pipe()", 1, p);
	p->env = env;
	p->infile_name = av[1];
	p->cmd1 = av[2];
	p->cmd2 = av[3];
	p->outfile_name = av[4];
	p->infile_fd = -1;
	p->outfile_fd = -1;
	pipex_getenv_path(p);
	if (p->path == NULL || p->path[0][0] == '\0')
		exit_error("PATH not found", 0, p);
}

int main(int ac, char **av, char **env)
{
	t_pipex	p;
	pid_t	pid;

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
