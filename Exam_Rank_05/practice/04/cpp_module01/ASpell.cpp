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



