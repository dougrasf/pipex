/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:11:01 by dofranci          #+#    #+#             */
/*   Updated: 2022/11/25 16:56:13 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	fork_function1(t_data *data, char *argv[], char *envp[])
{
	if (command(argv[2], envp, data) == -1)
	{
		ft_printf("Command 1 not found\n");
		return (1);
	}
	data->pid = fork();
	if (error(data->pid, 1))
		return (3);
	if (data->pid == 0)
	{
		dup2(data->fd, STDIN_FILENO);
		dup2(data->pipefd[1], STDOUT_FILENO);
		close(data->pipefd[0]);
		close(data->pipefd[1]);
		if (execute(envp, data) == 1)
		{
			freematriz(data->matrizpath);
			freematriz(data->cmd);
			return (2);
		}
	}
	freematriz(data->matrizpath);
	freematriz(data->cmd);
	return (0);
}

int	fork_function2(t_data *data, char *argv[], char *envp[])
{
	if (command(argv[3], envp, data) == -1)
	{
		ft_printf("Command 2 not found\n");
		return (1);
	}
	data->pid = fork();
	if (error(data->pid, 1))
		return (3);
	if (data->pid == 0)
	{
		dup2(data->pipefd[0], STDIN_FILENO);
		dup2(data->fd, STDOUT_FILENO);
		close(data->pipefd[0]);
		close(data->pipefd[1]);
		if (execute(envp, data) == 1)
			return (2);
	}
	return (0);
}
