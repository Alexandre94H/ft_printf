/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:55:17 by ahallain          #+#    #+#             */
/*   Updated: 2020/02/01 09:41:14 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "utils/ft_printf_utils.h"

size_t	ft_check(const char *str, va_list list)
{
	size_t		res;
	char		*arg;

	res = 0;
	while (*str)
		if (*str == '%')
		{
			arg = ft_get_arg(&str);
			res += ft_printf_display(arg, list);
			free(arg);
		}
		else
			res += ft_putchar(*str++, 1);
	return (res);
}

int		ft_printf(const char *str, ...)
{
	va_list	list;
	size_t	res;

	va_start(list, str);
	res = ft_check(str, list);
	va_end(list);
	return (res);
}
