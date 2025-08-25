/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 03:52:03 by mhashir           #+#    #+#             */
/*   Updated: 2025/08/25 00:19:43 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"

Zombie::Zombie(std::string s) : _name(s)
{
	std::cout << "Zombie object has been framed up " << _name << "\n" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << _name << " Zombie object is taken out of the scene.\n"  << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n" << std::endl;
}
