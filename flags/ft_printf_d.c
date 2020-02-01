/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:19:37 by ahallain          #+#    #+#             */
/*   Updated: 2020/02/01 10:21:08 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "../utils/ft_printf_utils.h"

size_t	ft_putnbr(char *base, long nbr, int display)
{
	size_t	res;
	size_t	len;

	len = ft_strlen(base);
	res = 0;
	if (nbr < 0)
		nbr *= -1;
	if (nbr >= (signed)len)
		res += ft_putnbr(base, nbr / len, display);
	res += ft_putchar(base[nbr % len], display);
	return (res);
}

size_t	ft_scan_self(t_display settings, long nbr)
{
	size_t		self;

	self = 0;
	if (settings.final.used && settings.final.null)
	{
		self = settings.final.size;
		if (nbr < 0)
			self--;
	}
	if (settings.self.used)
		self = settings.self.size;
	return (self);
}

char	*ft_getbase(char flag)
{
	if (flag == 'x')
		return ("0123456789abcdef");
	else if (flag == 'X')
		return ("0123456789ABCDEF");
	else
		return ("0123456789");
}

char	ft_write_before(long nbr, size_t size, size_t self, int display)
{
	size_t	res;

	res = 0;
	if (nbr < 0)
		res += ft_putchar('-', display);
	while (size < self--)
		res += ft_putchar('0', display);
	return (res);
}

size_t	ft_printf_d(char *arg, va_list list, t_display settings, int display)
{
	static long	nbr;
	size_t		self;
	size_t		res;
	size_t		size;
	char		last;

	last = arg[ft_strlen(arg) - 1];
	if (list != NULL)
	{
		if (last == 'u' || last == 'x' || last == 'X')
			nbr = va_arg(list, unsigned int);
		else
			nbr = va_arg(list, int);
	}
	res = 0;
	self = ft_scan_self(settings, nbr);
	if (settings.self.used && !self && !nbr)
		return (0);
	size = ft_putnbr(ft_getbase(last), nbr, 0);
	if (settings.space && !(nbr < 0))
		res += ft_putchar(' ', display);
	res += ft_write_before(nbr, size, self, display);
	res += ft_putnbr(ft_getbase(last), nbr, display);
	return (res);
}
