/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:04:17 by jasnguye          #+#    #+#             */
/*   Updated: 2024/03/11 14:46:28 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	error_syntax(char *str_i)
{
	if (!(*str_i == '+'
			|| *str_i == '-'
			|| (*str_i >= '0' && *str_i <= '9')))
		return (1);
	if ((*str_i == '+'
			|| *str_i == '-')
		&& !(str_i[1] >= '0' && str_i[1] <= '9'))
		return (1);
	while (*++str_i)
	{
		if (!(*str_i >= '0' && *str_i <= '9'))
			return (1);
	}
	return (0);
}

int	error_duplicate(t_list *stack_a, int nbr)
{
	if (!stack_a)
	{
		return (0);
	}
	while (stack_a)
	{
		if (stack_a->content == nbr)
		{
			return (1);
		}
		stack_a = stack_a->next;
	}
	return (0);
}

bool	stack_is_sorted(t_list *stack_a)
{
	if (!stack_a)
	{
		return (1);
	}
	while (stack_a->next != NULL)
	{
		if (stack_a->content > stack_a->next->content)
		{
			return (false);
		}
		stack_a = stack_a->next;
	}
	return (true);
}
