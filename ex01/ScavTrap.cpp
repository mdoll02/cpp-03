/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:23:42 by mdoll             #+#    #+#             */
/*   Updated: 2023/07/20 11:07:31 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap() {
	this->_dmg = 20;
	this->_energy = 50;
	this->_hp = 100;
	std::cout << "Default ScavTrap created" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
	this->_dmg = 20;
	this->_energy = 50;
	this->_hp = 100;
	std::cout << "ScavTrap " << name << " created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other.getName()) {
	this->_hp = other.getHp();
	this->_energy = other.getEnergy();
	this->_dmg = other.getDmg();
	std::cout << "New copy of ScavTrap " << other._name << " created" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << " destroyed" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	this->_name = other.getName();
	this->_energy = other.getEnergy();
	this->_hp = other.getHp();
	this->_dmg = other.getDmg();
	return *this;
}

void ScavTrap::attack(const std::string &target) {
	if (getEnergy() == 0) {
		std::cout << "ScavTrap " << getName() << " cant attack. He has no energy" << std::endl;
		return ;
	}
	_setEnergy(getEnergy() - 1);
	std::cout << "ScavTrap " << getName() << " attacks ";
	std::cout << target << " causing " << getDmg() << " damage " << std::endl;
}

void ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << getName() << " has entered Gate keeper mode!" << std::endl;
}
