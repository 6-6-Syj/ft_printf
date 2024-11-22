/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                            :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-21 16:51:29 by jmagand           #+#    #+#             */
/*   Updated: 2024-11-21 16:51:29 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stddef.h>

int	ft_printf(const char *format, ...);
int	ft_strlen(char *s);
int	ft_putchar(char c, int fd);
int	ft_putstr(char *str, int fd);
int	ft_putnbr(int n, int fd);

#endif
