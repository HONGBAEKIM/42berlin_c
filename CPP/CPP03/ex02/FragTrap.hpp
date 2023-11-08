
#ifndef FragTrap_HPP
# define FragTrap_HPP

#include "ClapTrap.hpp"

//Class FragTrap inherit ClapTrap
class FragTrap : public ClapTrap
{
    private:
        
    public:
        //Default constructor
        FragTrap(void);
        //Copy constructor
        FragTrap(const FragTrap &_FragTrap);
        //Assignment operator
        FragTrap& operator=(const FragTrap &_FragTrap);
        //Destructor
        ~FragTrap(void);

        //Constructor for name
        FragTrap(std::string name);
        
        void highFivesGuys(void);
};

#endif
