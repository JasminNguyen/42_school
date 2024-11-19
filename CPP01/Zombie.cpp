/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:31:43 by jasnguye          #+#    #+#             */
/*   Updated: 2024/11/19 18:08:41 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) // Constructor
{
	_name = name;
}


// Destructor: Prints a message when the zombie is destroyed
Zombie::~Zombie() {
    std::cout << "Zombie " << _name << " destroyed!" << std::endl;
}
void Zombie::announce (void) 
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	
}