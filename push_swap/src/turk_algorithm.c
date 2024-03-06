/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:43:05 by jasnguye          #+#    #+#             */
/*   Updated: 2024/03/06 18:19:16 by jasnguye         ###   ########.fr       */
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
/* 
void	find_target_node_for_a(t_list *stack_a, t_list *stack_b) //my version//not sure if it works correctly
{
	long	current_best_target;
	t_list	*current_stack_b;

	current_stack_b = stack_b;
	while (stack_a != NULL)
	{
		current_best_target = LONG_MIN;
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
} */

void	cost_analysis_for_a(t_list *stack_a, t_list *stack_b) //my version//to be tested //probably correct
{
	int	stack_a_len;
	int	stack_b_len;

	stack_a_len = ft_lstsize(stack_a);
	stack_b_len = ft_lstsize(stack_b);

	while (stack_a != NULL)
	{
		if (stack_a->above_median == true)
		{
			stack_a->push_cost = stack_a->index;
		}
		else
		{
			stack_a->push_cost = stack_a_len - stack_a->index;
		}
		if (stack_a->target_node->above_median == true)
		{
			stack_a->push_cost = stack_a->push_cost + stack_a->target_node->index;
		}
		else
		{
			stack_a->push_cost = stack_a->push_cost + (stack_b_len - stack_a->target_node->index);
		}
		stack_a = stack_a->next;
	}
}

///////////////////////////

void	find_target_node_for_a(t_list *stack_a, t_list *stack_b)
{
	t_list	*current_b;
	t_list	*target_node;
	long			best_match_index;

	while (stack_a)
	{
		best_match_index = LONG_MIN;
		current_b = stack_b;
		while (current_b)
		{
			if (current_b->content < stack_a->content
				&& current_b->content > best_match_index)
			{
				best_match_index = current_b->content;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			stack_a->target_node = find_max(stack_b);
		else
			stack_a->target_node = target_node;
		stack_a = stack_a->next;
	}
} 
/*
void	cost_analysis_for_a(t_list *stack_a, t_list *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstsize(stack_a);
	len_b = ft_lstsize(stack_b);
	while (stack_a)
	{
		stack_a->push_cost = stack_a->index;
		if (!(stack_a->above_median))
			stack_a->push_cost = len_a - (stack_a->index);
		if (stack_a->target_node->above_median)
			stack_a->push_cost += stack_a->target_node->index;
		else
			stack_a->push_cost += len_b - (stack_a->target_node->index);
		stack_a = stack_a->next;
	}
} 

*/
///////////////////

void	set_cheapest_bool(t_list *stack)
{
	long	current_cheapest;
	t_list	*cheapest_node;

	current_cheapest = LONG_MAX;
	while (stack != NULL)
	{
		if (stack->push_cost < current_cheapest)
		{
			current_cheapest = stack->push_cost;
			cheapest_node = stack; //cheapest_node points to the cheapest node so far
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	prep_stack_a_for_push(t_list *stack_a, t_list *stack_b)
{
	
	current_position(stack_a);
	current_position(stack_b);
	find_target_node_for_a(stack_a, stack_b);///
	cost_analysis_for_a(stack_a, stack_b);//probably correct
	set_cheapest_bool(stack_a);
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

void	rotation_for_both(t_list *cheapest_node, t_list **stack_a, t_list **stack_b)
{
	while (cheapest_node != *stack_a && cheapest_node->target_node != *stack_b)
	{
		rr(stack_a, stack_b);
		current_position(*stack_a);
		current_position(*stack_b);
	}
}

void	reverse_rotation_for_both(t_list *cheapest_node, t_list **stack_a, t_list **stack_b)
{
	while (cheapest_node != *stack_a && cheapest_node->target_node != *stack_b)
	{
		rrr(stack_a, stack_b);
		current_position(*stack_a);
		current_position(*stack_b);
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
void	push_a_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest_node;

	cheapest_node = find_cheapest(*stack_a);
	if (cheapest_node->above_median == true && cheapest_node->target_node->above_median == true)
	{
		rotation_for_both(cheapest_node, stack_a, stack_b);
	}
	else if (cheapest_node->above_median == false && cheapest_node->target_node->above_median == false)
	{
		reverse_rotation_for_both(cheapest_node, stack_a, stack_b);
	}
	prepare_stack_a_for_push(cheapest_node, stack_a);
	prepare_stack_b_for_push(cheapest_node->target_node, stack_b);
	pb(stack_b, stack_a);
}

void	turk_algorithm(t_list **stack_a, t_list **stack_b)
{
	int	stack_a_length;

	stack_a_length = ft_lstsize(*stack_a);
	if (stack_a_length > 3 && !(stack_is_sorted(*stack_a)))
	{
		pb(stack_b, stack_a);
		stack_a_length--; //
	}
	if (stack_a_length > 3 && !(stack_is_sorted(*stack_a)))
	{
		pb(stack_b, stack_a); 
		stack_a_length--;//
	}
	ft_printf("stack b: ");
	print_stack(*stack_b);
	while (stack_a_length > 3)
	{
		
		prep_stack_a_for_push(*stack_a, *stack_b);
		push_a_to_b(stack_a, stack_b);
		stack_a_length--;
		
	}ft_printf("stack a: "); print_stack(*stack_a);
	ft_printf("stack b: ");	print_stack(*stack_b);
	sort_three(stack_a);
	ft_printf("sort three\n");
	print_stack(*stack_a);
	while (stack_b != NULL)
	{
		//prepare the stack for push
		//push
	}
	//...
}