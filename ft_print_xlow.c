/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xlow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:41:43 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/03/11 17:44:24 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_x_lower(va_list args)
{
	const char	arr[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
		'a', 'b', 'c', 'd', 'e', 'f'};
	int			num;
	size_t		chars_printed;

	num = va_arg(args, int);
	chars_printed = 0;
	chars_printed += convert_to_hex((unsigned int) num, arr);
	return (chars_printed);
}
