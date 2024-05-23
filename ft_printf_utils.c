/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:16:33 by alarose           #+#    #+#             */
/*   Updated: 2024/05/23 15:27:48 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_n_print(va_list args, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'p')
		return (p_p(va_arg(args, unsigned long), 'x'));
	if (c == 'd' || c == 'i')
		return (p_int(va_arg(args, int)));
	if (c == 'u')
		return (p_u(va_arg(args, unsigned int)));
	if (c == 'x')
		return (p_hex(va_arg(args, long long), 'x'));
	if (c == 'X')
		return (p_hex(va_arg(args, long long), 'X'));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_putchar(int c)
{
	char	cc;

	if (!c)
		return (0);
	cc = (char)c;
	write(1, &cc, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		write(1, str++, 1);
	}
	return (1);
}

char	is_in_set(char c)
{
	int	i;

	i = 0;
	while (SET[i])
	{
		if (c == SET[i])
			return (SET[i]);
		i++;
	}
	return (0);
}
