#ifndef PLAYER_H
#define PLAYER_H

#if defined(DEBUG)
#define IS_DEBUG 1
#else
#define IS_DEBUG 0
#endif

#include "Terrain.h"
#include "GameDefs.h"
#include "Input.h"

class Player
{
    public:
        Player();
        virtual ~Player();

        //perhaps just a debug func
        void PlayerTerrainUpdate(SDL_Surface* terrainSurface);
    protected:

    private:
};

#endif // PLAYER_H
