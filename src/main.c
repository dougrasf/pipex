/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: dofranci <dofranci@student.42sp.org.br>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/11/08 20:26:35 by dofranci		  #+#	#+#			 */
/*   Updated: 2022/11/14 13:57:08 by dofranci		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "pipex.h"

static char *findpath(char *envp[])
{
	int i;

	i = 0;
	while(!ft_strnstr(envp[i], "PATH=", 5))
		i++;
	return(envp[i]);
}

void execute(char *argv, char *envp[])
{
	char **cmd;
	char **matrizpath;
	int i;

	i = 0;
	matrizpath = ft_split(findpath(envp), ':');
	cmd = ft_split(argv, ' ');
	while(matrizpath[i])
	{
		matrizpath[i] = ft_strjoin(ft_strjoin(matrizpath[i], "/"), cmd[0]);
		execve(matrizpath[i], cmd, envp);
		i++;
	}
}

int main(int argc, char *argv[], char *envp[])
{
	t_data data;

	if(argc_error(argc))
		return(1);
	if(pipe_error(pipe(data.pipefd)))
		return(2);
	data.fd = open(argv[1], O_RDONLY);
	if(open_error(data.fd))
		return(3);
	fork_function1(&data, argv, envp);
	close(data.fd);
	data.fd = open(argv[4], O_WRONLY | O_RDONLY);
	if(open_error(data.fd))
		return(3);
	fork_function2(&data, argv, envp);
	close(data.fd);
	waitpid(-1, NULL, 0);
	return(0);
}
