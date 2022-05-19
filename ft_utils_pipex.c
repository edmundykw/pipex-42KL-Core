/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_pipex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 14:12:02 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/05/19 14:26:27 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	check_file_status(char *file, int i)
{
	int	fd;

	if (i == 0)
		fd = open(file, O_RDONLY);
	else
	{
		fd = open(file, O_WRONLY | O_CREAT
				| O_TRUNC, 00700);
	}
	if (fd == -1)
	{
		perror(file);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

char	**create_path(char **envp)
{
	size_t	i;
	char	*path;
	char	**process_path;

	i = 0;
	while (envp[i] != NULL)
	{
		path = ft_strnstr(envp[i], "PATH", 4);
		if (path != NULL)
			break ;
		i++;
	}
	process_path = ft_split(ft_strchr(path, '/'), ':');
	return (process_path);
}

char	*create_cmd_path(char **process_path, char *cmd)
{
	char	*args_suffix;
	char	*args;
	size_t	i;

	i = 0;
	while (process_path[i] != NULL)
	{
		if (process_path[i][ft_strlen(process_path[i]) - 1] == '/')
			args = ft_strjoin(process_path[i], cmd);
		else
		{
			args_suffix = ft_strjoin("/", cmd);
			args = ft_strjoin(process_path[i], args_suffix);
			free(args_suffix);
		}
		if (access(args, F_OK) == 0)
			return (args);
		i++;
		free(args);
	}
	perror("Command not found");
	return (NULL);
}

void	free_mem(char **pointer)
{
	size_t	i;

	i = 0;
	while (pointer[i] != NULL)
	{
		free(pointer[i]);
		i++;
	}
	free(pointer);
}

void	free_command_path(char **ptr1, char **ptr2)
{
	free_mem(ptr1);
	free(ptr2);
	exit(EXIT_FAILURE);
}
