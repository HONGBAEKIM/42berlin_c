#ifndef ATARGET_HPP
# define ATARGET_HPP

#include <string>
#include <iostream>

#include "ASpell.hpp"

class ASpell;

class ATarget
{
    protected:
        std::string _type;


    public:
        ATarget(std::string type);
        virtual ~ATarget();
        ATarget(ATarget const &_ATarget);
        ATarget &operator=(ATarget const &_ATarget);

        std::string getType () const;

        virtual ATarget* clone() const = 0;
        void getHitBySpell(ASpell const &spell) const;

};


#endif
