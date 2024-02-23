/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:17:45 by jasnguye          #+#    #+#             */
/*   Updated: 2024/02/23 15:05:10 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
		if (!(check_valid_argument(temp[i]))) //checks every number in the array
		{
			free_errors(stack_a); //this array has to be freed with a loop
		}
		if (check_doubles(stack_a, ft_atoi(temp[i]))) 
		{
			free_errors(stack_a);
			free_temp(temp);
		}
		new = ft_lstnew(ft_atoi(temp[i])); //neu schreiben (doubly linked list)
		ft_lstadd_back(&stack_a, new); // neu schreiben
		i++;
	}
	free_temp(temp);
	return (stack_a);
}

t_list	*parse_arguments_to_stack(t_list *stack_a, int argc, char *argv[])
{
	t_list	*new;
	int		i;

	if (argc > 1)
	{
		i = 1;
		new = NULL; // right placement?
		while (argv[i])
		{
			if (!(check_valid_argument(argv[i]))) //checks every argument
			{
				free_errors(stack_a);
			}
			if (check_doubles(stack_a, ft_atoi(argv[i])))
			{
				free_errors(stack_a);
			}
			new = ft_lstnew(ft_atoi(argv[i])); 
			ft_lstadd_back(&stack_a, new); 
			i++;
		}
	}
	return (stack_a);
}
