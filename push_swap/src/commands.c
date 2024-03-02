/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:37:50 by jasnguye          #+#    #+#             */
/*   Updated: 2024/03/02 15:43:49 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_list **stack_a/* , bool boolean */)
{
	/* if(!boolean)
	{

	} */
	ft_printf("sa\n"); // do I need a bool here?
	if (!(*stack_a) || !(*stack_a)->next)
	{
		return ;
	}
	*stack_a = (*stack_a)->next; //swaps
	(*stack_a)->prev->prev = *stack_a; //makes the prev pointer of the node before the new head (that is going to be moved behind the new head) point to the new head
	(*stack_a)->prev->next = (*stack_a)->next; //makes the next pointer of the node before the new head (that is going to be moved behind the new head) point whatever is after the new head
	if ((*stack_a)->next)// checks if there is something after the new head
	{
		(*stack_a)->next->prev = (*stack_a)->prev;//if yes, makes the prev pointer of the node after the new head point to whatever is before the new head(because it's going to be moved at the second position)
	}
	(*stack_a)->next = (*stack_a)->prev;// let's the next pointer of the new head point to the old head
}	

void	sb(t_list **stack_b)
{
	ft_printf("sb\n");
	//do I need a bool here?
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
	//do I need a bool here?
	sa(stack_a);
	sb(stack_b);
	ft_printf("ss\n");
}

void	push(t_list **destination, t_list **source)
{
	t_list *node_to_push; //temp variable for the node to push

	if (!(*source)) //checks whether there is somethin in the source stack
	{
		return ; 
	}
	node_to_push = *source; //puts the first node of the source stack in the temp variable
	*source = (*source)->next; //updates the src stack so that it starts with the second node
	if(*source) //checks wheter the second node exists 
	{
		(*source)->prev = NULL; //sets it's prev pointer to NULL (because it's now the head)
	}
	node_to_push->prev = NULL; //set's the prev pointer of the node to push to NULL
	if (!(*destination)) //checks if the destination stack is empty
	{
		*destination = node_to_push; //assigns the node to push as the head of the destination stack
		node_to_push->next = NULL;//sets the next pointer of the head to NULL, since there it's the only node in the stack
	}
	else // if the destination stack is not empty
	{
		node_to_push->next = *destination; //lets the next pointer of the node to push point to the old head of the destination stack
		node_to_push->next->prev = node_to_push; //lets prev pointer of the old head of the destination stack point to the node to push (new head)
		*destination = node_to_push;//the node to push becomes the head of the destination stack
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


void	ra(t_list **stack_a)
{
	t_list *last_node;

	last_node = ft_lstlast(stack_a);
	if(!(*stack_a) || !(*stack_a)->next) //checks if the stack is empty or if there is only one node
	{
		return ;
	}
	

	*stack_a = (*stack_a)->next;
	(*stack_a)->prev->prev = ft_lstlast(stack_a);
	(*stack_a)->prev->next = NULL;
	(*stack_a)->prev = NULL;


}

void	rb(t_list **stack_b)
{

}

void rr(t_list **stack_a, t_list **stack_b)
{
	 
}



