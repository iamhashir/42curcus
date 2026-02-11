#include "ATarget.hpp"
#include "ASpell.hpp"
ATarget::ATarget(){}
ATarget::ATarget(const std::string &type):type(type){}
ATarget::~ATarget(){}
ATarget::ATarget(const ATarget &spell):type(spell.type){}
ATarget &ATarget::operator=(const ATarget &other){
    if(this != &other){
        this->type = other.type;
    }

    return *this;
}
void ATarget::getHitBySpell(const ASpell &spell)const{
    std::cout<<getType()<<" has been "<<spell.getEffects()<<"!"<<std::endl;
}

const std::string &ATarget::getType()const{return this->type;}
