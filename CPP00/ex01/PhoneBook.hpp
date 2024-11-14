/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:58:28 by jasnguye          #+#    #+#             */
/*   Updated: 2024/11/14 19:00:41 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <string>
#include "Contact.hpp"

class PhoneBook
{
	private:

		Contact _contacts[8];
		int index;

	public:

		PhoneBook();
		
		
		void addContact(); //method to add a contact
		void displayContacts() const; //method to display contacts
	
};

#endif