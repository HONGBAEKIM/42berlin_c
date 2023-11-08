
#include "ClapTrap.hpp"

//Default constructor called
ClapTrap::ClapTrap(void) :_hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Default constructor called" << '\n';
}

//Copy constructor called
ClapTrap::ClapTrap(const ClapTrap &_ClapTrap)
{
    std::cout << "Copy constructor called" << '\n';
    (*this) = _ClapTrap;
}

//Copy assignment operator called
ClapTrap& ClapTrap::operator=(const ClapTrap &_ClapTrap)
{
    std::cout << "Copy assignment operator called" << '\n';
    if (this != &_ClapTrap)
    {
        //copy data from _ClapTrap
        this->_name = _ClapTrap._name;
        this->_hitPoints = _ClapTrap._hitPoints;
        this->_energyPoints = _ClapTrap._energyPoints;
        this->_attackDamage = _ClapTrap._attackDamage;
    }
    //return a reference to the current object
    return (*this);
}

//Destructor called
ClapTrap::~ClapTrap(void)
{
    std::cout << "Destructor " << this->getName() << '\n';
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "Constructor " << name << '\n';
    this->_name = name;
    this->_hitPoints = 10;
    this->_energyPoints = 10;
    this->_attackDamage = 0;
}

std::string	ClapTrap::getName(void) const
{
    return (this->_name);
}

void ClapTrap::attack(const std::string& target)
{
    if (this->_hitPoints < 1)
        std::cout << "Can not attack cus Hit points = 0" << '\n';
    if (this->_energyPoints < 1)
        std::cout << "Can not attack cus Energy points = 0" << '\n';
    this->_energyPoints--;
    //ClapTrap <name> attacks <target>, causing <damage> points of damage!
    std::cout << "ClapTrap " << this->_name << " attacks " << target \
                << ", causing " << this->_attackDamage << " points of damage!" << '\n';
    std::cout << this->_name << "'s hit points= " << this->_hitPoints << '\n';
    std::cout << this->_name << "'s energy points= " << this->_energyPoints << '\n';
    std::cout << this->_name << "'s attact damage= " << this->_attackDamage << '\n';
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoints < 1)
        std::cout << "Can not take damage cus Hit points = 0" << '\n';
    if (this->_energyPoints < 1)
        std::cout << "Can not take damage cus Energy points = 0" << '\n';
    this->_hitPoints = this->_hitPoints - amount;
    //ClapTrap <name> attacks <target>, causing <damage> points of damage!
    std::cout << "ClapTrap " << this->_name << " take damage " \
                << ", causing " << amount << " points of damage!" << '\n';
    std::cout << this->_name << "'s hit points= " << this->_hitPoints << '\n';
    std::cout << this->_name << "'s energy points= " << this->_energyPoints << '\n';
    std::cout << this->_name << "'s attact damage= " << this->_attackDamage << '\n';
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_hitPoints < 1)
        std::cout << "Can not repair cus Hit points = 0" << '\n';
    if (this->_energyPoints < 1)
        std::cout << "Can not repair cus Energy points = 0" << '\n';
    this->_hitPoints = this->_hitPoints + amount;
    this->_energyPoints--;
    //ClapTrap <name> attacks <target>, causing <damage> points of damage!
    std::cout << "ClapTrap " << this->_name << " is repairing and got " \
                << amount << " points back!" << '\n';
    std::cout << this->_name << "'s hit points= " << this->_hitPoints << '\n';
    std::cout << this->_name << "'s energy points= " << this->_energyPoints << '\n';
    std::cout << this->_name << "'s attact damage= " << this->_attackDamage << '\n';
}
