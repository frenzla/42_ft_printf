/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:13:33 by alarose           #+#    #+#             */
/*   Updated: 2024/05/23 15:27:45 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

# define SET "cspdiuxX%"
# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

int		ft_printf(const char *str, ...);
int		check_n_print(va_list args, char c);
int		p_hex(long long nb, char x);
int		p_p(unsigned long nb, char x);
int		p_int(int n);
int		p_u(unsigned int u);
int		ft_putchar(int c);
int		ft_putstr(char *str);
char	is_in_set(char c);

#endif