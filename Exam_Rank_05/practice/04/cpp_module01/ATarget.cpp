#include "ATarget.hpp"

ATarget::ATarget(std::string type)
{
    this->_type = type;

}

ATarget::~ATarget()
{
   
}

ATarget::ATarget(ATarget const &_ATarget)
{
    *this = _ATarget;
}

ATarget &ATarget::operator=(ATarget const &_ATarget)
{
    this->_type = _ATarget.getType();
    return (*this);
}

std::string ATarget::getType() const
{
    return (this->_type);
}


void ATarget::getHitBySpell(ASpell const &spell) const
{
    std::cout << this->_type << " has been " << spell.getEffects() << "!\n";
}


