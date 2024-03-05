/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:43:05 by jasnguye          #+#    #+#             */
/*   Updated: 2024/03/05 15:28:28 by jasnguye         ###   ########.fr       */
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

void	find_target_node_for_a(t_list *stack_a, t_list *stack_b) //my version//not sure if it works correctly
{
	long	current_best_target;

	while (stack_a != NULL)
	{
		current_best_target = LONG_MIN;
		while (stack_b != NULL)
		{
			if (stack_a->content > stack_b->content 
				&& stack_b->content > current_best_target)
			{
				current_best_target = stack_b->content;
				stack_a->target_node = stack_b;
			}
			stack_b = stack_b->next;
		}
		if (current_best_target == LONG_MIN)
		{
			stack_a->target_node = find_max(stack_b);
		}
		stack_a = stack_a->next;
	}
}
void	cost_analysis_for_a(t_list **stack_a, t_list **stack_b)
{
	
}
void	prep_stack_a_for_push(t_list *stack_a, t_list *stack_b)
{
	current_position(stack_a);
	current_position(stack_b);
	find_target_node_for_a(stack_a, stack_b);
	cost_analysis_for_a(stack_a, stack_b);
	//find_cheapest_in_a(stack_a);

}

void	turk_algorithm(t_list **stack_a, t_list **stack_b)
{
	int	stack_a_length;

	stack_a_length = ft_lstsize(*stack_a);
	if (stack_a_length > 3 && !(stack_is_sorted(*stack_a)))
	{ft_printf("hdk1");
		pb(stack_b, stack_a);
	}
	if (stack_a_length > 3 && !(stack_is_sorted(*stack_a)))
	{ft_printf("hdk");
		pb(stack_b, stack_a); 
	}
	while (stack_a_length != 3)
	{
		prep_stack_a_for_push(*stack_a, *stack_b);
		//push
	}
	sort_three(stack_a);
	while(stack_b != NULL)
	{
		//prepare the stack for push
		//push
	}
	//...
}