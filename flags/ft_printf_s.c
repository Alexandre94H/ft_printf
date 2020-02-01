/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:46:36 by ahallain          #+#    #+#             */
/*   Updated: 2020/02/01 10:50:56 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "../utils/ft_printf_utils.h"

size_t	ft_putstr_len(char *str, size_t len, int display)
{
	size_t	res;

	res = 0;
	while (*str && len--)
	{
		res += ft_putchar(*str, display);
		str++;
	}
	return (res);
}

size_t	ft_printf_s(va_list list, t_display settings, int display)
{
	static char	*str;
	size_t		res;

	if (list != NULL)
		str = va_arg(list, char*);
	if (str == NULL)
		str = "(null)";
	res = 0;
	if (settings.self.used)
		res += ft_putstr_len(str, settings.self.size, display);
	else
		res += ft_putstr_len(str, -1, display);
	return (res);
}
