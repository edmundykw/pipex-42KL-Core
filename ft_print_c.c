/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 19:24:25 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/03/08 19:25:55 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_c(va_list args)
{
	size_t	chars_printed;
	char	c;

	chars_printed = 0;
	c = va_arg(args, int);
	chars_printed += write(1, &c, 1);
	return (chars_printed);
}
