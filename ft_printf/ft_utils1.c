/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amert <amert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:26:55 by amert             #+#    #+#             */
/*   Updated: 2025/03/19 13:40:07 by amert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa(unsigned int z, char *list)
{
	int	count;

	count = 0;
	if (z >= 16)
	{
		count += ft_hexa(z / 16, list);
	}
	count += ft_putchar(list[z % 16]);
	return (count);
}

int	ft_printu(unsigned long x, char *list)
{
	if (x == 0)
		return (ft_putstr("(nil)"));
	write(1, "0x", 2);
	return (ft_printu2(x, list) + 2);
}

int	ft_printu2(unsigned long x, char *list)
{
	int	count;

	count = 0;
	if (x >= 16)
	{
		count += ft_printu2(x / 16, list);
	}
	count += ft_putchar(list[x % 16]);
	return (count);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' \
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}
