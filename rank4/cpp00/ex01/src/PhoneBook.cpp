/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 20:46:49 by mhashir           #+#    #+#             */
/*   Updated: 2025/08/22 06:47:37 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_index = 0;
	this->_full = false;
}

PhoneBook::~PhoneBook(void)
{
}

void PhoneBook::set_information(void)
{
	std::string input;

	if (!this->_full)
	{
		std::cout << "This is your contact #" << this->_index + 1 << std::endl;
		if (this->_contacts[this->_index].set_contact())
		{
			if (this->_index == 7)
				this->_full = true;
			else
				this->_index++;
		}
	}
	else
	{
		std::cout << "Your phonebook is full." << std::endl;
		std::cout << "If you add a new contact, the first one will be deleted." << std::endl;
		std::cout << "Press '1' and Enter to proceed, or anything else to go back." << std::endl;
		std::cout << "Your choice: ";

		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << "You pressed ^D. Exiting phonebook now." << std::endl;
			std::exit(0);
		}
		else if (input == "1")
		{
			for (int i = 1; i < 8; i++)
				this->_contacts[i - 1] = this->_contacts[i];

			std::cout << "This is your contact #8" << std::endl;
			this->_contacts[this->_index].set_contact();
		}
		else
		{
			std::cout << "Back to main menu without deleting or adding." << std::endl;
		}
	}
}

void PhoneBook::display_all_contacts() const
{
    std::cout << "+----------+----------+----------+----------+" << std::endl;
    std::cout << "|     Index|First Name| Last Name| Nickname |" << std::endl;
    std::cout << "+----------+----------+----------+----------+" << std::endl;
    for (int i = 0; i < (this->_full ? 8 : this->_index); i++)
        this->_contacts[i].get_contact(i + 1);
    std::cout << "+----------+----------+----------+----------+" << std::endl;
}

void PhoneBook::get_information() const
{
	if (this->_index == 0)
	{
		std::cout << "Please add at least one contact before searching." << std::endl;
	}
	else
	{
		std::string input;
		int index;

		// Display all contacts first
		display_all_contacts();

		std::cout << "Enter contact index (1 to 8, or 0 to quit): ";

		while (!(std::getline(std::cin, input)) ||
			   input.length() > 1 ||
			   input < "0" || input > "8" ||
			   (std::atoi(input.c_str()) - 1 >= this->_index && !this->_full))
		{
			if (std::cin.eof())
			{
				std::cout << "You pressed ^D. Exiting phonebook now." << std::endl;
				std::exit(0);
			}
			else if (input.length() > 1 || input < "0" || input > "8")
			{
				std::cin.clear();
				std::cout << "Only digits from 1 to 8 are allowed (or 0 to quit)." << std::endl;
				std::cout << "Enter contact index: ";
			}
			else if (std::atoi(input.c_str()) - 1 >= this->_index && !this->_full)
			{
				std::cout << "You only have " << this->_index << " contacts saved." << std::endl;
				std::cin.clear();
				std::cout << "Enter contact index: ";
			}
		}

		index = std::atoi(input.c_str());
		if (index > 0)
		{
			std::cout << "\nContact information:\n" << std::endl;
			std::cout << "First Name:     " << this->_contacts[index - 1].get_field(0) << std::endl;
			std::cout << "Last Name:      " << this->_contacts[index - 1].get_field(1) << std::endl;
			std::cout << "Nickname:       " << this->_contacts[index - 1].get_field(2) << std::endl;
			std::cout << "Phone Number:   " << this->_contacts[index - 1].get_field(3) << std::endl;
			std::cout << "Darkest Secret: " << this->_contacts[index - 1].get_field(4) << std::endl;
			std::cout << std::endl;
		}
		else
		{
			std::cout << "Exiting search mode." << std::endl;
		}
	}
}

void PhoneBook::show_instruction(void)
{
	std::cout << "Enter your command [ADD, SEARCH, EXIT]:" << std::endl;
}
