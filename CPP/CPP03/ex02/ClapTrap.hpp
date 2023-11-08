
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    private:
        std::string _name;
        int _hitPoints;
        int _energyPoints;
        int _attackDamage;
        
    public:
        //Default constructor
        ClapTrap(void);
        //Copy constructor
        ClapTrap(const ClapTrap &_ClapTrap);
        ClapTrap(std::string name);
        //Assignment operator
        ClapTrap& operator=(const ClapTrap &_ClapTrap);
        //Destructor
        ~ClapTrap(void);

        std::string getName(void) const;

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif
