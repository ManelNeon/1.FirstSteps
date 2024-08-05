#include <iostream>
#include "player.h"
#include "enginner.h"
#include "nurse.h"

int main(){
    
    Player p1("Jose", "Castelo Branco","Basketball");
        
    std::cout << p1 << std::endl;
    
    Enginner e1("Jose", "Castelo Branco", "Digital");
    
    std::cout << e1 << std::endl;
    
    Nurse n1("Jose", "Castelo Branco", "Little Boys");
    
    std::cout << n1 << std::endl;
    
    return 0;
}