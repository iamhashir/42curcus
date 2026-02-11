#pragma once
#include <iostream>
class ASpell;
class ATarget{

    protected:
        std::string type;
    private:

    public:
        ATarget();
        ATarget(const std::string &);
        ATarget(const ATarget &);
        ATarget&operator=(const ATarget &);
        virtual ~ATarget();
        const std::string &getType()const;
        virtual ATarget *clone() const = 0;
        void getHitBySpell(const ASpell &)const;
};