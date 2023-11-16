#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>
# include <string>

class Warlock
{
    private:
        std::string _name;
        std::string _title;
        
        Warlock();
        Warlock(Warlock const &_Warlock);
        Warlock &operator=(Warlock const &_Warlock);

    public:
        Warlock(std::string const &_name, std::string const &_title);
        ~Warlock();

        std::string const &getName() const;
        std::string const &getTitle() const;

        void setTitle(std::string const &_title);
        void introduce() const;
};

#endif
