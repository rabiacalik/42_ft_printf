/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcalik <rcalik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 08:46:06 by hamaarou          #+#    #+#             */
/*   Updated: 2022/12/05 16:52:11 by rcalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

int	prnt_second(va_list args, char k)
{
	int	len;

	len = 0;
	if (k == 'c')
		len += ft_putchar(va_arg(args, int));
	if (k == 's')
		len += ft_putstr(va_arg(args, char *));
	if (k == 'd' || k == 'i')
		len += ft_putnbr(va_arg(args, int));
	if (k == 'u')
		len += ft_putnbr(va_arg(args, unsigned int));
	if (k == 'x')
		len += ft_putnbr_hex(va_arg(args, unsigned int), 'x');
	if (k == 'X')
		len += ft_putnbr_hex(va_arg(args, unsigned int), 'X');
	if (k == '%')
		len += ft_putchar('%');
	if (k == 'p')
	{
		len += ft_putstr("0x");
		len += ft_putnbr_hex(va_arg(args, unsigned long), 'x');
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!str)
		return (0);
	va_start(args, str);
	while (str[i] != 0)
	{
		if (str[i] == '%')
		{
			len += prnt_second(args, str[i + 1]);
			i++;
		}
		else
		{
			len += ft_putchar(str[i]);
		}
		i++;
	}
	va_end(args);
	return (len);
}
