
#include "FragTrap.hpp"

//Default constructor called
FragTrap::FragTrap(void) 
{
    std::cout << "FragTrap_Default constructor called" << '\n';
    this->_name = "FragTrap_default constructor";
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

//Copy constructor called
FragTrap::FragTrap(const FragTrap &_FragTrap)
{
    std::cout << "FragTrap_Copy constructor called" << '\n';
    (*this) = _FragTrap;
}

//Overloaded assignment operator called
FragTrap& FragTrap::operator=(const FragTrap &_FragTrap)
{
    if (this != &_FragTrap)
    {
        //copy data from _FragTrap
        this->_name = _FragTrap._name;
        this->_hitPoints = _FragTrap._hitPoints;
        this->_energyPoints = _FragTrap._energyPoints;
        this->_attackDamage = _FragTrap._attackDamage;
        std::cout << "FragTrap_Assignment operator " \
            << this->_name << " has been created" << '\n';
    }
    //return a reference to the current object
    return (*this);
}

//Destructor called
FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap_Destructor " << this->_name << '\n';
}

//Constructor for name
FragTrap::FragTrap(std::string name)
{
    std::cout << "FragTrap_Constructor " << name << '\n';
    this->_name = name;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}


void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap_highFivesGuys" << this->_name << '\n';
}
