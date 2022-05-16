/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:54:30 by ekeen-wy          #+#    #+#             */
/*   Updated: 2022/03/09 19:35:41 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	count(unsigned int n)
{
	unsigned int	len;

	len = 0;
	while (!(n <= 9))
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_itoa_u(unsigned int n)
{
	char			*ptr;
	unsigned int	len;

	len = count(n) + 1;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	ptr[len] = '\0';
	if (n == 0)
		ptr[0] = '0';
	while (n > 0)
	{
		ptr[--len] = '0' + (n % 10);
		n /= 10;
	}
	return (ptr);
}

size_t	ft_print_u(va_list args)
{
	unsigned int	num;
	size_t			chars_printed;
	char			*str;

	num = va_arg(args, unsigned int);
	chars_printed = 0;
	str = ft_itoa_u(num);
	chars_printed += ft_putstr(str);
	free(str);
	return (chars_printed);
}
