/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 20:46:49 by mhashir           #+#    #+#             */
/*   Updated: 2025/08/22 06:47:32 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::_fields_name[5] =
{
    "First Name",
    "Last Name",
    "Nickname",
    "Phone Number",
    "Darkest Secret"
};

Contact::Contact()
{
    for (int i = FirstName; i <= DarkestSecret; i++)
        this->_informations[i] = std::string();
}

Contact::~Contact()
{
}

bool Contact::set_contact()
{
    for (int i = FirstName; i <= DarkestSecret; i++)
    {
        std::cout << "Please enter the " << Contact::_fields_name[i] << ": ";
        while (!(std::getline(std::cin, this->_informations[i])) ||
               this->_informations[i].length() == 0)
        {
            if (std::cin.eof())
            {
                std::cout << "You pressed ^D. Exiting phonebook now." << std::endl;
                std::exit(0);
            }
            else if (this->_informations[i].length() == 0)
            {
                this->_informations[i].clear();
                std::cout << "Empty input not allowed. Please try again." << std::endl;
                std::cout << "Please enter the " << Contact::_fields_name[i] << ": ";
            }
        }
    }
    std::cout << "Contact added successfully." << std::endl;
    return true;
}

void Contact::get_contact(int index) const
{
    std::cout << "|" << std::setw(9) << index << "|";
    for (int i = FirstName; i <= NickName; i++)
    {
        if (this->_informations[i].length() > 9)
            std::cout << this->_informations[i].substr(0, 9) << ".|";
        else
            std::cout << std::setw(9) << this->_informations[i] << "|";
    }
    std::cout << std::endl;
}

std::string Contact::get_field(int field) const {
    return this->_informations[field];
}