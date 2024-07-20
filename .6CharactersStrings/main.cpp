#include <iostream>
#include <cstring>

void CheckingCharacters(){
    
    //with this we can check if the character is alpha numerical (a number or a letter), if it is, it gives us a 1, if it isnt it gives us a 0
    std::cout << "C is alphanumeric: " << std::isalnum('C') << std::endl;
    
    std::cout << "? is alphanumeric: " << std::isalnum('?') << std::endl;
    
    //we can also directly check
    if (std::isalnum('C')){
        std::cout << "Character is alphanumeric." << std::endl;
    }
    else {
        std::cout << "Character is not alphanumeric." << std::endl;
    }
    
    //this command sees if it is an alphabetical number
    std::cout << "1 is alphabetical: " << std::isalpha('1') << std::endl;
    
    char message[] = "Hello there summoner. 223 ";
    
    int blankCounter = 0;
    
    std::cout << message << std::endl;
    
    for (size_t i = 0; i < std::size(message); ++i){
        
        char c = message[i];
        
        //this command checks if it's blank
        if (std::isblank(message[i])){
            std::cout << "Found a blank character at index: " << i << std::endl;
            ++blankCounter;
        }
        
        //this command checks if it's a lowercase
        if (std::islower(message[i])){
            std::cout << "Found a lowercase character at index: " << i << ", which is " << message[i] << std::endl;
            //this command turns that character into uppercase
            message[i] = std::toupper(c);
        }
        //this command checks if it's a uppercase
        else if (std::isupper(message[i])){
            std::cout << "Found a uppercase character at index: " << i << ", which is " << message[i] << std::endl;
            //this command turns that character into lowercase
            message[i] = std::tolower(c);
        }
        //this command checks if it's a digit
        else if (std::isdigit(message[i])){
            std::cout << "Found a digit character at index: " << i << ", which is " << message[i] << std::endl;   
        }
    }
    
    std::cout << "Found " << blankCounter << " blank(s)." <<std::endl;
    
    std::cout << message << std::endl;
}

void SpecificFunctions(){
    
    const char message1[] = "The sky is blue.";
    
    //havent noted anything about this, but you can create a character pointer directly to a c-string, but always make it constant for good measure
    const char* message2{"The sky is blue."};
    
    //this command prints out the size of the message, not counting the \0 in the end
    std::cout << "Size of message1 : " << std::strlen(message1) << std::endl;
    
    std::cout << "Size of message2 : " << std::strlen(message2) << std::endl;
    
    const char* message3 = "Blabcma";
    
    const char* message4 = "Blabama";
    
    //right now cant find a use case scenario for this type of comparison where we check whoever comes first in alphabetical order, in this case, Blabcma comes after Blabama so we get a value of 1, if it was the same we would get a value of 0, if it was after we would get a value of -1
    std::cout << std::strcmp(message3,message4) << std::endl;
    
    //we can do the same thing but this time we compare it with the first 3 values, because Bla is the same as Bla we will get 0
    std::cout << std::strncmp(message3, message4, 3) << std::endl;
    
    //so this function gives us the rest of the string starting at the character we poointed at, turning that string into, in this example, bcma, since we found b after that, and because we're looking for b, the rest is gonna be nullptr
    while ((message3 = std::strchr(message3, 'b')) != nullptr){
        std::cout << "Found b starting at " << message3 << std::endl; 
        
        break;
    }
    std::cout << "Found this: " << message3 << std::endl;
    //after some testing, still a bit confused, I know what it does, but I feel like a for cycle might be better than this
    
    char dest[50] = "Hello ";
    char src[50] = "World!";
    
    //this code basically joins both the char arrays, but we need space in that array to store all the information, we can also use std::strncat which does the same thing, yet with one extra parameter that lets us decide how many characters to add 
    std::strcat(dest,src);
    
    std::cout << dest << std::endl;
    
    std::strcat(dest, " Goodbye World!");
    
    std::cout << dest << std::endl;
    
    const char original[] = "Hello World!";
    
    char dup[std::strlen(original + 1)]; //contains garbage value
    
    std::cout << "Original: " << original << std::endl;
    
    std::cout << "Dup: " << dup << std::endl;
    
    //std::strcpy(original, dump); this code doesnt work because original is a const
    
    std::strcpy(dup, original); //this one does, because dup is not a const and will copy the data in original
    
    std::cout << "Dup: " << dup << std::endl; //the function strcpy copies the characters, yet we can also use strncpy which only copies the characters we need
}

void StringsBegins(){
    //different ways to initialize a std::string
    std::string fullName; //empty
    std::string planet = "Earth";
    std::string planet2 {"UrAnus"};
    std::string preferedPlanet = planet;
    std::string planet3 {"UrAnus!", 2}; //initializes the string with only the first 2 characters, in this case Ur
    std::string eSpam {21, 'e'}; //initializes the string with 21 e's
    std::string sayingHello = "Hello World";
    std::string sayingWorld{ sayingHello , 6, 5}; //initializes the string on basis with sayingHello, but since it has 2 numbers in front, it will start on the 6th index and will contain 5 characters
    
    //the cool thing about strings on contrary to character arrays, is that we can actually change the size of it, no worries
    planet = "AELKGJKLAEGJKLAEJGLAEJGKLJAEKLGJAELKJGKLAEGJLKAEJGKLAEJGKLAEKLGEKLAJGKLEAJGAEJLGEAKLGJEAGAEJ"; //and this will work
}

int main(){
           
    return 0;
}