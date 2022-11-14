/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:24:14 by dofranci          #+#    #+#             */
/*   Updated: 2022/11/14 14:16:22 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

# include <unistd.h>
# include "../libft/include/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>

typedef struct s_data
{
	int	fd;
	int	pipefd[2];
	int	pid;
} t_data;

int		fd_error(int value);
int		argc_error(int argc);
int		pipe_error(int value);
int		fork_error(int value);
int		open_error(int value);
int		fork_function1(t_data *data, char *argv[], char *envp[]);
int		fork_function2(t_data *data, char *argv[], char *envp[]);
void	execute(char *argv, char *envp[]);

#endif