/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:10:49 by jasnguye          #+#    #+#             */
/*   Updated: 2024/03/11 13:59:54 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*find_max(t_list *stack_a)
{
	long	current_max;
	t_list	*max_node;

	if (!stack_a)
		return (NULL);
	current_max = LONG_MIN;
	while (stack_a != NULL)
	{
		if (stack_a->content > current_max)
		{
			current_max = stack_a->content;
			max_node = stack_a;
		}
		stack_a = stack_a->next;
	}
	return (max_node);
}

void	sort_three(t_list **stack_a)
{
	t_list	*biggest_nbr;

	biggest_nbr = find_max(*stack_a);
	if (biggest_nbr == *stack_a)
	{
		ra(stack_a);
	}
	else if ((*stack_a)->next == biggest_nbr)
	{
		rra(stack_a);
	}
	if ((*stack_a)->content > (*stack_a)->next->content) 
	{
		sa(stack_a);
	}
}
