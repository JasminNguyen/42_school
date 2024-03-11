/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:37:50 by jasnguye          #+#    #+#             */
/*   Updated: 2024/03/11 14:39:40 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rev_rotate(t_list **stack)
{
	t_list	*last_node;

	if (!(*stack) || !(*stack)->next)
	{
		return ;
	}
	last_node = ft_lstlast(*stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	*stack = last_node;
	last_node->next->prev = last_node;
}

void	rra(t_list **stack_a)
{
	rev_rotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_list **stack_b)
{
	rev_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_printf("rrr\n");
}

void	rev_rot_both(t_list *cheapest_node, t_list **stack_a, t_list **stack_b)
{
	while (cheapest_node != *stack_a && cheapest_node->target_node != *stack_b)
	{
		rrr(stack_a, stack_b);
		current_position(*stack_a);
		current_position(*stack_b);
	}
}
