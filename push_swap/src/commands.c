/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:37:50 by jasnguye          #+#    #+#             */
/*   Updated: 2024/03/04 15:30:00 by jasnguye         ###   ########.fr       */
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
	t_list	*last_node;

	if(!(*stack_a) || !(*stack_a)->next) //checks if the stack is empty or if there is only one node
	{
		return ;
	}
	last_node = ft_lstlast(*stack_a);
	last_node->next = *stack_a; //next pointer of last node points to the head (that is going to be moved at to end of the stack)
	*stack_a = (*stack_a)->next;
	(*stack_a)->prev = NULL;
	last_node->next->prev = last_node; // why not (*stack_a)->prev->prev = last_node;
	last_node->next->next = NULL; // why not (*stack_a)->prev->next = NULL;
	ft_printf("ra\n");
}

void	rb(t_list **stack_b)
{
	t_list	*last_node;

	if (!(*stack_b) || !(*stack_b)->next)
	{
		return ;
	}
	last_node = ft_lstlast(*stack_b);
	last_node->next = *stack_b; 
	*stack_b = (*stack_b)->next;
	(*stack_b)->prev = NULL;
	last_node->next->prev = last_node; 
	last_node->next->next = NULL;
	ft_printf("rb\n");
}

void rr(t_list **stack_a, t_list **stack_b)
{
	ft_printf("rr\n");
	ra (stack_a);
	rb (stack_b);
}

void	rra(t_list **stack_a)
{
	t_list	*last_node;

	if (!(*stack_a) || !(*stack_a)->next)
	{
		return ;
	}
	last_node = ft_lstlast(*stack_a); //find last node
	last_node->prev->next = NULL; // disconnects the last node from the list
	last_node->next = *stack_a; //lets the next pointer of the last node point to the head of the stack
	last_node->prev = NULL; //lets the prev pointer of the new head point to NULL
	*stack_a = last_node; //sets the last node as the head of the stack
	last_node->next->prev = last_node; //lets the prev pointer of the old head point to the new head
	ft_printf("rra\n");
}

void	rrb(t_list **stack_b)
{
	t_list	*last_node;

	if (!(*stack_b) || !(*stack_b)->next)
	{
		return ;
	}
	last_node = ft_lstlast(*stack_b);
	last_node->prev->next = NULL;
	last_node->next = *stack_b;
	last_node->prev = NULL;
	*stack_b = last_node;
	last_node->next->prev = last_node;
	ft_printf("rrb\n");
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	ft_printf("rrr\n");
}


