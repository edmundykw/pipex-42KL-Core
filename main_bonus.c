/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:09:52 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/05/16 09:22:28 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_pipex(char **argv, char **envp, int fd_rw[2])
{
	pid_t	pid;
	int		i;
	int		status;
	int		fd[2];
	char	**ptr;

	i = 2;
	ptr = argv + 2;
	while (*(argv + i + 1) != NULL)
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
			break ;
		fd_rw[0] = fd[0];
		i++;
		ptr++;
	}
}

int	main(int args, char **argv, char **envp)
{
	int		fd_rw[2];

	if (args < 5)
	{
		ft_printf("Invalid number of arguments.\n");
		exit(EXIT_FAILURE);
	}
	fd_rw[0] = check_file_status(argv[1], 0);
	if (fd_rw[0] == -1)
		exit(EXIT_FAILURE);
	fd_rw[1] = check_file_status(argv[args - 1], 1);
	if (fd_rw[1] == -1)
		exit(EXIT_FAILURE);
	ft_pipex(argv, envp, fd_rw);
	close(fd_rw[0]);
	close(fd_rw[1]);
}
