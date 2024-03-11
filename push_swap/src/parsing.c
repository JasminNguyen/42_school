/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:17:45 by jasnguye          #+#    #+#             */
/*   Updated: 2024/03/11 14:48:14 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stack(t_list *stack_a)
{
	t_list	*current;

	current = stack_a;
	if (stack_a == NULL)
	{
		ft_printf("Stack is empty\n");
	}
	ft_printf("Stack contents:\n");
	while (current != NULL)
	{
		ft_printf("%d\n", current->content);
		current = current->next;
	}
}

static void	append_node(t_list **stack_a, int nbr)
{
	t_list	*new;
	t_list	*last_node;

	if (!stack_a)
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
	if (!(*stack_a))
	{
		*stack_a = new;
		new->prev = NULL;
	}
	else
	{
		last_node = ft_lstlast(*stack_a);
		last_node->next = new;
		new->prev = last_node;
	}
}

void	check_for_duplicates(t_list *stack_a, int nbr, int argc, char **argv)
{
	if (error_duplicate(stack_a, (int)nbr))
	{
		if (argc == 2)
			free_array(argv);
		free_errors(&stack_a);
	}
}

void	init_stack_a(t_list **stack_a, char *argv[], int argc)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
		{
			if (argc == 2)
				free_array(argv);
			free_errors(stack_a);
		}
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
		{
			if (argc == 2)
				free_array(argv);
			free_errors(stack_a);
		}
		check_for_duplicates(*stack_a, (int)nbr, argc, argv);
		append_node(stack_a, (int)nbr);
		i++;
	}
}
