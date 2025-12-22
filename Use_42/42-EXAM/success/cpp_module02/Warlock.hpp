#pragma once
#include <iostream>
 class ASpell;
class ATarget;

#include "SpellBook.hpp"

class Warlock{
    private:
        std::string name;
        std::string title;
        Warlock();
        Warlock &operator=(const Warlock &);
        Warlock(const Warlock &);
        SpellBook spellbook;
     public:
        Warlock(const std::string &name,const std::string title);
        ~Warlock();
        const std::string &getName()const;
        const std::string &getTitle()const;
        void setTitle(const std::string &);
        void introduce()const;
        void learnSpell(ASpell *);
        void forgetSpell(const std::string &name);
        void launchSpell(const std::string &name,ATarget &);
};