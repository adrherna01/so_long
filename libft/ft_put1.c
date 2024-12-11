/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrherna <adrianhdt.2001@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:46:29 by adrherna          #+#    #+#             */
/*   Updated: 2023/10/31 12:54:12 by adrherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, int *count)
{
	if (write (1, &c, 1) == -1)
		return (-1);
	else
	{
		(*count)++;
		return (1);
	}
}

int	ft_putstr(char *str, int *count)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (write (1, &str[i], 1) == -1)
			return (-1);
		i++;
		(*count)++;
	}
	return (1);
}

int	ft_put_int(int n, int *count)
{
	if (n == -2147483648)
	{
		if ((ft_putstr("-2147483648", count)) == -1)
			return (-1);
		return (1);
	}
	if (n < 0)
	{
		if (write (1, "-", 1) == -1)
			return (-1);
		n *= -1;
		(*count)++;
	}
	if (n >= 10)
	{
		if (ft_put_int (n / 10, count) == -1)
			return (-1);
	}
	n = (n % 10) + 48;
	if (write (1, &n, 1) == -1)
		return (-1);
	(*count)++;
	return (1);
}

int	ft_put_un_int(unsigned int n, int *count)
{
	char	nb;

	nb = 0;
	if (n >= 10)
	{
		if (ft_put_un_int (n / 10, count) == -1)
			return (-1);
	}
	nb = (n % 10) + 48;
	if (write (1, &nb, 1) == -1)
		return (-1);
	(*count)++;
	return (1);
}

// int main(void)
// {
// 	int	num1;
// 	int	num2;
// 	int	num3;
// 	int	num4;

// 	num1 = 34;
// 	num2 = 0;
// 	num3 = 2345;
// 	num4 = -345;

// 	ft_put_hexa_low(num4);
// }
