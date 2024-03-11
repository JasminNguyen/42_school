/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:32:34 by jasnguye          #+#    #+#             */
/*   Updated: 2024/03/11 14:54:27 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*last_node;

	if (!(*stack) || !(*stack)->next)
	{
		return ;
	}
	last_node = ft_lstlast(*stack);
	last_node->next = *stack; 
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node; 
	last_node->next->next = NULL;
}

void	ra(t_list **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_list **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}

void	rot_both(t_list *cheapest_node, t_list **stack_a, t_list **stack_b)
{
	while (cheapest_node != *stack_a && cheapest_node->target_node != *stack_b)
	{
		rr(stack_a, stack_b);
		current_position(*stack_a);
		current_position(*stack_b);
	}
}
