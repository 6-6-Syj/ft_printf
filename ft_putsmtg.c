/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsmtg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-21 19:07:47 by jmagand           #+#    #+#             */
/*   Updated: 2024-11-21 19:07:47 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putchar(const char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *str)
{
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

