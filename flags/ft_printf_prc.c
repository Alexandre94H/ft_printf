/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_prc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:19:37 by ahallain          #+#    #+#             */
/*   Updated: 2020/02/01 09:54:01 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "../utils/ft_printf_utils.h"

size_t	ft_printf_prc(t_display settings, int display)
{
	size_t		res;
	size_t		size;

	size = 0;
	if (settings.final.used && settings.final.null)
		size = settings.final.size;
	res = 0;
	while (size-- > 1)
		res += ft_putchar('0', display);
	res += ft_putchar('%', display);
	return (res);
}
