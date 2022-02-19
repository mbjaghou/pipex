/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:18:44 by mbjaghou          #+#    #+#             */
/*   Updated: 2022/01/18 23:14:22 by mbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_pipe(t_data *data, char **env)
{
	if (pipe(data->fd) == -1)
		return (ft_putstr_fd("error whith opening the pipe", 1), exit(1), 0);
	data->pid = fork();
	if (data->pid < 0)
		perror("Fork");
	if (data->pid == 0)
	{
		dup2(data->fd[1], 1);
		dup2(data->input, 0);
		close(data->fd[0]);
		close(data->fd[1]);
		if (data->input > 0)
			execve(data->s1[0], data->s1, env);
	}
	else
	{
		dup2(data->fd[0], 0);
		dup2(data->output, 1);
		close(data->fd[0]);
		close(data->fd[1]);
		execve(data->s2[0], data->s2, env);
	}
	close(data->input);
	return (close(data->output), waitpid(data->pid, NULL, 0), 0);
}
