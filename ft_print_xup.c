/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:27:36 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/03/11 11:55:11 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_x_upper(va_list args)
{
	const char	arr[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
		'A', 'B', 'C', 'D', 'E', 'F'};
	int			num;
	size_t		chars_printed;

	num = va_arg(args, int);
	chars_printed = 0;
	chars_printed += convert_to_hex((unsigned int) num, arr);
	return (chars_printed);
}
