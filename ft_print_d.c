/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:41:51 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/03/09 19:38:03 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_d(va_list args)
{
	int		num;
	size_t	chars_printed;
	char	*str;

	num = va_arg(args, int);
	chars_printed = 0;
	str = ft_itoa(num);
	chars_printed += ft_putstr(str);
	free(str);
	return (chars_printed);
}
