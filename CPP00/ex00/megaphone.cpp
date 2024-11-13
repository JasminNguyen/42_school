/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:45:47 by jasnguye          #+#    #+#             */
/*   Updated: 2024/11/12 12:50:28 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		std::cout << "\n";
	}
	else
	{
		char *string = argv[1];
		int i = 1;
		while(i < argc)
		{
			int j = 0;
			while(argv[i][j] != '\0')
			{
	
				std::cout << (char)toupper(argv[i][j]);
				j++;
			}
			i++;
		}
		
		std::cout << "\n";
	}

	

}