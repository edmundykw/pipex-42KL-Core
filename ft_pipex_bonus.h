/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:11:56 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/05/15 16:13:35 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_BONUS_H
# define FT_PIPEX_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include "ft_printf_mod/ft_printf.h"

int		check_file_status(char *file, int i);
char	**create_path(char **envp);
char	*create_cmd_path(char **process_path, char *cmd);
void	free_mem(char **pointer);
void	create_child(char **argv, char **envp, int fd[2], int fd_rw[2]);
void	ft_pipex(char **argv, char **envp, int fd_rw[2]);

#endif