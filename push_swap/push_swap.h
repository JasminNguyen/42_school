/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:12:58 by jasnguye          #+#    #+#             */
/*   Updated: 2024/03/11 14:27:46 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_list
{
	int						content;
	int						index;
	int						push_cost;
	bool					above_median;
	bool					cheapest;
	struct s_list			*target_node;
	struct s_list			*next;
	struct s_list			*prev;
}	t_list;

//libft functions
char	**ft_split(char *s, char c);//review this one again!!!
long	ft_atol(const char *str);
size_t	ft_strlen(const char *s);
int		ft_printf(const char *s, ...);
int		ft_isdigit(int nbr);
void	*ft_calloc(size_t count, size_t size);

//list functions
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);

//parsing functions
void	init_stack_a(t_list **stack_a, char *argv[], int argc);
void	print_stack(t_list *stack_a);

//check functions
int		error_syntax(char *nbr);
int		error_duplicate(t_list *stack_a, int nbr);
bool	stack_is_sorted(t_list *stack_a);

//sorting functions
void	sort_three(t_list **stack_a);
void	turk_algorithm(t_list **stack_a, t_list **stack_b);

//utils functions
t_list	*find_max(t_list *stack_a);
void	current_position(t_list *stack);
void	find_target_node_for_a(t_list *stack_a, t_list *stack_b);
void	cost_analysis_for_a(t_list *stack_a, t_list *stack_b);
void	set_cheapest_bool(t_list *stack);
void	find_target_node_for_b(t_list *stack_a, t_list *stack_b);
void	move_min_on_top(t_list **stack_a);
t_list	*find_min(t_list *stack);
t_list	*find_cheapest(t_list *stack);
void	prepare_stack_a_for_push(t_list *node_to_be_moved, t_list **stack_a);
void	prepare_stack_b_for_push(t_list *node_to_be_moved, t_list **stack_b);
void	find_target_node_for_b(t_list *stack_a, t_list *stack_b);

//commands
void	push(t_list **destination, t_list **source);
void	sa(t_list **stack_a);
void	sb(t_list **stack_a);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_b, t_list **stack_a);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	rev_rotate(t_list **stack);
void	rotate(t_list **stack);
void	rev_rot_both(t_list *cheapest_node, t_list **stack_a, t_list **stack_b);
void	rot_both(t_list *cheapest_node, t_list **stack_a, t_list **stack_b);
//free functions
void	free_errors(t_list **lst);
void	free_stack(t_list **stack_a);
void	free_array(char **argv);

#endif