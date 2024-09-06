/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:03:50 by mshabano          #+#    #+#             */
/*   Updated: 2024/09/06 21:42:35 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int fd_is_open(int fd)
{
	if (fd == -1)
		return (0);
	return (!(write(fd, 0, 0) == -1 && errno == EBADF));
}

char *fetch_cmd_path(char *cmd, t_pipex *p)
{
	t_exec_cmd c;

	p->i = 0;
	while (p->path[p->i] != NULL)
	{
		c.path_part = ft_strjoin(p->path[p->i], "/");
		c.executable = ft_strjoin(c.path_part, cmd);
		if (c.path_part && c.executable)
		{
			free(c.path_part);
			if(!access(c.executable, F_OK | X_OK))
				return(c.executable);
			free(c.executable);
			p->i++;
		}
		else
			exit_error("ft_strjoin():malloc failed", 0, p);
	}
	return(NULL);
}

void execute_cmd(char *cmd, t_pipex *p)
{
	char **cmd_split;
	char *cmd_path;

	cmd_split = NULL;
	cmd_path = NULL;
	cmd_split = ft_split(cmd, ' ');
	if (cmd_split == NULL)
		exit_error("ft_split()", 0, p);
	cmd_path = fetch_cmd_path(cmd_split[0], p);
	if (execve(cmd_path, cmd_split, p->env) == -1)
	{
		free_arr(cmd_split);
		free(cmd_split);
		free(cmd_path);
		exit_error(cmd, 1, p);
	}
}

void	pipex_getenv_path(t_pipex *p)
{
	p->i = 0;
	if (p->env == NULL)
		exit_error("environment variables not found", 0, p);
	while(p->env[p->i] != NULL)
	{
		if (!ft_strncmp("PATH=", p->env[p->i], 5))
		{
			p->path = ft_split(p->env[p->i] + 5, ':');
			if (!p->path)
				exit_error("memory allocation failure", 0, p);
			break;
		}
		(p->i)++;
	}
}
