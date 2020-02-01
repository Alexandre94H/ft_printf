/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:35:38 by ahallain          #+#    #+#             */
/*   Updated: 2020/02/01 09:40:19 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "../utils/ft_printf_utils.h"

size_t	ft_printf_c(va_list list, int display)
{
	static char	c;
	size_t		res;

	if (list != NULL)
		c = va_arg(list, int);
	res = 0;
	res += ft_putchar(c, display);
	return (res);
}
