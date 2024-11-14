/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:33:47 by jasnguye          #+#    #+#             */
/*   Updated: 2024/11/14 18:01:50 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "PhoneBook.hpp"


int main()
{
	
	PhoneBook phonebook; // declare an instance outside of the loop to only create ONE!
	while(1)
	{

	
		std::cout << "Please enter one of the following commands: ADD, SEARCH or EXIT" << std::endl;	
		
		
		std::string command;

		getline(std::cin, command);
		if(command == "ADD")
		{
			phonebook.addContact();
		}
		else if(command == "SEARCH")
		{
			phonebook.displayContacts();
		}
		else if(command == "EXIT")
		{
			std::cout << "I am exiting the program." << std::endl;
			break;
		}
		else
		{
			std::cout << "Not a valid command. Try again!" << std::endl;
		}
	}
}
