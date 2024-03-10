/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:35:14 by jasnguye          #+#    #+#             */
/*   Updated: 2024/03/10 15:20:27 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (argc == 2)
		init_stack_a(&stack_a, argv, argc);
	else
		init_stack_a(&stack_a, argv + 1, argc);
	if (!stack_is_sorted(stack_a))
	{
		if (ft_lstsize(stack_a) == 2)
			sa(&stack_a);
		else if (ft_lstsize(stack_a) == 3)
			sort_three(&stack_a);
		else
			turk_algorithm(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	if (argc == 2)
		free_array(argv);
}
