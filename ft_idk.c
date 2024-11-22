/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_idk.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-21 19:32:20 by jmagand           #+#    #+#             */
/*   Updated: 2024-11-21 19:32:20 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	int_len(long nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		count++;
		nb = -nb;
	}
	if (nb == 0)
		count++;
	while (nb != 0)
	{
		count++;
		nb = nb / 10;
	}
	return (count);
}

int	ft_putnbr(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return;
	}
	if (n < 0)
	{
		n *= -1;
		ft_putchar('-', 1);
	}
	if (n > 9)
	{
		ft_putnbr(n / 10, 1);
		ft_putchar(n % 10 + 48, 1);
	}
	else if (n < 10)
		ft_putchar(n + 48, 1);
	return (int_len(n));
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	nb;

	nb = nbr;
    if (nb < 0)
    {
        nb = nb * -1;
        write(1, "-", 1);
    }
    if (nb >= base_len(base))
		ft_putnbr_base(nb / base_len(base), base);
	write(1, &base[nb % base_len(base)], 1);
	// return (int_len());
	//  a reflechir avec base
}

