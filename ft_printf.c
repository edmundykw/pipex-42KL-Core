/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:42:28 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/03/11 15:45:08 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	find_specifier(const char *str)
{
	const int	identifier[] = {'c', 's', 'p', 'd', 'i',
		'u', 'x', 'X', '%'};
	int			index;

	index = 8;
	while (index > -1)
	{
		if (identifier[index] == *(str + 1))
			return (index);
		index--;
	}
	return (-1);
}

static size_t	process_idenfifier(va_list args, int specifier)
{
	static size_t	(*f_converters[])(va_list args) = {&ft_print_c, &ft_print_s,
		&ft_print_p, &ft_print_d, &ft_print_d, &ft_print_u,
		&ft_print_x_lower, &ft_print_x_upper};
	size_t			chars_printed;

	chars_printed = 0;
	if (specifier == 8)
		chars_printed += write(1, "%", 1);
	else
		chars_printed += f_converters[specifier](args);
	return (chars_printed);
}

size_t	ft_printf(const char *str, ...)
{
	va_list			args;
	size_t			chars_printed;
	size_t			index;
	int				specifier;

	chars_printed = 0;
	index = 0;
	va_start(args, str);
	while (str[index] != '\0')
	{
		specifier = find_specifier(&str[index]);
		if (str[index] == '%' && specifier != -1)
		{
			chars_printed += process_idenfifier(args, specifier);
			index++;
		}
		else
			chars_printed += write(1, &str[index], 1);
		index++;
	}
	va_end(args);
	return (chars_printed);
}
