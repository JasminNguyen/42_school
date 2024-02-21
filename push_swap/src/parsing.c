/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:17:45 by jasnguye          #+#    #+#             */
/*   Updated: 2024/02/20 18:14:18 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*parse_string(char *argv[], t_list *stack_a)
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
		if (check_doubles(stack_a, ft_atoi(temp[i]))) // how can we check for doubles here if there is nothing in stack yet?
		{
			free_errors(stack_a);
			free_temp(temp); // is this for every char that I turn into an int?
		}
		new = ft_lstnew(ft_atoi(temp[i])); //neu schreiben (doubly linked list)
		ft_lstadd_back(&stack_a, new); // neu schreiben
		i++;
	}
	free_temp(temp);
	return(stack_a);
}