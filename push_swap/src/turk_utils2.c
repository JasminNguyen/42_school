/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:42:07 by jasnguye          #+#    #+#             */
/*   Updated: 2024/03/11 14:48:42 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	current_position(t_list *stack)
{
	int	i;
	int	median;

	i = 0;
	median = ft_lstsize(stack) / 2;
	if (!stack)
	{
		return ;
	}
	while (stack != NULL)
	{
		stack->index = i;
		if (i <= median)
		{
			stack->above_median = true;
		}
		else
		{
			stack->above_median = false;
		}
		stack = stack->next;
		i++;
	}
}

void	set_cheapest_bool(t_list *stack)
{
	long	current_cheapest;
	t_list	*cheapest_node;
	t_list	*head;

	head = stack;
	current_cheapest = LONG_MAX;
	while (stack != NULL)
	{
		if (stack->push_cost < current_cheapest)
		{
			current_cheapest = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
	while (head != NULL)
	{
		if (head != cheapest_node)
		{
			head->cheapest = false;
		}
		head = head->next;
	}
}

t_list	*find_min(t_list *stack)
{
	t_list	*min_node;
	long	current_min;

	if (!stack)
		return (NULL);
	current_min = LONG_MAX;
	while (stack != NULL)
	{
		if (stack->content < current_min)
		{
			current_min = stack->content;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_list	*find_cheapest(t_list *stack)
{
	if (!stack)
	{
		return (NULL);
	}
	while (stack != NULL)
	{
		if (stack->cheapest == true)
		{
			return (stack);
		}
		stack = stack->next;
	}
	return (NULL);
}

void	move_min_on_top(t_list **stack_a)
{
	t_list	*smallest_value;

	smallest_value = find_min(*stack_a);
	if (smallest_value == *stack_a)
	{
		return ;
	}
	while (smallest_value != *stack_a)
	{
		if (smallest_value->above_median == true)
		{
			ra(stack_a);
		}
		else
		{
			rra(stack_a);
		}
	}
}
