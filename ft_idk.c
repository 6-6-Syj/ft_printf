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

int	base_len(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

int	check_base(char *base)
{
	int	i;
	int j;

	i = 0;
	while (base[i] != '\0')
    {
		if (base[i] == 43 || base[i] == 45)
			return (0);
		j = 0;
		while (base[j] != '\0')
		{
			if (i != j && base[i] == base[j])
            	return (0);
    		j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}
int	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return;
	}
	if (n < 0)
	{
		n *= -1;
		ft_putchar('-');
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + 48);
	}
	else if (n < 10)
		ft_putchar(n + 48);
	return (int_len(n));
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	nb;

	nb = nbr;
	if (!check_base(base))
        return ;
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

