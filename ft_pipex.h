/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:11:56 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/05/19 15:25:55 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>

size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_putstr(char *s);
int		check_file_status(char *file, int i);
char	**create_path(char **envp);
char	*create_cmd_path(char **process_path, char *cmd);
void	free_mem(char **pointer);
void	free_command_path(char **ptr1, char **ptr2);
void	create_child(char **argv, char **envp, int fd[2], int fd_rw[2]);
void	ft_pipex(char **argv, char **envp, int fd_rw[2]);
#endif