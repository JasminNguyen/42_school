/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:09:51 by jasnguye          #+#    #+#             */
/*   Updated: 2024/03/11 14:47:49 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_errors(t_list **stack_a)
{
	t_list	*temp;
	t_list	*current;

	if (!stack_a)
	{
		return ;
	}
	current = *stack_a;
	while (current != NULL)
	{
		temp = current->next;
		current->content = 0;
		free(current);
		current = temp;
	}
	*stack_a = NULL;
	write(2, "Error!\n", 7);
	exit(1);
}

void	free_stack(t_list **stack_a)
{
	t_list	*temp;
	t_list	*current;

	if (!stack_a)
	{
		return ;
	}
	current = *stack_a;
	while (current != NULL)
	{
		temp = current->next;
		current->content = 0;
		free(current);
		current = temp;
	}
	*stack_a = NULL;
}

void	free_array(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}
