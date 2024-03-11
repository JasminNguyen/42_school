/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:57:18 by jasnguye          #+#    #+#             */
/*   Updated: 2024/03/11 13:57:56 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	find_target_node_for_b(t_list *stack_a, t_list *stack_b)
{
	long	current_best_target;
	t_list	*current_stack_a;

	while (stack_b != NULL)
	{
		current_best_target = LONG_MAX;
		current_stack_a = stack_a;
		while (current_stack_a != NULL)
		{
			if (stack_b->content < current_stack_a->content 
				&& current_stack_a->content < current_best_target)
			{
				current_best_target = current_stack_a->content;
				stack_b->target_node = current_stack_a;
			}
			current_stack_a = current_stack_a->next;
		}
		if (current_best_target == LONG_MAX)
		{
			stack_b->target_node = find_min(stack_a);
		}
		stack_b = stack_b->next;
	}
}

void	prepare_stack_a_for_push(t_list *node_to_be_moved, t_list **stack_a)
{
	while (node_to_be_moved != *stack_a)
	{
		if (node_to_be_moved->above_median == true)
		{
			ra(stack_a);
		}
		else
		{
			rra(stack_a);
		}
	}
}
