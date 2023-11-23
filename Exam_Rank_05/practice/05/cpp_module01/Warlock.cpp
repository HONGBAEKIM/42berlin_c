#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title) : _name(name), _title(title)
{
    std::cout << _name << ": This looks like another boring day.\n"; 
}

Warlock::~Warlock()
{
    std::cout << _name << ": My job here is done!\n";   
    for (std::map <std::string, ASpell*>::iterator it = _SpellBook.begin(); it != _SpellBook.end(); ++it)
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

std::string const &Warlock::getName () const
{
    return (_name);
}

std::string const &Warlock::getTitle () const
{
    return (_title);
}

void Warlock::setTitle(std::string const &title)
{
    _title = title;
}

void Warlock::introduce() const
{
    std::cout << _name << ": I am " << _name << ", " << _title << "!\n"; 
}

void Warlock::learnSpell(ASpell *spell)
{
    if (spell)
        if (_SpellBook.find(spell->getName()) == _SpellBook.end())
            _SpellBook[spell->getName()] = spell->clone();
}

void Warlock::forgetSpell(std::string const SpellName)
{
    if (_SpellBook.find(SpellName) != _SpellBook.end())
        _SpellBook.erase(_SpellBook.find(SpellName));
}

void Warlock::launchSpell(std::string const SpellName, ATarget const &target)
{
    if (_SpellBook.find(SpellName) != _SpellBook.end())
        _SpellBook[SpellName] -> launch(target);
}









		
