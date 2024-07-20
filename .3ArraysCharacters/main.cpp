#include <iostream>
#include <string>

int main(){
    
    char lettera {'A'};
    
    char lettera2 {65};
    
    char letterb {66};
    
    std::cout << sizeof(lettera) << std::endl;
    
    std::cout << sizeof(lettera2) << std::endl;
    
    auto sum = lettera2 + letterb;
    
    std::cout << sizeof(sum) << std::endl;
    
    char message[] {'h', 'e', 'l', 'l', 'o'};
    
    std::cout << std::size(message) << std::endl;
    
    std::cout << "Why ";
    
    /*
    This was interesting ngl, could have its use case scenarios
    f.e, in an enemy manager, we could if every enemy is dead and then boom, end the fight
    */
   
    for (auto i : message){
        std::cout << i;
    }
    
    std::cout << " there!" << std::endl;
    
    //so looks like i rushed myself, yet nice, I got a little bit of a bigger understanding of strings!
    char message2[] {'h', 'e', 'l', 'l', 'o', '\0'};
    
    std::cout << "Why " << message2 << " there!" << std::endl;
    
    //I feel dumb
    char message3[] {"hello"};
    
    std::cout << "Why " << message3 << " there!";
    
    return 0;
}