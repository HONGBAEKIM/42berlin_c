
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

//Class ScavTrap inherit ClapTrap
class ScavTrap : public ClapTrap
{
    private:
        
    public:
        //Default constructor
        ScavTrap(void);
        //Copy constructor
        ScavTrap(const ScavTrap &_ScavTrap);
        //Assignment operator
        ScavTrap& operator=(const ScavTrap &_ScavTrap);
        //Destructor
        ~ScavTrap(void);

        //Constructor for name
        ScavTrap(std::string name);
        
        void attack(const std::string& target);
        void guardGate(void);
};

#endif
