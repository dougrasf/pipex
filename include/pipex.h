/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:24:14 by dofranci          #+#    #+#             */
/*   Updated: 2022/11/25 17:10:28 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include "../libft/include/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>

typedef struct s_data
{
	int		fd;
	int		pipefd[2];
	int		pid;
	char	**cmd;
	char	**matrizpath;
}	t_data;

void	freematriz(char **split);
void	freematriz(char **matriz);
int		argc_error(int argc);
int		error(int value, int test);
int		fork_function1(t_data *data, char *argv[], char *envp[]);
int		fork_function2(t_data *data, char *argv[], char *envp[]);
int		command(char *argv, char *envp[], t_data *data);
int		execute(char *envp[], t_data *data);
char	*findpath(char *envp[]);

#endif
