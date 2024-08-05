#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
#include "person.h"

class Player : public Person{
    friend std::ostream& operator << (std::ostream& out, const Player& player);
    
public:
    Player() = default;
    Player(std::string_view gameParam);
    
private:
    std::string m_game{"None"};
};

#endif