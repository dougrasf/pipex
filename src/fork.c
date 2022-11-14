/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:11:01 by dofranci          #+#    #+#             */
/*   Updated: 2022/11/14 14:12:17 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int fork_function1(t_data *data, char *argv[], char *envp[])
{
	data->pid = fork();
	if(fork_error(data->pid))
		return(3);
	if(data->pid == 0)
	{
		dup2(data->fd,  STDIN_FILENO);
		dup2(data->pipefd[1], STDOUT_FILENO); // se -1 = erro
		close(data->pipefd[0]);
		close(data->pipefd[1]);
		execute(argv[2], envp);
	}
	return(0);
}

int fork_function2(t_data *data, char *argv[], char *envp[])
{
	data->pid = fork();
	if(fork_error(data->pid))
		return(3);
	if(data->pid == 0)
	{
		dup2(data->pipefd[0], STDIN_FILENO);
		dup2(data->fd, STDOUT_FILENO);
		close(data->pipefd[0]);
		close(data->pipefd[1]);
		execute(argv[3], envp);
	}
	return(0);
}