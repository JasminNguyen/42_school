/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:12:58 by jasnguye          #+#    #+#             */
/*   Updated: 2024/03/10 15:01:07 by jasnguye         ###   ########.fr       */
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
//t_list	*parse_string_to_stack(char *argv[], t_list *stack_a);
//t_list	*parse_arguments_to_stack(t_list *stack_a, int argc, char *argv[]);
void		init_stack_a(t_list **stack_a, char *argv[], int argc);
void		print_stack(t_list *stack_a);

//check functions
int		error_syntax(char *nbr);
int		error_duplicate(t_list *stack_a, int nbr);
bool	stack_is_sorted(t_list *stack_a);

//sorting functions
void	sort_three(t_list **stack_a);
void	turk_algorithm(t_list **stack_a, t_list **stack_b);

//utlils functions
t_list	*find_max(t_list *stack_a);

//commands
void	sa(t_list **stack_a/* , bool boolean */);
void	sb(t_list **stack_a/* , bool boolean */);
void	ss(t_list **stack_a, t_list **stack_b); //do I need a bool here?
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

//free functions
void	free_errors(t_list **lst);
void	free_stack(t_list **stack_a);
void	free_array(char **argv);

//void	free_temp(char **temp);
#endif