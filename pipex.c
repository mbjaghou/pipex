/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:22:15 by mbjaghou          #+#    #+#             */
/*   Updated: 2022/01/19 18:49:41 by mbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_data	data;

	if (ac != 5)
	{
		ft_putstr_fd("error in the argument\n", 1);
		exit(1);
	}
	data.input = open(av[1], O_RDONLY, 0644);
	if (data.input < 0)
		perror("pipex");
	data.output = open(av[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (data.output < 0)
		perror("pipex");
	data.s1 = ft_split(av[2], ' ');
	data.s2 = ft_split(av[3], ' ');
	data.s1[0] = search_path(data.s1[0], env);
	if (data.s1[0] == NULL)
		ft_putstr_fd("command not found\n", 1);
	data.s2[0] = search_path(data.s2[0], env);
	ft_pipe(&data, env);
}
