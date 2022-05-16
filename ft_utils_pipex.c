/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_pipex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 14:12:02 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/05/16 08:55:13 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	check_file_status(char *file, int i)
{
	int	fd;

	if (i == 0)
		fd = open(file, O_RDONLY);
	else if (i == 1)
	{
		fd = open(file, O_WRONLY | O_CREAT
				| O_TRUNC, 00700);
	}
	if (fd == -1)
	{
		ft_printf("bash: ");
		if (i == 0)
			ft_printf("%s: %s\n", file, strerror(errno));
		else
			ft_printf("%s: %s\n", file, strerror(errno));
		return (-1);
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

void	create_child(char **argv, char **envp, int fd[2], int fd_rw[2])
{
	char	**process_path;
	char	**split_cmd;
	char	*args_path;

	process_path = create_path(envp);
	split_cmd = ft_split(*argv, ' ');
	args_path = create_cmd_path(process_path, split_cmd[0]);
	if (args_path == NULL)
		exit(EXIT_FAILURE);
	dup2(fd_rw[0], STDIN_FILENO);
	if (*(argv + 2) == NULL)
		dup2(fd_rw[1], STDOUT_FILENO);
	else
		dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	execve(args_path, split_cmd, envp);
	free_mem(split_cmd);
	free_mem(process_path);
	free(args_path);
	perror("Error");
	exit(EXIT_FAILURE);
}
