/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:58:44 by ahallain          #+#    #+#             */
/*   Updated: 2020/02/01 10:41:26 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

# include <unistd.h>

typedef struct	s_size
{
	int		used;
	int		null;
	size_t	size;
	int		sign;
}				t_size;

typedef struct	s_display
{
	t_size	final;
	t_size	self;
	int		space;
}				t_display;

size_t			ft_putchar(char c, int display);
size_t			ft_putstr_len(char *str, size_t len, int display);
size_t			ft_strlen(char *str);
int				ft_contains(char *str, char c);
int				ft_isdigit(int c);
size_t			ft_printf_display(char *arg, va_list list);
char			*ft_get_arg(const char **src);
size_t			ft_print_arg(char *arg, va_list list, t_display settings,
	int display);
size_t			ft_printf_c(va_list list, int display);
size_t			ft_printf_s(va_list list, t_display settings, int display);
size_t			ft_putstr_len(char *str, size_t len, int display);
size_t			ft_printf_p(va_list list, int display);
size_t			ft_printf_d(char *arg, va_list list, t_display settings,
	int display);
size_t			ft_putnbr(char *base, long nbr, int display);
size_t			ft_printf_prc(t_display settings, int display);
#endif
