/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:27:45 by mdoll             #+#    #+#             */
/*   Updated: 2023/07/19 11:28:07 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

class ClapTrap {
public:
    // Default constructor
	ClapTrap();

	// Constructor with name attribute
	ClapTrap(const std::string &name);

    // Destructor
   ~ClapTrap();

    // Copy constructor
   ClapTrap(const ClapTrap& other);

    // Copy assignment operator
   ClapTrap& operator=(const ClapTrap& other);

   virtual void attack(const std::string &target);
   virtual void takeDamage(unsigned int amount);
   virtual void beRepaired(unsigned int amount);

	int getHp() const;
	int getEnergy() const;
	int getDmg() const;
	std::string getName() const;

protected:

	void _setHp(int newHp);
	void _setEnergy(int newEnergy);
	std::string _name;
	int _hp;
	int _energy;
	int _dmg;
};

#endif