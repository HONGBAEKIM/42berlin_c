
#include "ClapTrap.hpp"

int main( void ) 
{
    /*
	ClapTrap b("Eren");
	ClapTrap c("Colossal titan");
	b.attack("Colossal titan");
	c.takeDamage(4);
	b.beRepaired(3);
	b.attack("Colossal titan");
	c.takeDamage(6);
	b.attack("Colossal titan");
	c.takeDamage(10);
	return (0);
	

	ScavTrap a("Nezuko");
	ScavTrap b( a);
	ScavTrap c("Scary-demon");
	a.attack("scary-demon");
	c.takeDamage(20);
	c.attack("Nezuko");
	a.takeDamage(20);
	a.beRepaired(11);
	a.guardGate();
	a.attack("scary-demon");
	c.takeDamage(10000);
	c.attack("Nezuko");
	return (0);
*/

	FragTrap a("Eren");
	FragTrap b(a);
	FragTrap c("titan");
	a.attack("titan");
	c.takeDamage(20);
	c.beRepaired(30);
	c.attack("Eren");
	a.takeDamage(1000);
	a.beRepaired(2);
	a.highFivesGuys();
	return (0);
}
