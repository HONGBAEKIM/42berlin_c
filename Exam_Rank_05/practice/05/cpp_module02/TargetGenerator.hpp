#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

#include <string>
#include <iostream>
#include <map>

#include "ATarget.hpp"



class TargetGenerator
{
    private:
        TargetGenerator(TargetGenerator const &src);
        TargetGenerator &operator=(TargetGenerator const &src);
        std::map < std::string, ATarget * > _target;

    public:
        TargetGenerator();
        ~TargetGenerator();
        
        void learnTargetType(ATarget*);
        void forgetTargetType(std::string const &);
        ATarget* createTarget(std::string const &);
};

#endif
