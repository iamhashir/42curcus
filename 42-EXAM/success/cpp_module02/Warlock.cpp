#include "Warlock.hpp"
#include  "ATarget.hpp"
#include  "ASpell.hpp"
Warlock::Warlock(const std::string &name,const std::string title):name(name),title(title){
    std::cout<< getName()<<": This looks like another boring day."<<std::endl ;
}
Warlock::~Warlock(){
     

    std::cout<<getName()<< ": My job here is done!"<<std::endl;

}
const std::string &Warlock::getName()const{return this->name;}
const std::string &Warlock::getTitle()const{return this->title;}
void Warlock::setTitle(const std::string &title){this->title=title;}
void Warlock::introduce()const{
    std::cout<<getName()<<": I am "<< getName()<<", " <<getTitle()<<"!"<<std::endl;
}


void Warlock::learnSpell(ASpell *spell){
    spellbook.learnSpell(spell);
}
void Warlock::forgetSpell(const std::string &name){
    spellbook.forgetSpell(name);
}
void Warlock::launchSpell(const std::string &name,ATarget &target){
    ASpell *spell = spellbook.createSpell(name);
    if(spell){
        spell->launch(target);
    }
}


