/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:39:44 by dofranci          #+#    #+#             */
/*   Updated: 2022/11/21 12:09:50 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int argc_error(int argc)
{
	if(argc != 5)
	{
		ft_printf("Arguments error\n");
		return(1);
	}
	else
		return(0);
}

int pipe_error(int value)
{
	if(value == -1)
	{
		ft_printf("Pipe error\n");
		return(2);
	}
	else
		return(0);
}

int fork_error(int value)
{
	if(value == -1)
	{
		ft_printf("Fork error\n");
		return(3);
	}
	else
		return(0);
}

int open_error(int value)
{
	if(value == -1)
	{
		ft_printf("FD error\n");
		return(4);
	}
	else
		return(0);
}
