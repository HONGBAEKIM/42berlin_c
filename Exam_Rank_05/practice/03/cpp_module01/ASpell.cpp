#include "ASpell.hpp"

ASpell::ASpell(std::string name, std::string effects)
{
    this->_name = name;
    this->_effects = effects;
}

ASpell::~ASpell()
{

}

ASpell::ASpell(ASpell const &_ASpell)
{
    *this = _ASpell;
}

ASpell &ASpell::operator=(ASpell const &_ASpell)
{
    this->_name = _ASpell.getName();
    this->_effects = _ASpell.getEffects();
    return (*this);
}

std::string ASpell::getName() const
{
    return (this->_name);
}

std::string ASpell::getEffects() const
{
    return (this->_effects);
}

void ASpell::launch(ATarget const &target) const
{
    target.getHitBySpell(*this);
}


/* 

void ASpell::setTitle(std::string const &_title)
{
    this->_title = _title;
}

void ASpell::introduce() const
{
    std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!\n";
}


void ASpell::learnSpell(ASpell *spell)
{
    if (spell)
        if (_SpellBook.find(spell->getName()) == _SpellBook.end())
            _SpellBook[spell->getName()] = spell->clone();
}

void ASpell::forgetSpell(std::string SpellName)
{
    if (_SpellBook.find(SpellName) != _SpellBook.end())
        _SpellBook.erase(_SpellBook.find(SpellName));
}

void ASpell::launchSpell(std::string SpellName, ATarget const &target)
{
    if (_SpellBook.find(SpellName) != _SpellBook.end())
        _SpellBook[SpellName]->launch(target);
}
 */
