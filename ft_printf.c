/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-21 17:12:13 by jmagand           #+#    #+#             */
/*   Updated: 2024-11-21 17:12:13 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdarg.h>

int ft_printf_args(va_list args, const char * format, size_t i)
{
	if (format[i] == 'c')
		return (ft_putchar(va_arg(args, int), 1));
	else if (format[i] == 's')
		return (ft_putstr(va_arg(args, int), 1));
	else if (format[i] == 'i')
		return (ft_putnbr(va_arg(args, int), 1));
	else if (format[i] == 'd')
		return (ft_putnbr_base(va_arg(args, int), "0123456789"));
	else if (format[i] == 'p')
		return ((va_arg(args, int), "0123456789ABCDEF"));
	else if (format[i] == 'x')
		return ((va_arg(args, int), "0123456789ABCDEF"));
	else if (format[i] == 'X')
		return ((va_arg(args, int), "0123456789ABCDEF"));
	else if (format[i] == '%')
		return ((va_arg(args, int), 1));
}

int	ft_printf(const char *format, ...)
{
	va_list args;
	size_t	i;
	size_t	count;

	if (!format)
		return (-1);
	va_start (args, format);
	i = 0;
	while (format[i])
	{
		while (format[i] != '%')
		{
			count++;
			ft_putchar(format[i], 1);
			i++;
		}
		count += ft_printf_args(args, format, i);
		count++;
		i++;
	}
	va_end (args);
	return (count);
}
