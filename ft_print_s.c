/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:47:13 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/03/11 12:34:38 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_s(va_list args)
{
	char	*str;
	size_t	chars_to_print;

	str = va_arg(args, char *);
	chars_to_print = 0;
	if (str == NULL)
		chars_to_print += write(1, "(null)", 6);
	else
	{
		chars_to_print = ft_strlen(str);
		write(1, str, chars_to_print);
	}
	return (chars_to_print);
}
