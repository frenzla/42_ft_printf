/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:15:51 by alarose           #+#    #+#             */
/*   Updated: 2024/05/28 11:53:59 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	p_hex(unsigned int nb, char x, int *count)
{
	if (nb >= 16)
		p_hex(nb / 16, x, count);
	if (x == 'x')
		ft_putchar(HEX_LOWER[nb % 16], count);
	else
		ft_putchar(HEX_UPPER[nb % 16], count);
	return (1);
}

int	p_p(unsigned long nb, char x, int *count)
{
	if (nb == 0)
	{
		ft_putstr("(nil)", count);
		return (1);
	}
	if (nb < 16)
		ft_putstr("0x", count);
	if (nb >= 16)
		p_p(nb / 16, x, count);
	if (x == 'x')
	{
		ft_putchar(HEX_LOWER[nb % 16], count);
		return (1);
	}
	else
	{
		ft_putchar(HEX_UPPER[nb % 16], count);
		return (1);
	}
	return (0);
}

int	p_int(int n, int *count)
{
	if (n == INT_MIN)
		return (ft_putstr("-2147483648", count), 1);
	if (n < 0)
	{
		ft_putchar('-', count);
		n = -n;
	}
	if (n >= 10)
		p_int(n / 10, count);
	ft_putchar(n % 10 + '0', count);
	return (1);
}

int	p_u(unsigned int u, int *count)
{
	if (u >= 10)
		p_u(u / 10, count);
	ft_putchar(u % 10 + '0', count);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	char	type;
	int		i;
	int		count;

	va_start(args, str);
	i = 0;
	count = 0;
	if (str == NULL)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == '\0')
			return (-1);
		if (str[i] == '%' && is_in_set(str[i + 1]))
		{
			type = str[i + 1];
			check_n_print(args, type, &count);
			i += 2;
		}
		else
			ft_putchar(str[i++], &count);
	}
	return (count);
}

/*int	main(void)
{
	int		printed_chars;

	printf("--------- TEST 1 ---------\n");
	printed_chars = printf("printf:    %p\n", &printed_chars);
	printf("return: %d\n", printed_chars);
	printed_chars = ft_printf("ft_printf: %p\n", &printed_chars);
	printf("return: %d\n", printed_chars);
	printf("--------- TEST 2 ---------\n");
	printed_chars = printf("printf:    %p\n");
	printf("return: %d\n", printed_chars);
	printed_chars = ft_printf("ft_printf: %p\n");
	printf("return: %d\n", printed_chars);
	printf("--------- TEST 3 ---------\n");
	printed_chars = printf("printf:    %p\n", 42);
	printf("return: %d\n", printed_chars);
	printed_chars = ft_printf("ft_printf: %p\n", 42);
	printf("return: %d\n", printed_chars);
	printf("--------- TEST 4 ---------\n");
	printed_chars = printf("printf:    %c\n", 'A');
	printf("return: %d\n", printed_chars);
	printed_chars = ft_printf("ft_printf: %c\n", 'A');
	printf("return: %d\n", printed_chars);
	printf("--------- TEST 5 ---------\n");
	printed_chars = printf("printf:    %s\n", "42born2code");
	printf("return: %d\n", printed_chars);
	printed_chars = ft_printf("ft_printf: %s\n", "42born2code");
	printf("return: %d\n", printed_chars);
	printf("--------- TEST 6 ---------\n");
	printed_chars = printf("printf:    %d\n", INT_MIN - 1);
	printf("return: %d\n", printed_chars);
	printed_chars = ft_printf("ft_printf: %d\n", INT_MIN - 1);
	printf("return: %d\n", printed_chars);
	printf("--------- TEST 7 ---------\n");
	printed_chars = printf("printf:    %d\n", INT_MAX + 1);
	printf("return: %d\n", printed_chars);
	printed_chars = ft_printf("ft_printf: %d\n", INT_MAX + 1);
	printf("return: %d\n", printed_chars);
	printf("--------- TEST 8 ---------\n");
	printed_chars = printf("printf:    %u\n", UINT_MAX);
	printf("return: %d\n", printed_chars);
	printed_chars = ft_printf("ft_printf: %u\n", UINT_MAX);
	printf("return: %d\n", printed_chars);
	printf("--------- TEST 9 ---------\n");
	printed_chars = printf("printf:    %u\n", UINT_MAX + 1);
	printf("return: %d\n", printed_chars);
	printed_chars = ft_printf("ft_printf: %u\n", UINT_MAX + 1);
	printf("return: %d\n", printed_chars);
	printf("--------- TEST 10 ---------\n");
	printed_chars = printf("printf:    %x\n", 42);
	printf("return: %d\n", printed_chars);
	printed_chars = ft_printf("ft_printf: %x\n", 42);
	printf("return: %d\n", printed_chars);
	printf("--------- TEST 11 ---------\n");
	printed_chars = printf("printf:    %X\n", 42);
	printf("return: %d\n", printed_chars);
	printed_chars = ft_printf("ft_printf: %X\n", 42);
	printf("return: %d\n", printed_chars);
	printf("--------- TEST 12 ---------\n");
	printed_chars = printf("printf:    %x\n", -42);
	printf("return: %d\n", printed_chars);
	printed_chars = ft_printf("ft_printf: %x\n", -42);
	printf("return: %d\n", printed_chars);
	printf("--------- TEST 13 ---------\n");
	printed_chars = printf("printf:    %d\n");
	printf("return: %d\n", printed_chars);
	printed_chars = ft_printf("ft_printf: %d\n");
	printf("return: %d\n", printed_chars);
	printf("--------- TEST 14 ---------\n");
	printed_chars = printf("printf:    %s %d %s\t%c\n",
	"The best school is ", 42, "Paris", '.');
	printf("return: %d\n", printed_chars);
	printed_chars = ft_printf("ft_printf: %s %d %s\t%c\n",
	"The best school is ", 42, "Paris", '.');
	printf("return: %d\n", printed_chars);
	printf("--------- TEST 15 ---------\n");
	printed_chars = printf("printf:    %c\n", "Code");
	printf("return: %d\n", printed_chars);
	printed_chars = ft_printf("ft_printf: %c\n", "Code");
	printf("return: %d\n", printed_chars);
	printf("--------- TEST 16 ---------\n");
	printed_chars = printf("printf:    %c\n", 'C');
	printf("return: %d\n", printed_chars);
	printed_chars = ft_printf("ft_printf: %c\n", 'C');
	printf("return: %d\n", printed_chars);
	printf("--------- TEST 17 ---------\n");
	printed_chars = printf("printf:    %c\n", 0);
	printf("return: %d\n", printed_chars);
	printed_chars = ft_printf("ft_printf: %c\n", 0);
	printf("return: %d\n", printed_chars);
	printf("--------- TEST 18 ---------\n");
	printed_chars = printf("printf:    %s %s\n", 0, 0);
	printf("return: %d\n", printed_chars);
	printed_chars = ft_printf("ft_printf: %s %s\n", 0, 0);
	printf("return: %d\n", printed_chars);
	printf("--------- TEST 19 ---------\n");
	printed_chars = printf("printf:    %p %p\n", 0, 0);
	printf("return: %d\n", printed_chars);
	printed_chars = ft_printf("ft_printf: %p %p\n", 0, 0);
	printf("return: %d\n", printed_chars);
	printf("--------- TEST 20 ---------\n");
	printed_chars = printf("printf:    %x %x\n", 0, 0);
	printf("return: %d\n", printed_chars);
	printed_chars = ft_printf("ft_printf: %x %x\n", 0, 0);
	printf("return: %d\n", printed_chars);
	printf("--------- TEST 21 ---------\n");
	printed_chars = printf("printf:    %X %X\n", 0, 0);
	printf("return: %d\n", printed_chars);
	printed_chars = ft_printf("ft_printf: %X %X\n", 0, 0);
	printf("return: %d\n", printed_chars);
	printf("--------- TEST 22 ---------\n");
	printed_chars = printf("printf:    %\n");
	printf("return: %d\n", printed_chars);
	printed_chars = ft_printf("ft_printf: %\n");
	printf("return: %d\n", printed_chars);
	printf("--------- TEST 23 ---------\n");
	printed_chars = printf("printf:    %% %%\n");
	printf("return: %d\n", printed_chars);
	printed_chars = ft_printf("ft_printf: %% %%\n");
	printf("return: %d\n", printed_chars);
	printf("--------- TEST 24 ---------\n");
	printed_chars = printf("printf:    %x\n", INT_MIN);
	printf("return: %d\n", printed_chars);
	printed_chars = ft_printf("ft_printf: %x\n", INT_MIN);
	printf("return: %d\n", printed_chars);
	printf("--------- TEST 25 ---------\n");
	printed_chars = printf("printf:    %x\n", LONG_MAX);
	printf("return: %d\n", printed_chars);
	printed_chars = ft_printf("ft_printf: %x\n", LONG_MAX);
	printf("return: %d\n", printed_chars);
	printf("--------- TEST 26 ---------\n");
	printed_chars = printf(NULL);
	printf("return: %d\n", printed_chars);
	printed_chars = ft_printf(NULL);
	printf("return: %d\n", printed_chars);
	printf("--------- TEST 27 ---------\n");
	printed_chars = printf(0);
	printf("return: %d\n", printed_chars);
	printed_chars = ft_printf(0);
	printf("return: %d\n", printed_chars);
	printf("--------- TEST 28 ---------\n");
	printed_chars = printf("%");
	printf("return: %d\n", printed_chars);
	printed_chars = ft_printf("%");
	printf("return: %d\n", printed_chars);
	printf("--------- TEST 29 ---------\n");
	printed_chars = printf("Hello World\n%");
	printf("return: %d\n", printed_chars);
	printed_chars = ft_printf("Hello World\n%");
	printf("return: %d\n", printed_chars);
	printf("--------- TEST 30 ---------\n");
	printed_chars = printf("Hello World %c | %d\n", NULL, 42);
	printf("return: %d\n", printed_chars);
	printed_chars = ft_printf("Hello World %c | %d\n", NULL, 42);
	printf("return: %d\n", printed_chars);
	printf("--------- TEST 31 ---------\n");
	printed_chars = printf("Hello World %s | %d\n", NULL, 42);
	printf("return: %d\n", printed_chars);
	printed_chars = ft_printf("Hello World %s | %d\n", NULL, 42);
	printf("return: %d\n", printed_chars);
	printf("--------- TEST 32 ---------\n");
	printed_chars = printf("Hello World %x | %d\n", NULL, 42);
	printf("return: %d\n", printed_chars);
	printed_chars = ft_printf("Hello World %x | %d\n", NULL, 42);
	printf("return: %d\n", printed_chars);

	char		s[] = "Hello";
	size_t		i;
	size_t		size;
	size_t		size_int;
	size_t		size_hex;
	size_t		size_p;
	size_t		size_strs;
	size_t		size_char;
	size_t		size_u;
	int			ret;

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
		INT_MAX, INT_MIN, UINT_MAX, UINT_MAX + 7,
		LONG_MAX, LONG_MIN, ULONG_MAX, 9223372036854775807LL};
		size_hex = 13;

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
		ret = 0;
		i = 0;
		size = size_hex;
		while (i < size)
		{
			ret = ft_printf("%x", test_hex[i]);
			printf(" (RET = %d) VS printf: ", ret);
			ret = printf("%x", test_hex[i]);
			printf(" (RET = %d)\n", ret);
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

	ret = ft_printf("| %p %p |", 0, 0);
	printf(" => RET: %d", ret);
	printf("\n"); ret = printf("| %p %p |", 0, 0);
	printf(" => RET: %d", ret);
	printf("\n\n");

	return (0);
}*/