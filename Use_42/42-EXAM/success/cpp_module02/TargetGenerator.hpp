#pragma once
#include <string>
#include <map>
#include "ATarget.hpp"
class TargetGenerator{
    private:
        TargetGenerator(const TargetGenerator&);
        TargetGenerator &operator=(const TargetGenerator&);
        std::map<std::string,ATarget *> book;
    public:
        TargetGenerator();
        ~TargetGenerator();
        void learnTargetType(ATarget*);
        void forgetTargetType(std::string const &);
        ATarget* createTarget(std::string const &);
};