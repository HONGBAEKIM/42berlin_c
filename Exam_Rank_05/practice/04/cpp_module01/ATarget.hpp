#ifndef ATARGET_HPP
# define ATARGET_HPP

#include <iostream>
#include <string>
#include "ASpell.hpp"

class ASpell;

class ATarget 
{
    protected:
        std::string _type;
    
    public:
        ATarget(std::string type);
        ATarget(ATarget const &_ATarget);
        ATarget &operator=(ATarget const &_ATarget);
        virtual ~ATarget();
        
        //ATarget(std::string const &name, std::string const &effects);

        std::string getType() const;

        virtual ATarget* clone() const = 0; 
        void getHitBySpell(ASpell const &spell) const;
};


#endif
