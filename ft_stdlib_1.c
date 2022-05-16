/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:48:33 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/05/16 09:22:16 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	h;
	size_t	i;

	h = 0;
	if (*(char *) little == '\0')
		return ((char *) big);
	if ((int) len < 0)
		len = ft_strlen(big);
	while (*(big + h) != '\0' && big + h <= big + len - 1)
	{
		i = 0;
		if (*(big + h) == *(little + i))
		{
			while (*(little + i) != '\0')
			{
				if (*(big + h + i) == *(little + i)
					&& big + h + i <= big + len - 1)
					if (i + 1 == ft_strlen(little))
						return ((char *)(big + h));
				i++;
			}
		}
		h++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*ptr;
	unsigned int	len;
	unsigned int	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (ptr == NULL)
		return (NULL);
	while (*s1 != '\0')
		ptr[i++] = *s1++;
	while (*s2 != '\0')
		ptr[i++] = *s2++;
	*(ptr + len) = '\0';
	return (ptr);
}

static unsigned int	count(int n)
{
	unsigned int	len;
	long			num;

	num = n;
	len = 0;
	if (num < 0)
	{
		num *= -1;
		len++;
	}
	while (!(num >= 0 && num <= 9))
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*ptr;
	long			num;
	unsigned int	len;

	num = (long) n;
	len = count(num) + 1;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	ptr[len] = '\0';
	if (num == 0)
		ptr[0] = '0';
	if (n < 0)
	{
		num *= -1;
		ptr[0] = '-';
	}
	while (num > 0)
	{
		ptr[--len] = '0' + (num % 10);
		num /= 10;
	}
	return (ptr);
}
