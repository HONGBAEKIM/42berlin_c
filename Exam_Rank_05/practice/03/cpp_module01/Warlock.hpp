#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>
# include <string>
# include <map>
# include "ASpell.hpp"
# include "ATarget.hpp"



class Warlock
{
    private:
        std::string _name;
        std::string _title;
        
        Warlock();
        Warlock(Warlock const &_Warlock);
        Warlock &operator=(Warlock const &_Warlock);
        
        //map will store <std::string, ASpell *>
                   //type std::string
        //valuse are pointer to objects of type ASpell
        
        //_SpellBook is name of the map variable.
        std::map < std::string, ASpell * > _SpellBook;


    public:
        Warlock(std::string const &name, std::string const &title);
        ~Warlock();

        std::string const &getName() const;
        std::string const &getTitle() const;

        void setTitle(std::string const &title);
        void introduce() const;
        void learnSpell(ASpell *spell);
        void forgetSpell(std::string SpellName);
        void launchSpell(std::string SpellName, ATarget const &target);

};

#endif
