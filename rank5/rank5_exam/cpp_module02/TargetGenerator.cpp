#include "TargetGenerator.hpp"


TargetGenerator::TargetGenerator(){}
TargetGenerator::~TargetGenerator(){
    for(std::map<std::string,ATarget *>::iterator it = book.begin();it!=book.end();++it)
        delete it->second;
    book.clear();
}
void TargetGenerator::learnTargetType(ATarget* target){
    if(!target)return;
    if(book.find(target->getType()) == book.end()){
        book[target->getType()] = target->clone();
    }
}
void TargetGenerator::forgetTargetType(std::string const &target){
    std::map<std::string,ATarget *>::iterator it = book.find(target);
    if(it!=book.end())
    {
        delete it->second;
        book.erase(it);
    }
}

ATarget *TargetGenerator::createTarget(std::string const &target){
    std::map<std::string,ATarget *>::iterator it = book.find(target);
    if(it!=book.end())
    {
        return it->second->clone();
    }
    return NULL;
}