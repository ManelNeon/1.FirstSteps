#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
#include "person.h"

//so the reason we do public Person, instead of protected Person or private person is because we want the variables to stay in their classification in the Player Class, in a public Person, all variables stay the same, public -> public, protected -> protected and private -> private, in a protected Person, publics become protected, protected -> protected, and in a private Person, publics and protected become private, public -> private and protected -> private
class Player : public Person{
    friend std::ostream& operator << (std::ostream& out, const Player& player);
    
public:
    Player() = default;
    Player(std::string_view firstNameParam, std::string_view secondNameParam, std::string_view gameParam);
    
private:
    std::string m_game{"None"};
};

#endif