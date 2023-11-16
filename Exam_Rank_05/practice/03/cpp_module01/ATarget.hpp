#ifndef ATARGET_HPP
# define ATARGET_HPP

# include <iostream>
# include <string>
# include "ASpell.hpp"

class ASpell;

class ATarget
{
    protected:
        std::string _type;        

    public:
        ATarget(std::string type);
        //ATarget(std::string const &_name, std::string const &_effects);
        //ATarget();
        ATarget(ATarget const &_ATarget);
        ATarget &operator=(ATarget const &_ATarget);
        virtual ~ATarget();

        std::string getType() const;

        virtual ATarget* clone() const = 0;
        void getHitBySpell(ASpell const &spell) const;


};

#endif
