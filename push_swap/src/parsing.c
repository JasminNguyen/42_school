/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:17:45 by jasnguye          #+#    #+#             */
/*   Updated: 2024/03/04 15:42:04 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* 
t_list	*parse_string_to_stack(char *argv[], t_list *stack_a)
{
	t_list	*new;
	char	**temp;
	int		i;

	i = 0;
	temp = argv;
	temp = ft_split(argv[1], ' ');
	while (temp[i])
	{
		if (!(check_valid_argument(temp[i])))
		{
			printf("hello1");
			free_errors(&stack_a);
		}
		if (check_doubles(stack_a, (ft_atoi(temp[i]) || ft_atoi(temp[i]) > INT_MAX) || ft_atoi(temp[i]) < INT_MIN))
		{
			printf("helloo1");
			free_errors(&stack_a);
			free_temp(temp);
		}
		new = ft_lstnew(ft_atoi(temp[i]));	//neu schreiben (doubly linked list)
		ft_lstadd_back(&stack_a, new); // neu schreiben
		i++;
	}
	free_temp(temp);
	print_stack(stack_a);
	return (stack_a);
}

t_list	*parse_arguments_to_stack(t_list *stack_a, int argc, char *argv[])
{
	t_list	*new;
	int		i;

	if (argc > 1)
	{
		i = 1;
		new = NULL;
		while (argv[i])
		{
			if (!(check_valid_argument(argv[i])))
			{
				printf("hello2");
				free_errors(&stack_a);
			}

			if (check_doubles(stack_a, ft_atoi(argv[i]) || ft_atoi(argv[i]) > INT_MAX|| ft_atoi(argv[i]) < INT_MIN))
			{
				free_errors(&stack_a);
				printf("helloo2");
			}
			new = ft_lstnew(ft_atoi(argv[i])); 
			ft_lstadd_back(&stack_a, new); 
			
			i++;
		}
	}
	print_stack(stack_a);
	return (stack_a);
}  */


void	print_stack(t_list *stack_a)
{
	t_list	*current;

	current = stack_a;
	if (stack_a == NULL)
	{
		printf("Stack is empty\n");
	}
	ft_printf("Stack contents:\n");
	while (current != NULL)
	{
		ft_printf("%d\n", (*current).content);
		current = current->next;
	}
}

static void	append_node(t_list **stack_a, int nbr)
{
	t_list	*new;
	t_list	*last_node;

	if (!stack_a) //there is no stack to append to
	{
		return ;
	}
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
	{
		return ;
	}
	new->content = nbr;
	new->next = NULL;
	if (!(*stack_a))//the existing stack is empty
	{
		*stack_a = new;
		new->prev = NULL; //Set the head node's previous pointer to NULL as it's the first node
	}
	else
	{
		last_node = ft_lstlast(*stack_a); // find last node
		last_node->next = new; //let last node point to new node
		new->prev = last_node; // let new node point back to node before
	}
}

void	init_stack_a(t_list **stack_a, char *argv[])
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
		{
			free_errors(stack_a);
		}
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
		{
			free_errors(stack_a);
		}
		if (error_duplicate(*stack_a, (int)nbr)) //or (int)nbr?
		{
			free_errors(stack_a);
		}
		append_node(stack_a, (int)nbr);
		i++;
	}
	print_stack(*stack_a);
}
