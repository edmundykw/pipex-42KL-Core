/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:43:01 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/05/13 21:18:44 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>

size_t	ft_printf(const char *str, ...);
size_t	ft_print_c(va_list args);
size_t	ft_print_s(va_list args);
size_t	ft_print_x_lower(va_list args);
size_t	ft_print_x_upper(va_list args);
size_t	ft_print_p(va_list args);
size_t	ft_print_d(va_list args);
size_t	ft_print_u(va_list args);
size_t	allocate_size(unsigned int num);
size_t	convert_to_hex(unsigned int num, const char arr[]);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_putstr(char *s);
#endif