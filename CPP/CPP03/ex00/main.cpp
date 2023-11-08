
#include "ClapTrap.hpp"

int main( void ) 
{
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
}
