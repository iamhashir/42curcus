/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 00:32:37 by mhashir           #+#    #+#             */
/*   Updated: 2025/08/25 02:45:43 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : _type(type) {}

const std::string& Weapon::getType() const {
    return _type;
}

void Weapon::setType(const std::string& type) {
    _type = type;
}

