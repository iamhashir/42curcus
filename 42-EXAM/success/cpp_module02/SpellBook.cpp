#include "SpellBook.hpp"


SpellBook::SpellBook(){}
SpellBook::~SpellBook(){
    for(std::map<std::string,ASpell *>::iterator it = book.begin();it!=book.end();++it)
        delete it->second;
    book.clear();
}
void SpellBook::learnSpell(ASpell* spell){
    if(!spell)return;
    if(book.find(spell->getName()) == book.end()){
        book[spell->getName()] = spell->clone();
    }
}
void SpellBook::forgetSpell(std::string const &name){
    std::map<std::string,ASpell *>::iterator it = book.find(name);
    if(it!=book.end())
    {
        delete it->second;
        book.erase(it);
    }
}

ASpell *SpellBook::createSpell(std::string const &name){
    std::map<std::string,ASpell *>::iterator it = book.find(name);
    if(it!=book.end())
    {
        return it->second->clone();
    }
    return NULL;
}