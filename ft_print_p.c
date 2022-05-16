/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:13:10 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/03/11 21:20:51 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* The function below is identical to the one used in printing hex. 
But I duplicated it here because I am using a different data type here
versus what I used in hex (unsigned int vs uintptr_t respectively) to ensure 
portability.
*/
static size_t	allocate_size_p(uintptr_t num)
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

static size_t	convert_pointer(uintptr_t num, const char arr[])
{
	size_t	chars_printed;
	size_t	index;
	size_t	size;
	int		bit_shifts;
	char	*temp;

	chars_printed = 0;
	index = 0;
	size = allocate_size_p(num);
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

size_t	ft_print_p(va_list args)
{
	const char	arr[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
		'a', 'b', 'c', 'd', 'e', 'f'};
	void		*temp;
	size_t		chars_printed;
	uintptr_t	casted_pointer;

	temp = va_arg(args, void *);
	casted_pointer = (uintptr_t) temp;
	chars_printed = 0;
	if (casted_pointer == 0)
		chars_printed += write(1, "0x0", 3);
	else
	{
		chars_printed += write(1, "0x", 2);
		chars_printed += convert_pointer(casted_pointer, arr);
	}
	return (chars_printed);
}
