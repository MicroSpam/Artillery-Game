#include "Player.h"

#include <iostream>

Player::Player()
{
    //ctor
}

Player::~Player()
{
    //dtor
}


void Player::PlayerTerrainUpdate(SDL_Surface* terrainSurface)
{
    printf("x: %i, y: %i\n", getMouseAbs().x, getMouseAbs().y);


}
