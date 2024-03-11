/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:19:35 by jasnguye          #+#    #+#             */
/*   Updated: 2024/03/11 14:52:18 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	push(t_list **destination, t_list **source)
{
	t_list	*node_to_push;

	if (!(*source))
	{
		return ;
	}
	node_to_push = *source;
	*source = (*source)->next; 
	if (*source)
	{
		(*source)->prev = NULL;
	}
	node_to_push->prev = NULL;
	if (!(*destination))
	{
		*destination = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *destination;
		node_to_push->next->prev = node_to_push;
		*destination = node_to_push;
	}
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	ft_printf("pa\n");
	push(stack_a, stack_b);
}

void	pb(t_list **stack_b, t_list **stack_a)
{
	ft_printf("pb\n");
	push(stack_b, stack_a);
}
