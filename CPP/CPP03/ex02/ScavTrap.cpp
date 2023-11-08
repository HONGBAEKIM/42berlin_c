
#include "ScavTrap.hpp"

//Default constructor called
ScavTrap::ScavTrap(void) 
{
    std::cout << "ScanTrap_Default constructor called" << '\n';
    this->_name = "ScanTrap_default constructor";
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

//Copy constructor called
ScavTrap::ScavTrap(const ScavTrap &_ScavTrap)
{
    std::cout << "ScanTrap_Copy constructor called" << '\n';
    (*this) = _ScavTrap;
}

//Overloaded assignment operator called
ScavTrap& ScavTrap::operator=(const ScavTrap &_ScavTrap)
{
    if (this != &_ScavTrap)
    {
        //copy data from _ScavTrap
        this->_name = _ScavTrap._name;
        this->_hitPoints = _ScavTrap._hitPoints;
        this->_energyPoints = _ScavTrap._energyPoints;
        this->_attackDamage = _ScavTrap._attackDamage;
        std::cout << "ScanTrap_A duplicate of " \
            << this->_name << " has been created" << '\n';
    }
    //return a reference to the current object
    return (*this);
}

//Destructor called
ScavTrap::~ScavTrap(void)
{
    std::cout << "ScanTrap_Destructor " << this->_name << '\n';
}

//Constructor for name
ScavTrap::ScavTrap(std::string name)
{
    std::cout << "ScavTrap_Constructor " << name << '\n';
    this->_name = name;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->_hitPoints < 1)
        std::cout << "ScavTrap_ " << this->_name << " can not attack cus Hit points = 0" << '\n';
    if (this->_energyPoints < 1)
        std::cout << "ScavTrap_ " << this->_name << " can not attack cus Energy points = 0" << '\n';
    this->_energyPoints--;
    //ScavTrap <name> attacks <target>, causing <damage> points of damage!
    std::cout << "ScavTrap " << this->_name << " attacks " << target \
                << ", causing " << this->_attackDamage << " points of damage!" << '\n';
    std::cout << this->_name << "'s hit points= " << this->_hitPoints << '\n';
    std::cout << this->_name << "'s energy points= " << this->_energyPoints << '\n';
    std::cout << this->_name << "'s attact damage= " << this->_attackDamage << '\n';
    std::cout << '\n';
}

void ScavTrap::guardGate(void)
{
    std::cout << this->_name << " is now in gate keeper mode." << '\n';
}
