/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:25:49 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/05/16 09:22:24 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

size_t	ft_putstr(char *s)
{
	size_t	len;
	size_t	chars_printed;

	chars_printed = 0;
	len = ft_strlen(s);
	chars_printed += write(1, s, len);
	return (chars_printed);
}

size_t	allocate_size(unsigned int num)
{
	size_t		size;

	size = 1;
	while (num > 15)
	{
		size++;
		num /= 16;
	}
	return (size);
}

size_t	convert_to_hex(unsigned int num, const char arr[])
{
	size_t	chars_printed;
	size_t	index;
	size_t	size;
	int		bit_shifts;
	char	*temp;

	chars_printed = 0;
	index = 0;
	size = allocate_size(num);
	temp = (char *)malloc(sizeof(char) * (size + 1));
	if (temp == NULL)
		return (0);
	bit_shifts = (size - 1) * 4;
	while (bit_shifts >= 0)
	{
		temp[index++] = arr[(num >> bit_shifts) & 0xf];
		bit_shifts -= 4;
	}
	temp[index] = '\0';
	chars_printed += ft_putstr(temp);
	free(temp);
	return (chars_printed);
}
