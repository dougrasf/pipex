/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:39:19 by dofranci          #+#    #+#             */
/*   Updated: 2022/11/25 17:11:30 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	treat_arg(char *arg, char *envp[], t_data *data)
{
	int		i;
	char	*temp;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == ' ')
			arg[i] = -1;
		if (arg[i] == '\'')
		{
			i++;
			while (arg[i] != '\'')
				i++;
		}
		i++;
	}
	data->cmd = ft_split(arg, -1);
	temp = ft_strtrim(data->cmd[1], "'");
	free(data->cmd[1]);
	data->cmd[1] = temp;
	data->matrizpath = ft_split(findpath(envp), ':');
}

int	command(char *argv, char *envp[], t_data *data)
{
	char	*arg;
	int		i;

	i = 0;
	arg = ft_strdup(argv);
	treat_arg(arg, envp, data);
	while (data->matrizpath[i])
	{
		data->matrizpath[i] = ft_strjoin(ft_strjoin \
		(data->matrizpath[i], "/"), data->cmd[0]);
		if (access(data->matrizpath[i], X_OK) == 0)
		{
			free(arg);
			return (0);
		}
		i++;
	}
	freematriz(data->matrizpath);
	freematriz(data->cmd);
	free(arg);
	return (-1);
}

int	execute(char *envp[], t_data *data)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	while (data->matrizpath[i])
	{
		ret = execve(data->matrizpath[i], data->cmd, envp);
		i++;
	}
	if (ret == -1)
		return (1);
	return (0);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;
	int		rt;

	if (argc_error(argc))
		return (1);
	data.fd = open(argv[4], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (error(data.fd, 2))
		return (1);
	close(data.fd);
	if (error(pipe(data.pipefd), 3))
		return (2);
	data.fd = open(argv[1], O_RDONLY);
	if (error(data.fd, 2))
		return (1);
	rt = fork_function1(&data, argv, envp);
	if (rt == 2)
		return (1);
	close(data.fd);
	data.fd = open(argv[4], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (fork_function2(&data, argv, envp) == 1)
		return (127);
	freematriz(data.matrizpath);
	freematriz(data.cmd);
	waitpid(-1, NULL, 0);
	return (0);
}
