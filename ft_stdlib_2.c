/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 13:54:08 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/05/16 09:22:18 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*ptr;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		ptr = (char *)malloc(sizeof(char));
		*ptr = '\0';
		return (ptr);
	}
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (len-- > 0 && *(s + start) != '\0')
	{
		*(ptr + i) = *(char *)(s + start);
		start++;
		i++;
	}
	*(ptr + i) = '\0';
	return (ptr);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	unsigned long	i;
	unsigned int	j;

	i = nmemb * size;
	j = 0;
	if (i > __LONG_MAX__)
		return (NULL);
	ptr = (char *) malloc(i);
	if (ptr == NULL)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (ptr);
	while (j != i)
	{
		*(char *)(ptr + j) = 0;
		j++;
	}
	return (ptr);
}

static unsigned int	word_count(char *s, char c)
{
	char			*ptr;
	unsigned int	count;

	count = 0;
	ptr = s;
	while (*ptr != '\0')
	{
		while (*ptr == c && *ptr != '\0')
			ptr++;
		if (*ptr != c && *ptr != '\0')
			count++;
		while (*ptr != c && *ptr != '\0')
			ptr++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	i;
	unsigned int	start;
	unsigned int	k;
	char			**ptr;

	if (s == NULL)
		return (NULL);
	ptr = (char **)ft_calloc(word_count((char *) s, c) + 1, sizeof(ptr));
	if (ptr == NULL)
		return (NULL);
	k = 0;
	i = 0;
	while (*(s + i) != '\0')
	{
		start = i;
		while (*(s + i) != c && *(s + i) != '\0')
			i++;
		if (start < i)
			ptr[k++] = ft_substr(s + start, 0, i - start);
		if (*(s + i) != '\0')
			i++;
	}
	*(ptr + k) = NULL;
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	int			i;
	char		*temp;

	i = ft_strlen(s);
	temp = (char *) s;
	while (i + 1 != 0)
	{
		if (*temp == (char) c)
			return ((char *) temp);
		temp++;
		i--;
	}
	return (NULL);
}
