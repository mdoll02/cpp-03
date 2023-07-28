/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:27:45 by mdoll             #+#    #+#             */
/*   Updated: 2023/07/19 11:39:49 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

// ------------------------------ Constructor ------------------------------

ClapTrap::ClapTrap() : _name("default"), _hp(10), _energy(10), _dmg(0) {
	std::cout << "Default ClapTrap created" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hp(10), _energy(10), _dmg(0) {
	std::cout << "ClapTrap " << name << " created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name), _hp(other._hp), _energy(other._energy), _dmg(other._dmg) {
	std::cout << "New copy of ClapTrap " << other._name << " created" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " destroyed" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	this->_name = other._name;
	this->_energy = other._energy;
	this->_hp = other._hp;
	this->_dmg = other._dmg;
	return *this;
}

// ------------------------------ Getter and Setter ------------------------------

int ClapTrap::getHp() const { return _hp; }

int ClapTrap::getEnergy() const { return _energy; }

int ClapTrap::getDmg() const { return _dmg; }

std::string ClapTrap::getName() const { return _name; }

void ClapTrap::_setHp(int newHp) {
	if (newHp >= 0)
		_hp = newHp;
	else
		_hp = 0;
}

void ClapTrap::_setEnergy(int newEnergy) {
	if (newEnergy >= 0)
		_energy = newEnergy;
	else
		_energy = 0;
}

// ------------------------------ Other member functions ------------------------------

void ClapTrap::attack(const std::string &target) {
	if (getEnergy() == 0) {
		std::cout << "ClapTrap " << getName() << " cant attack. He has no energy" << std::endl;
		return ;
	}
	_setEnergy(getEnergy() - 1);
	std::cout << "ClapTrap " << getName() << " attacks ";
	std::cout << target << " causing " << getDmg() << " damage " << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (getHp() == 0 && amount != 0)
		std::cout << "ClapTrap " << getName() << " is already at 0 hp" << std::endl;
	else {
		_setHp(getHp() - amount);
		std::cout << "ClapTrap " << getName() << " has taken ";
		std::cout << amount << " damage" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (getEnergy() - amount < 0)
		std::cout << std::cout << "ClapTrap " << getName() << " is too exhausted" << std::endl;
	_setEnergy(getEnergy() - amount);
	_setHp(getHp() + amount);
	std::cout << "ClapTrap " << getName() << " has repaired himself. He now has ";
	std::cout << getHp() << " hp" << std::endl;
}
