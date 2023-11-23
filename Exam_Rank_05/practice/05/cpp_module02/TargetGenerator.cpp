#include "TargetGenerator.hpp"



TargetGenerator::TargetGenerator()
{
}

TargetGenerator::~TargetGenerator()
{
    
    /* for (std::map <std::string, ASpell*>::iterator it = _TargetGenerator.begin(); it != _TargetGenerator.end(); ++it)
        delete (it->second);
    _TargetGenerator.clear(); */
}

TargetGenerator::TargetGenerator(TargetGenerator const &src)
{
    *this = src;
}

TargetGenerator &TargetGenerator::operator=(TargetGenerator const &src)
{
    _target = src._target;
    return (*this);
}


/* 
void learnTargetType(ATarget*);
void forgetTargetType(std::string const &);
ATarget* createTarget(std::string const &); 
*/


void TargetGenerator::learnTargetType(ATarget *target)
{
    if (target)
        _target[target->getType()] = target->clone();
}


void TargetGenerator::forgetTargetType(std::string const &target)
{
    
    if (_target.find(target) != _target.end())
        _target.erase(_target.find(target));
}

ATarget* TargetGenerator::createTarget(std::string const &target)
{
    ATarget* tmp = NULL;
    if (_target.find(target) != _target.end())
        tmp = _target[target];
    return (tmp);
}
