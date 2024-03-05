/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:09:51 by jasnguye          #+#    #+#             */
/*   Updated: 2024/03/05 11:59:28 by jasnguye         ###   ########.fr       */
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
		current	= temp;
	}
	*stack_a = NULL;
	write(2, "Error!\n", 7);
	exit(1); //makes the program stop executing the remaining code (afer it finds an error)
}

/* 
void	free_temp(char **temp)
{
	int	i;

	i = 0;
	while (temp[i] != NULL)
	{
		free(temp[i]);
		i++;
	}
	free(temp);
} */

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
		current	= temp;
	}
	*stack_a = NULL;

}

void	free_array(char **argv)
{
	int i = 0;
	while(argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}
