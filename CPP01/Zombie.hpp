/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:11:37 by jasnguye          #+#    #+#             */
/*   Updated: 2024/11/19 17:52:08 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	private:

		std::string _name;

	public:
		Zombie(std::string name); //constructor
		//~Zombie(); //do I need this?
		void announce( void );

};

	Zombie* newZombie( std::string name );
	void randomChump( std::string name );
	
#endif