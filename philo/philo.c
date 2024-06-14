/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:19:15 by jasnguye          #+#    #+#             */
/*   Updated: 2024/06/04 13:44:36 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int is_numerical(char *argument)
{
    int i = 0;
    while(argument[i] != '\0')
    {
        if(!(argument[i] >= '0' && argument[i] <= '9'))
        {
            return(0);
        }
        i++;
    }
    return (1);
}
void check_greater_zero(char *argument)
{
    int number = ft_atoi(argument);
    if(!(number > 0))
    {
        printf("Error: Input needs to be greater than zero!\n");
    }
    
}
void check_input(char *argument)
{
   if(is_numerical(argument) != 1)
   {
        printf("Error: Invalid input!\n");
   }
}

void error_check(int argc, char *argv[])
{
    if(argc != 5 && argc != 6)
    {
        printf("Error: Invalid number of arguments!\n");
    }
    else 
    {
        int i = 1;
        int j = 1;
        while(i < argc )
        {
            check_input(argv[i]);
            if(j != argc - 1)
            {
                check_greater_zero(argv[j]);
            }
            i++;
            j++;
        }
    }
}
int main(int argc, char *argv[])
{
    error_check(argc, argv);
    initialize_struct(argc, argv);
    return (0);
}