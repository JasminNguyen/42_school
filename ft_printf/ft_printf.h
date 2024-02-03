/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:53:32 by jasnguye          #+#    #+#             */
/*   Updated: 2023/12/07 11:11:24 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int	ft_printf(const char *s, ...);
int	print_s(char specifier, va_list ap);
int	print_char(int c);
int	print_string(char *s);
int	print_digit(long nbr, int base, int boolean);
int	print_ox(va_list arguments);
int	print_pointer(unsigned long long int nbr); 

#endif