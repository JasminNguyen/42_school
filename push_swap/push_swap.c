/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:35:14 by jasnguye          #+#    #+#             */
/*   Updated: 2024/03/07 16:16:53 by jasnguye         ###   ########.fr       */
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
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' '); //review this one!!
	}
	init_stack_a(&stack_a, argv + 1, argc);
	if (!stack_is_sorted(stack_a))
	{
		//printf("stack needs to be sorted\n");
		if (ft_lstsize(stack_a) == 2)
		{
			//printf("switch the two\n");
			//printf("last element: %d\n", ft_lstlast(stack_a)->content);
			sa(&stack_a/* , false */); //-> simple swap of two // do I need a bool here?
			print_stack(stack_a);
		}
		
		else if (ft_lstsize(stack_a) == 3)
		{
			//printf("sort the three\n");
			//printf("last element: %d\n", ft_lstlast(stack_a)->content);
			sort_three(&stack_a);
			print_stack(stack_a);
		}
		else
		{
			//printf("sort bigger stack\n");
			//printf("last element: %d\n", ft_lstlast(stack_a)->content);
			turk_algorithm(&stack_a, &stack_b);
		}
	}
	else
		printf("stack is sorted!");
	free_stack(&stack_a);
	if (argc == 2)
	free_array(argv);

}
