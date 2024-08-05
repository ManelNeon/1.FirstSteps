#include "person.h"
#include "player.h"

Player::Player(std::string_view gameParam)
    : m_game(gameParam)
{
}

std::ostream& operator<<(std::ostream& out, const Player& player){
    out << "Player : [ game : "  << player.m_game
         << " names : " << player.get_first_name()
             << " " << player.get_last_name() << "]";
    return out;
}