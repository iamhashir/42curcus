#pragma once
#include <iostream>
class ATarget;
class ASpell{

    protected:
        std::string name;
        std::string effects;
    private:

    public:
        ASpell();
        ASpell(const std::string &,const std::string &);
        ASpell(const ASpell &);
        ASpell&operator=(const ASpell &);
        virtual ~ASpell();
        const std::string &getName()const;
        const std::string &getEffects()const;
        virtual ASpell *clone() const = 0;
        void launch (const ATarget &target)const;

};