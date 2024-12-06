/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrherna <adrianhdt.2001@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:58:01 by adrherna          #+#    #+#             */
/*   Updated: 2023/11/08 14:06:18 by adrherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_char(char c, void *arg, int *count)
{
	if (c == 'c')
		return (ft_putchar((char)arg, count));
	else if (c == 's')
	{
		if ((char *)arg == NULL)
			return (ft_putstr("(null)", count));
		else
			return (ft_putstr((char *)arg, count));
	}
	else if (c == 'p')
		return (ft_put_hexa_ptr((unsigned long)arg, count));
	else if (c == 'd')
		return (ft_put_int((int)arg, count));
	else if (c == 'i')
		return (ft_put_int((int)arg, count));
	else if (c == 'u')
		return (ft_put_un_int((unsigned int)arg, count));
	else if (c == 'x')
		return (ft_put_hexa_low((unsigned int)arg, count));
	else if (c == 'X')
		return (ft_put_hexa_upp((unsigned int)arg, count));
	else
		return (-1);
}
