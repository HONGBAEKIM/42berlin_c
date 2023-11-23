#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <string>
#include <iostream>
#include <map>

#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock
{
    private:
        std::string _name;
        std::string _title;

        Warlock();
        Warlock(Warlock const &_Warlock);
        Warlock &operator=(Warlock const &_Warlock);
        std::map < std::string, ASpell * > _SpellBook;


    public:
        Warlock(std::string const &name, std::string const &title);
        virtual ~Warlock();
        std::string const &getName () const;
        std::string const &getTitle () const;

        void setTitle(std::string const &title);
        void introduce() const;

        void learnSpell(ASpell *spell);
        void forgetSpell(std::string const SpellName);
        void launchSpell(std::string const SpellName, ATarget const &target);


};

#endif
