#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title)
{
    this->_name = name;
    this->_title = title;
    std::cout << this->_name << ": This looks like another boring day.\n";
}

//has to be changed
Warlock::~Warlock()
{
    std::cout << this->_name << ": My job here is done!\n";
    for (std::map<std::string, ASpell*>::iterator it = _SpellBook.begin(); it != _SpellBook.end(); ++it)
        delete (it->second);
    _SpellBook.clear();
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

void Warlock::learnSpell(ASpell* spell)
{
    if (spell)
        if (_SpellBook.find(spell->getName()) == _SpellBook.end())
            _SpellBook[spell->getName()] = spell->clone();
}

void Warlock::forgetSpell(std::string SpellName)
{
    if (_SpellBook.find(SpellName) != _SpellBook.end())
        _SpellBook.erase(_SpellBook.find(SpellName));
}

void Warlock::launchSpell(std::string SpellName, ATarget const &target)
{
    if (_SpellBook.find(SpellName) != _SpellBook.end())
        _SpellBook[SpellName]->launch(target);
}

/* 
add 3 functions

void Warlock::learnSpell(ASpell* spell);
void Warlock::forgetSpell(std::string Spellname)
void Warlock::launchSpell(std::string Spellname, ATarget const &target)
*/



