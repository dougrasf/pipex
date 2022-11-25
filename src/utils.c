/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:39:44 by dofranci          #+#    #+#             */
/*   Updated: 2022/11/25 17:11:24 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*findpath(char *envp[])
{
	int	i;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH=", 5))
		i++;
	return (envp[i] + 5);
}

void	freematriz(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	argc_error(int argc)
{
	if (argc != 5)
	{
		ft_printf("Arguments error\n");
		return (1);
	}
	else
		return (0);
}

int	error(int value, int test)
{
	if (value == -1)
	{
		if (test == 1)
		{
			ft_printf("Fork error\n");
			return (3);
		}
		if (test == 2)
		{
			ft_printf("FD error\n");
			return (4);
		}
		if (test == 3)
		{
			ft_printf("Pipe error\n");
			return (2);
		}
	}
	return (0);
}
