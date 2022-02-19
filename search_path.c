/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 13:22:12 by mbjaghou          #+#    #+#             */
/*   Updated: 2022/01/18 23:40:02 by mbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*search_path(char *str, char **env)
{
	int		i;
	char	*path;
	char	**allpath;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			path = ft_strdup(env[i] + 5);
		i++;
	}
	i = 0;
	allpath = ft_split(path, ':');
	free(path);
	while (allpath[i])
	{
		path = ft_strjoin(allpath[i], str);
		if (open(path, O_RDONLY, 0644) >= 0)
			return (path);
		i++;
	}
	free(allpath);
	return (NULL);
}
