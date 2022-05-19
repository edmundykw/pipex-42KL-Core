/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:09:52 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/05/19 15:03:12 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	create_child(char **argv, char **envp, int fd[2], int fd_rw[2])
{
	char	**process_path;
	char	**split_cmd;
	char	*args_path;

	process_path = create_path(envp);
	split_cmd = ft_split(*argv, ' ');
	args_path = create_cmd_path(process_path, split_cmd[0]);
	if (args_path == NULL)
		free_command_path(process_path, split_cmd);
	dup2(fd_rw[0], STDIN_FILENO);
	if (*(argv + 2) == NULL)
		dup2(fd_rw[1], STDOUT_FILENO);
	else
		dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	if (execve(args_path, split_cmd, envp) == -1)
	{
		free(args_path);
		perror("Error");
		free_command_path(process_path, split_cmd);
	}
}

void	ft_pipex(char **argv, char **envp, int fd_rw[2])
{
	pid_t	pid;
	int		status;
	int		fd[2];
	char	**ptr;

	ptr = argv + 2;
	while (*(ptr + 1) != NULL)
	{
		pipe(fd);
		pid = fork();
		if (pid == -1)
			perror("Error");
		else if (pid == 0)
			create_child(ptr, envp, fd, fd_rw);
		close(fd[1]);
		waitpid(pid, &status, 0);
		if (!WIFEXITED(status))
			exit(EXIT_FAILURE);
		fd_rw[0] = fd[0];
		ptr++;
	}
}

int	main(int args, char **argv, char **envp)
{
	int		fd_rw[2];

	if (args < 5)
	{
		write(1, "Invalid number of arguments.\n", 30);
		exit(EXIT_FAILURE);
	}
	fd_rw[0] = check_file_status(argv[1], 0);
	fd_rw[1] = check_file_status(argv[args - 1], 1);
	ft_pipex(argv, envp, fd_rw);
	close(fd_rw[0]);
	close(fd_rw[1]);
	exit(EXIT_SUCCESS);
}
