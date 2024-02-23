/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:12:58 by jasnguye          #+#    #+#             */
/*   Updated: 2024/02/23 16:56:53 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>

typedef struct s_list
{
	int						content;
	int						index;
	int						push_cost;
	bool					above_median;
	bool					cheapest; // vid with woman
	struct s_list			*target_node;
	struct s_list			*next;
	struct s_list			*prev;
}	t_list;

//libft functions
char	**ft_split(const char *s, char c);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);

//list functions
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);

//parsing functions
t_list	*parse_string_to_stack(char *argv[], t_list *stack_a);
t_list	*parse_arguments_to_stack(t_list *stack_a, int argc, char *argv[]);

//check functions
int		check_valid_argument(char *nbr);
int		check_doubles(t_list *stack_a, int nbr);

#endif