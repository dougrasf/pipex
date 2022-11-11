/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:26:35 by dofranci          #+#    #+#             */
/*   Updated: 2022/11/10 22:43:59 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *findpath(char *envp[])
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
    // ft_printf("%s\n", path);
    matrizpath = ft_split(findpath(envp), ':');
    //ft_printf("%s\n", argv[1]);
    cmd = ft_split(argv, ' ');
    while(matrizpath[i])
    {
        matrizpath[i] = ft_strjoin(ft_strjoin(matrizpath[i], "/"), cmd[0]);
        execve(matrizpath[i], cmd, envp);
        i++;
    }
}
//fd[0] = read
//fd[1] = write

int main(int argc, char *argv[], char *envp[])
{
    int fd;
    int pipefd[2];
    int pid;

    pipe(pipefd);
    pid = fork(); // error
    // if(argc != 5)
    //     return(0);
    fd = open(argv[1], O_RDONLY);
    if(pid == 0) // se pid < 0 = erro
    {
        dup2(fd,  STDIN_FILENO);
        dup2(pipefd[1], STDOUT_FILENO); // se -1 = erro
        close(pipefd[0]);
        close(pipefd[1]);
        execute(argv[2], envp);
    }
    close(fd);
    fd = open(argv[4], O_WRONLY | O_RDONLY); // error
    pid = fork(); // error
    if(pid == 0) // se pid < 0 = erro
    {
        dup2(pipefd[0], STDIN_FILENO);
        dup2(fd, STDOUT_FILENO);
        close(pipefd[0]);
        close(pipefd[1]);
        execute(argv[3], envp);
    }
    close(fd);
    waitpid(-1, NULL, 0);
    return(0);
}
