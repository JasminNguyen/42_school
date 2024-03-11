/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:43:05 by jasnguye          #+#    #+#             */
/*   Updated: 2024/03/11 13:41:06 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	analyse_stack_a_for_push(t_list *stack_a, t_list *stack_b)
{
	current_position(stack_a);
	current_position(stack_b);
	find_target_node_for_a(stack_a, stack_b);
	cost_analysis_for_a(stack_a, stack_b);
	set_cheapest_bool(stack_a);
}

void	analyse_stack_b_for_push(t_list *stack_a, t_list *stack_b)
{
	current_position(stack_a);
	current_position(stack_b);
	find_target_node_for_b(stack_a, stack_b);
}

void	push_a_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest_node;

	cheapest_node = find_cheapest(*stack_a);
	if (cheapest_node->above_median == true 
		&& cheapest_node->target_node->above_median == true)
	{
		rot_both(cheapest_node, stack_a, stack_b);
	}
	else if (cheapest_node->above_median == false 
		&& cheapest_node->target_node->above_median == false)
	{
		rev_rot_both(cheapest_node, stack_a, stack_b);
	}
	prepare_stack_a_for_push(cheapest_node, stack_a);
	prepare_stack_b_for_push(cheapest_node->target_node, stack_b);
	pb(stack_b, stack_a);
}

void	push_b_to_a(t_list **stack_a, t_list **stack_b)
{
	prepare_stack_a_for_push((*stack_b)->target_node, stack_a);
	pa(stack_a, stack_b);
}

void	turk_algorithm(t_list **stack_a, t_list **stack_b)
{
	int	stack_a_length;

	stack_a_length = ft_lstsize(*stack_a);
	if (stack_a_length > 3 && !(stack_is_sorted(*stack_a)))
		pb(stack_b, stack_a);
	if (stack_a_length > 3 && !(stack_is_sorted(*stack_a)))
	{
		pb(stack_b, stack_a); 
		stack_a_length--;
	}
	while (stack_a_length > 3 && !(stack_is_sorted(*stack_a)))
	{
		analyse_stack_a_for_push(*stack_a, *stack_b);
		push_a_to_b(stack_a, stack_b);
		stack_a_length--;
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		analyse_stack_b_for_push(*stack_a, *stack_b);
		push_b_to_a(stack_a, stack_b);
	}
	move_min_on_top(stack_a);
}
