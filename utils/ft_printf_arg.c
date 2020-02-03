/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:45:32 by ahallain          #+#    #+#             */
/*   Updated: 2020/02/03 09:50:24 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf_utils.h"

char	*ft_get_arg(const char **src)
{
	size_t	index;
	size_t	len;
	char	*arg;

	len = 0;
	(*src)++;
	while ((*src)[len] && (*src)[len] != 'c'
		&& (*src)[len] != 's' && (*src)[len] != 'p'
		&& (*src)[len] != 'd' && (*src)[len] != 'i'
		&& (*src)[len] != 'u' && (*src)[len] != 'x'
		&& (*src)[len] != 'X' && (*src)[len] != '%')
		len++;
	if (!(*src)[len])
		len = -1;
	len++;
	index = 0;
	arg = malloc(len + 1);
	while (len--)
		arg[index++] = *(*src)++;
	arg[index] = 0;
	return (arg);
}

size_t	ft_print_arg(char *arg, va_list list, t_display settings, int display)
{
	size_t	res;
	char	last;

	res = 0;
	last = arg[ft_strlen(arg) - 1];
	if (last == 'c')
		res += ft_printf_c(list, display);
	else if (last == 's')
		res += ft_printf_s(list, settings, display);
	else if (last == 'd' || last == 'i' || last == 'u'
		|| last == 'x' || last == 'X')
		res += ft_printf_d(arg, list, settings, display);
	else if (last == 'p')
		res += ft_printf_p(list, settings, display);
	else if (last == '%')
		res += ft_printf_prc(settings, display);
	return (res);
}
