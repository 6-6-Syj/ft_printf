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

ft_printf_args(args, format)
{
	if (format[i] == 'c')
		va_arg(args, int);
	else if (format[i] == 's')
		va_arg(args, char);
	else if (format[i] == 'p')
		va_arg(args, char);
	else if (format[i] == 'd')
		va_arg(args, char);
	else if (format[i] == 'i')
		ft_putnbr(va_arg(args, int));
	else if (format[i] == 'x')
		va_arg(args, char);
	else if (format[i] == 'X')
		va_arg(args, char);
	else if (format[i] == '%')
		va_arg(args, char);
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
			ft_putchar(format[i]);
			i++;
		}
		count += ft_printf_args(args, format);
		count++;
		i++;
	}
	va_end (args);
	return (count);
}
