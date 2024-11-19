/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:31:43 by jasnguye          #+#    #+#             */
/*   Updated: 2024/11/19 17:52:30 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) // Constructor
{
	_name = name;
}


void Zombie::announce (void) 
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	
}