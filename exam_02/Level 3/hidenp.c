/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:27:03 by jasnguye          #+#    #+#             */
/*   Updated: 2024/01/17 15:27:24 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
void hidenp(char *s1, char *s2)
{
        int i = 0;
        int j = 0;

        while (s1[i] != '\0' && s2[j] != '\0')
        {
                if(s1[i] == s2[j])
                {
                        i++;
                }
                j++;
        }

        if(s1[i] == '\0')
        {
                write(1, "1", 1);
        }
        else 
        {
                write(1, "0", 1);
        }
}
int main(int argc, char *argv[])
{
        if(argc == 3)
        {
                hidenp(argv[1], argv[2]);
        }
        write(1, "\n", 1);
}

