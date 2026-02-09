#pragma once
#include <iostream>
#include <map>
class ASpell;
class ATarget;
class Warlock{
    private:
        std::string name;
        std::string title;
        Warlock();
        Warlock &operator=(const Warlock &);
        Warlock(const Warlock &);
        std::map<std::string,ASpell *> book;
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