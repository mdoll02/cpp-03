/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 10:19:59 by mdoll             #+#    #+#             */
/*   Updated: 2023/07/21 10:20:53 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap() {
	this->_dmg = 30;
	this->_energy = 100;
	this->_hp = 100;
	std::cout << "Default FragTrap created" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	this->_dmg = 30;
	this->_energy = 100;
	this->_hp = 100;
	std::cout << "FragTrap " << getName() << " created" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other.getName()) {
	this->_hp = other.getHp();
	this->_energy = other.getEnergy();
	this->_dmg = other.getDmg();
	std::cout << "New copy of FragTrap " << this->getName() << " created" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << getName() << " destroyed" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	this->_name = other.getName();
	this->_dmg = other.getDmg();
	this->_hp = other.getHp();
	this->_energy = other.getEnergy();
	return *this;
}

void FragTrap::highFivesGuys(void) {
	if (getHp() == 0) {
		std::cout << "FragTrap " << getName() << " is too dead to high five!" << std::endl;
	} else if (getEnergy() == 0) {
		std::cout << "FragTrap " << getName() << " is too exhausted to high five!" << std::endl;
	}
	else {
		_setEnergy(getEnergy() - 1);
		std::cout << "FragTrap " << getName() << " is asking for a high five!" << std::endl;
	}
}

void FragTrap::attack(const std::string &target) {
	if (getEnergy() == 0) {
		std::cout << "FragTrap " << getName() << " cant attack. He has no energy" << std::endl;
		return ;
	}
	_setEnergy(getEnergy() - 1);
	std::cout << "FragTrap " << getName() << " attacks ";
	std::cout << target << " causing " << getDmg() << " damage " << std::endl;
}

void FragTrap::takeDamage(unsigned int amount) {
	if (getHp() == 0 && amount != 0)
		std::cout << "FragTrap " << getName() << " is already at 0 hp" << std::endl;
	else {
		_setHp(getHp() - amount);
		std::cout << "FragTrap " << getName() << " has taken ";
		std::cout << amount << " damage" << std::endl;
	}
}

void FragTrap::beRepaired(unsigned int amount) {
	if (static_cast<int>(getEnergy() - amount) < 0)
		std::cout << "FragTrap " << getName() << " is too exhausted" << std::endl;
	_setEnergy(getEnergy() - amount);
	_setHp(getHp() + amount);
	std::cout << "FragTrap " << getName() << " has repaired himself. He now has ";
	std::cout << getHp() << " hp" << std::endl;
}