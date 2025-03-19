/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amert <amert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:27:00 by amert             #+#    #+#             */
/*   Updated: 2025/03/04 20:27:01 by amert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int x)
{
	return (write(1, &x, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		return (write(1, "(null)", 6));
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	long	nb;
	int		count;

	count = 0;
	nb = n;
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = (nb * -1);
	}
	if (nb < 10)
		count += ft_putchar(nb + 48);
	if (nb > 9)
	{
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
	return (count);
}

int	ft_un_int(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb < 10)
		count += ft_putchar(nb + 48);
	if (nb > 9)
	{
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
	return (count);
}

int	ft_percent(void)
{
	return (write(1, "%", 1));
}
