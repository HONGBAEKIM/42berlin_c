#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

#include <string>
#include <iostream>
#include <map>

#include "ASpell.hpp"



class SpellBook
{
    private:
        SpellBook(SpellBook const &src);
        SpellBook &operator=(SpellBook const &src);
        std::map < std::string, ASpell * > _SpellBook;

    public:
        SpellBook();
        ~SpellBook();
        
        void learnSpell(ASpell*);
        void forgetSpell(std::string const &);
        ASpell* createSpell(std::string const &);
};

#endif
