/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:09:51 by jasnguye          #+#    #+#             */
/*   Updated: 2024/02/26 17:35:31 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_errors(t_list **lst)
{
	t_list	*temp;

	if (!lst)
	{
		return ;
	}
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		(*lst)->content = 0;
		free(*lst);
		(*lst) = temp;
	}
	write(2, "Error!\n", 7); // on the standard error?
}


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
}
