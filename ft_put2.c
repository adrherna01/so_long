/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrherna <adrianhdt.2001@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:37:04 by adrherna          #+#    #+#             */
/*   Updated: 2023/11/16 14:08:43 by adrherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hexa_upp(unsigned int n, int *count)
{
	char	*hexa_chars;

	hexa_chars = "0123456789ABCDEF";
	if (n < 16)
	{
		if (write(1, &hexa_chars[n], 1) == -1)
			return (-1);
		(*count)++;
	}
	else
	{
		if (ft_put_hexa_upp(n / 16, count) == -1)
			return (-1);
		if (write(1, &hexa_chars[n % 16], 1) == -1)
			return (-1);
		(*count)++;
	}
	return (1);
}

int	ft_put_hexa_low(unsigned int n, int *count)
{
	char	*hexa_chars;

	hexa_chars = "0123456789abcdef";
	if (n < 16)
	{
		if (write(1, &hexa_chars[n], 1) == -1)
			return (-1);
		(*count)++;
	}
	else
	{
		if (ft_put_hexa_low(n / 16, count) == -1)
			return (-1);
		if (write(1, &hexa_chars[n % 16], 1) == -1)
			return (-1);
		(*count)++;
	}
	return (1);
}

int	ft_put_hexa_ptr(unsigned long n, int *count)
{
	char	*hexa_chars;

	hexa_chars = "0123456789abcdef";
	if (n < 16)
	{
		if (write (1, "0x", 2) == -1)
			return (-1);
		(*count) += 2;
		if (write(1, &hexa_chars[n], 1) == -1)
			return (-1);
		(*count)++;
	}
	else
	{
		if (ft_put_hexa_ptr(n / 16, count) == -1)
			return (-1);
		if (write(1, &hexa_chars[n % 16], 1) == -1)
			return (-1);
		(*count)++;
	}
	return (1);
}

// int	main(void)
// {
// 	char	*str;

// 	str = "ola qlq";
// 	printf("%p\n", str);
// 	ft_put_ptr(str);
// }
