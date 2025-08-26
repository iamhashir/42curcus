#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
 
    FragTrap f1("FRG1");
    FragTrap f2(f1);  
    
     
    FragTrap f3("FRG3");
    f3 = f1;
    
     
    // for(int i = 0; i < 101; ++i) {
    //     f1.attack("dummy");   
    // }
    
     f2.takeDamage(150);      
    f2.highFivesGuys();      
    f2.beRepaired(50);       
    
     f3.takeDamage(50);
    f3.beRepaired(30);
    f3.highFivesGuys();      
    
    return 0;
}