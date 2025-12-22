#pragma once
#include <string>
#include <map>
#include "ASpell.hpp"
class SpellBook{
    private:
        SpellBook(const SpellBook&);
        SpellBook &operator=(const SpellBook&);
        std::map<std::string,ASpell *> book;
    public:
        SpellBook();
        ~SpellBook();
        void learnSpell(ASpell*);
        void forgetSpell(std::string const &);
        ASpell* createSpell(std::string const &);
};