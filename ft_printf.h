/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrherna <adrianhdt.2001@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 10:34:23 by adrherna          #+#    #+#             */
/*   Updated: 2023/10/31 10:26:49 by adrherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_putchar(char c, int *count);

int		ft_putstr(char *str, int *count);

int		ft_put_int(int n, int *count);

int		ft_put_un_int(unsigned int n, int *count);

int		ft_put_hexa_upp(unsigned int n, int *count);

int		ft_put_hexa_low(unsigned int n, int *count);

int		ft_put_hexa_ptr(unsigned long n, int *count);

int		ft_check_char(char c, void *arg, int *count);

int		ft_printf(const char *format, ...);

#endif
