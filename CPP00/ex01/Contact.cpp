/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:18:04 by jasnguye          #+#    #+#             */
/*   Updated: 2024/11/14 16:40:58 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"


//Constructor to set default values
Contact::Contact() : _first_name(""), _last_name(""), _nickname(""), _phone_number(""), _darkest_secret("") {}



// Setter for _first_name
void Contact::set_first_name(std::string first_name) {
    _first_name = first_name;
}

// Setter for _last_name
void Contact::set_last_name(std::string last_name) {
    _last_name = last_name;
}

// Setter for _nickname
void Contact::set_nickname(std::string nickname) {
    _nickname = nickname;
}

// Setter for _phone_number
void Contact::set_phone_number(std::string phone_number) {
    _phone_number = phone_number;
}

// Setter for _darkest_secret
void Contact::set_darkest_secret(std::string darkest_secret) {
    _darkest_secret = darkest_secret;
}



////////////


// Getter for _first_name
std::string Contact::get_first_name() const{
    return _first_name;
}

// Getter for _last_name
std::string Contact::get_last_name() const {
    return _last_name;
}

// Getter for _nickname
std::string Contact::get_nickname() const {
    return _nickname;
}

// Getter for _phone_number
std::string Contact::get_phone_number() const {
    return _phone_number;
}

// Getter for _darkest_secret
std::string Contact::get_darkest_secret() const {
    return _darkest_secret;
}

