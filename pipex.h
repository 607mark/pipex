/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:42:38 by mshabano          #+#    #+#             */
/*   Updated: 2024/09/06 18:33:58 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include "libft/libft.h"
# include <sys/wait.h>
# include <sys/types.h>
# include <errno.h>
# include <string.h>

typedef struct s_exec_cmd
{
	char *path_part;
	char *executable;
} t_exec_cmd;

typedef struct s_pipex
{
	char	**av;
	char	**env;
	char	**path;
	int		pipe_fd[2];
	int		infile_fd;
	int		outfile_fd;
	char	*cmd1;
	char	*cmd2;
	char	*infile_name;
	char	*outfile_name;
	int		status;
	int		i;
} t_pipex;		

void exit_error(char *s, int n, t_pipex *p);
int fd_is_open(int fd);
void execute_cmd(char *cmd, t_pipex *p);
void    pipex_getenv_path(t_pipex *p);

# endif
