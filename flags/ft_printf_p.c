/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:15:33 by ahallain          #+#    #+#             */
/*   Updated: 2020/02/03 09:54:33 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "../utils/ft_printf_utils.h"

size_t	ft_printf_p(va_list list, t_display settings, int display)
{
	static long	nbr;
	size_t		res;

	if (list != NULL)
		nbr = (uintptr_t)va_arg(list, void*);
	res = 0;
	res += ft_putstr_len("0x", -1, display);
	if (nbr || !settings.self.used || settings.self.size)
		res += ft_putnbr("0123456789abcdef", nbr, display);
	return (res);
}
