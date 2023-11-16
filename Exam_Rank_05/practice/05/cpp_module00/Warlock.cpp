#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title)
{
	this->_name = name;
	this->_title = title;
	std::cout << this->_name << ": This looks like another boring day.\n";
}

Warlock::~Warlock()
{
	std::cout << this->_name << ": My job here is done!\n";
}

Warlock::Warlock(Warlock const &_Warlock)
{
	*this = _Warlock;
}

Warlock &Warlock::operator=(Warlock const &_Warlock)
{
	this->_name = _Warlock._name;
	this->_title = _Warlock._title;
	return (*this);
}
		
std::string const &Warlock::getName() const
{
	return (this->_name);
}


std::string const &Warlock::getTitle() const	
{
	return (this->_title);
}		

void Warlock::setTitle(std::string const &title)
{
	this->_title = title;
}

void Warlock::introduce() const
{
	std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!\n";
}
	









		
