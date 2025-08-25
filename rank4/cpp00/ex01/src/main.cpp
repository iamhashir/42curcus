/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 20:46:49 by mhashir           #+#    #+#             */
/*   Updated: 2025/08/22 05:20:14 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"


 
int main(void)
{
	PhoneBook phonebook;
	bool run = true;
	std::string command;

	phonebook.show_instruction();
	std::cout << "$> ";

	while (run && std::getline(std::cin, command))
	{
		if (std::cin.eof())
		{
			std::cout << "You pressed ^D. Exiting phonebook now." << std::endl;
			exit(0);
		}
		else if (command == "ADD")
		{
			phonebook.set_information();
		}
		else if (command == "SEARCH")
		{
			phonebook.get_information();
		}
		else if (command == "EXIT")
		{
			std::cout << "Good Bye." << std::endl;
			run = false;
			continue;
		}

		command.clear();
		phonebook.show_instruction();
		std::cout << "$> ";
	}

	if (run)
	{
		std::cout << "You pressed ^D, exiting now." << std::endl;
		std::cout << "Good Bye." << std::endl;
	}

	return 0;
}


