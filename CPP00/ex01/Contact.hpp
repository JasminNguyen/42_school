/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:01:18 by jasnguye          #+#    #+#             */
/*   Updated: 2024/11/13 18:21:43 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>

class Contact
{
	private:
	
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _darkest_secret;

	public:
	void set_first_name(std::string _first_name);
	void set_last_name(std::string _last_name);
	void set_nickname(std::string _nickname);
	void set_phone(std::string _phone_number);
	void set_darkest_secret(std::string _darkest_secret);

};

#endif