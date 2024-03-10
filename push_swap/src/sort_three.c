/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:10:49 by jasnguye          #+#    #+#             */
/*   Updated: 2024/03/10 15:44:25 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*find_max(t_list *stack_a)
{
	long	current_max; //To store the biggest value so far
	t_list	*max_node; //To store a pointer that points to the biggest number

	if (!stack_a)
		return (NULL);
	current_max = LONG_MIN; //Assign to the biggest value so far, the max long integer
	while (stack_a != NULL) //Loop until the end of the stack_a is reached
	{
		if (stack_a->content > current_max) //Check if the current node value is bigger than the biggest so far
		{
			current_max = stack_a->content; //If so, update the biggest number so far
			max_node = stack_a; //Set the pointer to point to the node with the biggest number so far
		}
		stack_a = stack_a->next; //Move to the next node for processing
	}
	return (max_node);
}

void	sort_three(t_list **stack_a)
{
	t_list	*biggest_nbr;

	biggest_nbr = find_max(*stack_a);
	if (biggest_nbr == *stack_a)// biggest nbr is on the top
	{
		ra(stack_a/* , false */);
	}
	else if ((*stack_a)->next == biggest_nbr) //biggest nbr is in the middle
	{
		rra(stack_a/* , false */);
	}
	if ((*stack_a)->content > (*stack_a)->next->content) //now the biggest nbr is on the bottom, we just have to check wheter the first two are in the right order
	{
		sa(stack_a/* , false */);
	}
}
