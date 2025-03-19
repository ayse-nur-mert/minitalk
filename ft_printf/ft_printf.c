/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amert <amert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:26:43 by amert             #+#    #+#             */
/*   Updated: 2025/03/04 20:26:44 by amert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_format(va_list vl, int ch)
{
	if (ch == 'c')
		return (ft_putchar(va_arg(vl, int)));
	else if (ch == 's')
		return (ft_putstr(va_arg(vl, char *)));
	else if (ch == 'p')
		return (ft_printu(va_arg(vl, unsigned long), "0123456789abcdef"));
	else if (ch == 'd' || ch == 'i')
		return (ft_putnbr(va_arg(vl, int)));
	else if (ch == 'u')
		return (ft_un_int(va_arg(vl, int)));
	else if (ch == 'x')
		return (ft_hexa(va_arg(vl, unsigned int), "0123456789abcdef"));
	else if (ch == 'X')
		return (ft_hexa(va_arg(vl, unsigned int), "0123456789ABCDEF"));
	else if (ch == '%')
		return (ft_percent());
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		counter;
	va_list	hello;

	i = 0;
	counter = 0;
	va_start(hello, str);
	while (str[i])
	{
		if (str[i] != '%')
			counter += ft_putchar(str[i]);
		else
		{
			i++;
			counter += handle_format(hello, str[i]);
		}
		i++;
	}
	va_end(hello);
	return (counter);
}
