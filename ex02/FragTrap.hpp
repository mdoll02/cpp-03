/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 10:19:59 by mdoll             #+#    #+#             */
/*   Updated: 2023/07/21 10:20:04 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
public:
    // Default constructor
    FragTrap();

	FragTrap(const std::string &name);

    // Destructor
    ~FragTrap();

    // Copy constructor
    FragTrap(const FragTrap& other);

    // Copy assignment operator
    FragTrap& operator=(const FragTrap& other);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void highFivesGuys(void);

private:
    // Private members and methods
};



#endif
