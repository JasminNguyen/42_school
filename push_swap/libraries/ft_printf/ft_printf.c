/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:00:55 by jasnguye          #+#    #+#             */
/*   Updated: 2024/03/11 15:04:13 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
