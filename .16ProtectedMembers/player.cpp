#include "person.h"
#include "player.h"

Player::Player(std::string_view firstNameParam, std::string_view secondNameParam, std::string_view gameParam)
{
    first_name = firstNameParam;
    last_name = secondNameParam;
    m_game = gameParam;
}

std::ostream& operator<<(std::ostream& out, const Player& player){
    out << "Player : [ game : "  << player.m_game
         << " names : " << player.first_name
             << " " << player.last_name << "]";
    return out;
}