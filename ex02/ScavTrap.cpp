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
	this->_is_guard = false;
	std::cout << "Default ScavTrap created" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
	this->_dmg = 20;
	this->_energy = 50;
	this->_hp = 100;
	this->_is_guard = false;
	std::cout << "ScavTrap " << name << " created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other.getName()) {
	this->_hp = other.getHp();
	this->_energy = other.getEnergy();
	this->_dmg = other.getDmg();
	this->_is_guard = other._is_guard;
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
	this->_is_guard = other._is_guard;
	return *this;
}

void ScavTrap::guardGate(void) {
	if (!_is_guard) {
		std::cout << "ScavTrap " << getName() << " has entered Gate keeper mode!" << std::endl;
		_is_guard = true;
	}
	else {
		std::cout << "ScavTrap " << getName() << " had left Gate keeper mode!" << std::endl;
		_is_guard = false;
	}
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

void ScavTrap::takeDamage(unsigned int amount) {
	if (getHp() == 0 && amount != 0)
		std::cout << "ScavTrap " << getName() << " is already at 0 hp" << std::endl;
	else {
		_setHp(getHp() - amount);
		std::cout << "ScavTrap " << getName() << " has taken ";
		std::cout << amount << " damage" << std::endl;
	}
}

void ScavTrap::beRepaired(unsigned int amount) {
	if (static_cast<int>(getEnergy() - amount) < 0)
		std::cout << std::cout << "ScavTrap " << getName() << " is too exhausted" << std::endl;
	_setEnergy(getEnergy() - amount);
	_setHp(getHp() + amount);
	std::cout << "ScavTrap " << getName() << " has repaired himself. He now has ";
	std::cout << getHp() << " hp" << std::endl;
}