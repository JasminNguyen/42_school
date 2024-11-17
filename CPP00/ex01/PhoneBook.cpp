/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:13:59 by jasnguye          #+#    #+#             */
/*   Updated: 2024/11/17 12:47:34 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <limits>
#include "PhoneBook.hpp"

// Constructor for PhoneBook
PhoneBook::PhoneBook() : index(0) {} // Initializes the index to 0

int numerical(std::string input)
{
	int i = 0;
	while(input[i] != '\0')
	{
		if(!(isdigit(input[i])))
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

	std::cout << "First name: ";
	getline(std::cin, input);
	if(input.empty())
	{
		std::cout << std::endl << "Error: First name cannot be empty!" << std::endl;
		return;
	}
	newContact.set_first_name(input);


	std::cout << "Last name: ";
	getline(std::cin, input);
	if(input.empty())
	{
		std::cout << std::endl << "Error: Last name cannot be empty!" << std::endl;
		return;
	}
	newContact.set_last_name(input);


	std::cout << "Nickname: ";
	getline(std::cin, input);
	if(input.empty())
	{
		std::cout << std::endl << "Error: Nickname cannot be empty!" << std::endl;
		return;
	}
	newContact.set_nickname(input);


	std::cout << "Phone number: ";
	getline(std::cin, input);
	if(input.empty())
	{
		std::cout << std::endl << "Error: Phone number cannot be empty!" << std::endl;
		return;
	}
	if(numerical(input) != 0)
	{
		std::cout << std::endl << "Error: Only numerical input!" << std::endl;
		return ;
	}
	newContact.set_phone_number(input);


	std::cout << "Darkest secret: ";
	getline(std::cin, input);
	if(input.empty())
	{
		std::cout << std::endl << "Error: Darkest secret cannot be empty!" << std::endl;
		return;
	}
	newContact.set_darkest_secret(input);


	//access the phonebook
	// Store the contact in it at the current index, cycling back to 0 if max is reached
	_contacts[index] = newContact;
	std::cout << std::endl << "New Contact added!" << std::endl;
	// basically increments the index while also ensuring that it wraps around when we reach 8 entries
	index = (index + 1) % 8; 
}



void PhoneBook::displayContacts() const
{

	std::cout << std::setw(10) << std::right << "index|" << std::setw(10) << std::right << "first name|" << std::setw(10) << std::right << "last name|" << std::setw(10) << std::right << "nickname|" << std::setw(10) << std::right << "phone number|" << std::setw(10) << std::right << "darkest secret|" << std::endl;
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	int i = 0;
	std::string input_first_name;
	std::string input_last_name;
	std::string input_nickname;
	std::string input_phone_number;
	std::string input_darkest_secret;


	while(i < 8)
	{
   		// Start with the original values for the contact
   		input_first_name = _contacts[i].get_first_name();
    	input_last_name = _contacts[i].get_last_name();
		input_nickname = _contacts[i].get_nickname();
		input_phone_number = _contacts[i].get_phone_number();
		input_darkest_secret = _contacts[i].get_darkest_secret();

       // Truncate if the length exceeds 10 characters		
	   if(_contacts[i].get_first_name().length() > 10)
		{
			input_first_name = _contacts[i].get_first_name().substr(0,9) + ".";
		}
		if(_contacts[i].get_last_name().length() > 10)
		{
			input_last_name = _contacts[i].get_last_name().substr(0,9) + ".";
		}
		if(_contacts[i].get_nickname().length() > 10)
		{
			input_nickname = _contacts[i].get_nickname().substr(0,9) + ".";
		}
		if(_contacts[i].get_phone_number().length() > 10)
		{
			input_phone_number = _contacts[i].get_phone_number().substr(0,9) + ".";
		}
		if(_contacts[i].get_darkest_secret().length() > 10)
		{
			input_darkest_secret = _contacts[i].get_darkest_secret().substr(0,9) + ".";
		}

		std::cout << std::setw(10) << std::right << i << "|"
		<< std::setw(10) << std::right << input_first_name << "|" 
		<< std::setw(10) << std::right << input_last_name << "|" 
		<< std::setw(10) << std::right << input_nickname << "|" 
		<< std::setw(10) << std::right << input_phone_number << "|" 
		<< std::setw(10) << std::right << input_darkest_secret << "|" 
		<< std::endl;
		i++;
	}
	std::cout << "Which contact are you looking for? Please provide the index (0-7): ";

	int input_index;

	if(!(std::cin >> input_index) || input_index < 0 || input_index > 7) //handle non-numeric input and wrong index
	{
		std::cin.clear();
  		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
    	std::cout << std::endl << "Error: Invalid index. Try again!" << std::endl;

		return; //go back to main loop
	}
	else if(_contacts[input_index].get_first_name().empty()) //handle empty contacts
	{
		std::cout << std::endl <<  "Error: No contact exists at this index. Try again!" << std::endl;
		std::cin.ignore();
		return; //go back to main loop
	}
	else
	{
		std::cout << "First name: " << _contacts[input_index].get_first_name() << std::endl;
		std::cout << "last name: " << _contacts[input_index].get_last_name() << std::endl;
		std::cout << "Nickname: " << _contacts[input_index].get_nickname() << std::endl;
		std::cout << "Phone number: " << _contacts[input_index].get_phone_number() << std::endl;
		std::cout << "Darkest secret: " << _contacts[input_index].get_darkest_secret() << std::endl;
	}

	// Clear the buffer for further input
	std::cin.ignore();
	
}