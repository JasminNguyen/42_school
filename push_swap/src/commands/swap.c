/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:30:48 by jasnguye          #+#    #+#             */
/*   Updated: 2024/03/11 14:53:30 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sa(t_list **stack_a)
{
	ft_printf("sa\n");
	if (!(*stack_a) || !(*stack_a)->next)
	{
		return ;
	}
	*stack_a = (*stack_a)->next;
	(*stack_a)->prev->prev = *stack_a;
	(*stack_a)->prev->next = (*stack_a)->next;
	if ((*stack_a)->next)
	{
		(*stack_a)->next->prev = (*stack_a)->prev;
	}
	(*stack_a)->next = (*stack_a)->prev;
}

void	sb(t_list **stack_b)
{
	ft_printf("sb\n");
	if (!(*stack_b) || !(*stack_b)->next)
	{
		return ;
	}
	*stack_b = (*stack_b)->next;
	(*stack_b)->prev->prev = *stack_b; 
	(*stack_b)->prev->next = (*stack_b)->next; 
	if ((*stack_b)->next)
	{
		(*stack_b)->next->prev = (*stack_b)->prev;
	}
	(*stack_b)->next = (*stack_b)->prev;
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_printf("ss\n");
}
