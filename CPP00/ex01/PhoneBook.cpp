/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:13:59 by jasnguye          #+#    #+#             */
/*   Updated: 2024/11/14 19:20:36 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

// Constructor for PhoneBook
PhoneBook::PhoneBook() : index(0) {} // Initializes the index to 0




int numerical(std::string input)
{
	int i = 0;
	while(input[i] != '\0')
	{
		if(!(input[i] >= 48 && input[i] <= 57))
		{
			return -1;
		}
		i++;
	}
	return 0;
}
void PhoneBook::addContact()
{
	Contact newContact;
	std::string input;

	//do I need cin.ignore() here to clear the buffer in case of an int?

	std::cout << "First name: ";
	getline(std::cin, input);
	if(input.empty())
	{
		std::cout << "Error: First name cannot be empty!" << std::endl;
	}
	newContact.set_first_name(input);


	std::cout << "Last name: ";
	getline(std::cin, input);
	if(input.empty())
	{
		std::cout << "Error: Last name cannot be empty!" << std::endl;
	}
	newContact.set_last_name(input);


	std::cout << "Nickname: ";
	getline(std::cin, input);
	if(input.empty())
	{
		std::cout << "Error: Nickname cannot be empty!" << std::endl;
	}
	newContact.set_nickname(input);


	std::cout << "Phone number: ";
	getline(std::cin, input);
	if(input.empty())
	{
		std::cout << "Error: Phone number cannot be empty!" << std::endl;
	}
	if(numerical(input) != 0)
	{
		std::cout << "Error: Only numerical input!" << std::endl;
		return ;
	}
	newContact.set_phone_number(input);


	std::cout << "Darkest secret: ";
	getline(std::cin, input);
	if(input.empty())
	{
		std::cout << "Error: Darkest secret cannot be empty!" << std::endl;
	}
	newContact.set_darkest_secret(input);


//access the phonebook
// Store the contact in it at the current index, cycling back to 0 if max is reached
	_contacts[index] = newContact;
	index = (index /*+1*/) % 8; // Wraps around to replace the oldest contact after 8 entries //modified!!
}



void PhoneBook::displayContacts() const
{

	std::cout << "    index|   first name|   last name|   nickname|   phone number|   darkest secret|" << std::endl;
	std::cout << "-----------------------------------------------------------------------------------" << std::endl;
	int i = 0;
	while(i < 8)
	{
		std::cout << index << "|"<< _contacts[i].get_first_name() << std::endl;
		
		i++;
	}
	
}