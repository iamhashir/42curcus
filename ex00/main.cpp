#include "Bureaucrat.hpp"
#include <iostream>
int main() {
    try{
        Bureaucrat b("hashir",00);    
    }
    catch (std::exception &s){
        std::cout<<s.what();
    }
    
    return 0;
}