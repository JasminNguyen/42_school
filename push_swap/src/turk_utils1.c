/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:18:34 by jasnguye          #+#    #+#             */
/*   Updated: 2024/03/11 15:26:53 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	find_target_node_for_a(t_list *stack_a, t_list *stack_b)
{
	long	current_best_target;
	t_list	*current_stack_b;

	while (stack_a != NULL)
	{
		current_best_target = LONG_MIN;
		current_stack_b = stack_b;
		while (current_stack_b != NULL)
		{
			if (stack_a->content > current_stack_b->content 
				&& current_stack_b->content > current_best_target)
			{
				current_best_target = current_stack_b->content;
				stack_a->target_node = current_stack_b;
			}
			current_stack_b = current_stack_b->next;
		}
		if (current_best_target == LONG_MIN)
		{
			stack_a->target_node = find_max(stack_b);
		}
		stack_a = stack_a->next;
	}
}

void	cost_analysis_for_a(t_list *stack_a, t_list *stack_b)
{
	int	stack_a_len;
	int	stack_b_len;

	stack_a_len = ft_lstsize(stack_a);
	stack_b_len = ft_lstsize(stack_b);
	while (stack_a != NULL)
	{
		if (stack_a->above_median == true)
			stack_a->push_cost = stack_a->index;
		else
			stack_a->push_cost = stack_a_len - stack_a->index;
		if (stack_a->target_node->above_median == true)
		{
			stack_a->push_cost = stack_a->push_cost 
				+ stack_a->target_node->index;
		}
		else
		{
			stack_a->push_cost = stack_a->push_cost 
				+ (stack_b_len - stack_a->target_node->index);
		}
		stack_a = stack_a->next;
	}
}

void	prepare_stack_b_for_push(t_list *node_to_be_moved, t_list **stack_b)
{
	while (node_to_be_moved != *stack_b)
	{
		if (node_to_be_moved->above_median == true)
		{
			rb(stack_b);
		}
		else
		{
			rrb(stack_b);
		}
	}
}
