/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:00:55 by jasnguye          #+#    #+#             */
/*   Updated: 2024/02/15 11:37:23 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_s(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += print_string(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += print_digit((long)va_arg(ap, int), 10, 0);
	else if (specifier == 'x')
		count += print_digit((long)va_arg(ap, unsigned int), 16, 0);
	else if (specifier == 'X')
		count += print_digit((long)va_arg(ap, unsigned int), 16, 1);
	else if (specifier == 'p')
		count += print_ox(ap);
	else if (specifier == 'u')
		count += print_digit((long)va_arg(ap, unsigned int), 10, 0);
	else 
		count += write (1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(ap, s);
	if (!s) 
		return (-1);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			count += print_s(s[i], ap);
		}
		else
			count += write(1, &s[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}

int	check(int c, char *str, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (str[i] == c)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
/*
int main(int argc, char *argv[])
{
        int i = 0;
        int j = 0;
        int k = 0;

        if (argc == 3)
        {
                while(argv[1][i] != '\0')
                {
                        i++;
                }
                while(argv[2][j] != '\0')
                {
                        argv[1][i] = argv[2][j];
                        i++;
                        j++;
                }
                argv[1][i] = '\0';
                i--;
                while (k <= i)
                {
                        if (check(argv[1][k], argv[1], k) == 1)
                        {
                                write (1, &argv[1][k], 1);
                        }
                        k++;
                }
        }
        write (1, "\n", 1);
}
   */
/*int	main(void)
{
	ft_printf("Hello, %s!\n", "John");
	printf("Hello, %s!\n", "John");
	ft_printf("%c\n", 'a');
	printf("%c\n", 'a');
	ft_printf("%d\n", -123456);
	printf("%d\n", -123456);
	ft_printf("%x\n", 42);
	printf("%x\n", 42);
	ft_printf("%X\n", 42);
	printf("%X\n", 42);
	ft_printf("%p\n", (void *) 1234);
	printf("%p\n", (void *) 1234);
	ft_printf("%%\n");
	printf("%%\n");
	ft_printf("%u\n", 122);
	printf("%u\n", 122);
}*/
