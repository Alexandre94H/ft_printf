/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_display.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:00:15 by ahallain          #+#    #+#             */
/*   Updated: 2020/02/01 09:40:28 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf_utils.h"

void	ft_set_size(t_display *settings, char *field, size_t size)
{
	if (*field == 'f')
	{
		(*settings).final.used = 1;
		(*settings).final.size = size;
	}
	else if (*field == 's')
	{
		(*settings).self.used = 1;
		(*settings).self.size = size;
	}
}

void	ft_scan(char *arg, t_display *settings, va_list list)
{
	size_t	size;
	char	*type;

	while (*arg)
	{
		type = "final";
		size = 0;
		if (*arg == '-')
			(*settings).final.sign = -1;
		else if (*arg == '.')
			type = "self";
		else if (*arg == '0')
			(*settings).final.null = 1;
		else if (ft_isdigit(*arg))
			size = *arg - '0';
		else
			return ;
		while (ft_isdigit(*++arg))
			size = size * 10 + *arg - '0';
		ft_set_size(settings, type, size);
	}
	(void)list;
}

size_t	ft_printf_display(char *arg, va_list list)
{
	size_t		res;
	t_display	settings;
	size_t		size;

	res = 0;
	settings = (t_display) {{0, 0, 0, 1}, {0, 0, 0, 1}, 0};
	while (*arg == ' ')
	{
		settings.space = 1;
		arg++;
	}
	ft_print_arg(arg, list, settings, 0);
	ft_scan(arg, &settings, list);
	size = ft_print_arg(arg, NULL, settings, 0);
	if (settings.final.sign > 0)
		while (settings.final.size > size)
		{
			res += ft_putchar(' ', 1);
			settings.final.size--;
		}
	res += ft_print_arg(arg, NULL, settings, 1);
	while (settings.final.size-- > size)
		res += ft_putchar(' ', 1);
	return (res);
}
