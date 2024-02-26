/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:35:14 by jasnguye          #+#    #+#             */
/*   Updated: 2024/02/26 18:17:52 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2)
	{
		stack_a = parse_string_to_stack(argv, stack_a);
	}
	else
	{
		stack_a = parse_arguments_to_stack(stack_a, argc, argv);
	} 
	
	
} */

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
	{
		return (1);
	}
	else if(argc == 2)
	{
		argv = ft_split(argv[1], ' '); //modifiy?
	}
	init_stack_a(&stack_a, argv + 1);
	print_stack(stack_a);
/* 	if(!stack_is_sorted(stack_a))
	{

	} */
}
