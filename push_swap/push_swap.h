/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:12:58 by jasnguye          #+#    #+#             */
/*   Updated: 2024/02/21 11:24:14 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include "../libraries/Libft/libft.h"

typedef struct s_list
{
	int						content;
	int						index;
	int						push_cost;
	bool					above_median;
	bool					cheapest; // vid with woman
	struct s_list	*target_node;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

//parsing functions
t_list	*parse_string(char *argv[], t_list *stack_a);
t_list	*parse_arguments(t_list	*stack_a, int argc, char *argv[]);

//check functions
int		check_valid_argument(char *nbr);
int		check_doubles(t_list *stack_a, int nbr);

#endif