/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:15:51 by alarose           #+#    #+#             */
/*   Updated: 2024/05/23 15:27:44 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	p_hex(long long nb, char x)
{
	if (!nb)
		return (0);
	if (nb >= 16)
		p_hex(nb / 16, x);
	if (x == 'x')
		ft_putchar(HEX_LOWER[nb % 16]);
	else
		ft_putchar(HEX_UPPER[nb % 16]);
	return (1);
}

int	p_p(unsigned long nb, char x)
{
	if (nb == 0)
	{
		write(1, "(nil)", 5);
		return (1);
	}
	if (nb < 16)
		ft_putstr("0x");
	if (nb >= 16)
		p_p(nb / 16, x);
	if (x == 'x')
	{
		ft_putchar(HEX_LOWER[nb % 16]);
		return (1);
	}
	else
	{
		ft_putchar(HEX_UPPER[nb % 16]);
		return (1);
	}
	return (0);
}

int	p_int(int n)
{
	if (!n)
		return (0);
	if (n == INT_MIN)
		return (write(1, "-2147483648", 11), 1);
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		p_int(n / 10);
	ft_putchar(n % 10 + '0');
	return (1);
}

int	p_u(unsigned int u)
{
	if (!u)
		return (0);
	if (u >= 10)
		p_u(u / 10);
	ft_putchar(u % 10 + '0');
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	char	type;
	int		i;
	int		ret;

	va_start(args, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && is_in_set(str[i + 1]))
		{
			type = str[i + 1];
			ret = check_n_print(args, type);
			if (ret == 0)
				return (0);
			i += 2;
		}
		else
		{
			write(1, &(str[i]), 1);
			i++;
		}
	}
	return (ret);
}

/*#include <stdlib.h>

int	main(void)
{
	char		s[] = "Hello";
	long long	L = 0;
	size_t		i;
	size_t		size;
	size_t		size_int;
	size_t		size_hex;
	size_t		size_p;
	size_t		size_strs;
	size_t		size_char;
	size_t		size_u;

		char	c1 = 'c';
		int		c2 = -457;
		int		c3 = 457;
		char	c4 = 0;
		char	test_char[] = {c1, c2, c3, c4};
		size_char = 4;

		char	s1[] = " ";
		char	s2[] = "";
		char	s3[] = {'\0'};
		char	*s4;
		s4 = malloc(sizeof(char) * 6);
		char	*strs[] = {s, s1, s2, s3, s4};
		size_strs = 5;

		int	test_int[] = {42, -42, 2589974, -2589974, 0,
		INT_MAX, INT_MIN, UINT_MAX, UINT_MAX + 7};
		size_int = 9;

		unsigned int test_u[] = {42, -42, 2589974, -2589974, 0,
		INT_MAX, INT_MIN, UINT_MAX, UINT_MAX + 7};
		size_u = 9;

		int	test_hex[] = {42, -42, 2589974, -2589974, 0,
		INT_MAX, INT_MIN, UINT_MAX, UINT_MAX + 7};
		size_hex = 9;

		char	*p1, *p2, *p3;
		p1 = malloc(sizeof(char));
		p2 = malloc(sizeof(int));
		p3 = NULL;
		void *pointers[] = {p1, p2, p3, s};
		size_p = 4;

		printf("\nTests for CHARS (%%c):\n");
		i = 0;
		size = size_char;
		while (i < size)
		{
			ft_printf("%c", test_char[i]);
			printf(" VS printf: %c\n", test_char[i]);
			i++;
		}
		free (s4);

		printf("\nTests for STRS (%%s):\n");
		i = 0;
		size = size_strs;
		while (i < size)
		{
			ft_printf("%s", strs[i]);
			printf(" VS printf: %s\n", strs[i]);
			i++;
		}

		printf("\nTests for void * pointer (%%p):\n");
		i = 0;
		size = size_p;
		while (i < size)
		{
			ft_printf("%p", pointers[i]);
			printf(" VS printf: %p\n", pointers[i]);
			i++;
		}

		printf("\nTests for INT (%%d):\n");
		i = 0;
		size = size_int;
		while (i < size)
		{
			ft_printf("%d", test_int[i]);
			printf(" VS printf: %d\n", test_int[i]);
			i++;
		}

		printf("\nTests for INT (%%i):\n");
		i = 0;
		size = size_int;
		while (i < size)
		{
			ft_printf("%i", test_int[i]);
			printf(" VS printf: %i\n", test_int[i]);
			i++;
		}

		printf("\nTests for UNSIGNED INT (%%u):\n");
		i = 0;
		size = size_u;
		while (i < size)
		{
			ft_printf("%u", test_u[i]);
			printf(" VS printf: %u\n", test_u[i]);
			i++;
		}

		printf("\nTests for HEX (%%x):\n");
		i = 0;
		size = size_hex;
		while (i < size)
		{
			ft_printf("%x", test_hex[i]);
			printf(" VS printf: %x\n", test_hex[i]);
			i++;
		}

		printf("\nTests for HEX (%%X):\n");
		i = 0;
		size = size_hex;
		while (i < size)
		{
			ft_printf("%X", test_hex[i]);
			printf(" VS printf: %X\n", test_hex[i]);
			i++;
		}

		printf("\nTests for %%:\n");
		ft_printf("%%");
		printf(" VS printf: %%\n");

		printf("\n**********full sentences***********\n");

				printf("\nTests for STRS (%%s):\n");
		i = 0;
		size = size_strs;
		while (i < size)
		{
			ft_printf("|%s boss!", strs[i]);
			printf("| VS printf: \n|%s boss!|\n\n", strs[i]);
			i++;
		}

		ft_printf("Tesing a char |%c|, now a str |%s|, an adress: |%p|,
		\n int |%d|, other int |%i|, u |%u|, HEX x |%x|,\n HEX X |%X|,
		 and finishing with a %%\n", c1, s, p1, test_int[0], test_int[0],
		 test_u[0], test_hex[0], test_hex[0]);
	return (0);
}*/