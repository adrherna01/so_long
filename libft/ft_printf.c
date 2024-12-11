/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrherna <adrianhdt.2001@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:43:10 by adrherna          #+#    #+#             */
/*   Updated: 2023/10/31 13:46:05 by adrherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;
	int		ret_val;

	count = 0;
	va_start(args, format);
	while (*format != 0)
	{
		if (*format != '%')
			if (ft_putchar(*format, &count) == -1)
				return (-1);
		if (*format == '%')
		{
			format++;
			if (*format != '%')
				ret_val = ft_check_char(*format, va_arg(args, void *), &count);
			else
				ret_val = ft_putchar('%', &count);
			if (ret_val == -1)
				return (-1);
		}
		format++;
	}
	va_end(args);
	return (count);
}

// int	ft_printf(const char *format, ...)

// #include <stdio.h>
// int	main(void)
// {
// 	int a;
// 	int b;
// 	a = ft_printf("%%%c", 'x');
// 	b = printf("%%%c", 'x');
// 	printf("\na: %d\nb: %d\n", a, b);
// 	return (0);
// }
