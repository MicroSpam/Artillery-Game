#ifndef MAINGAME_H
#define MAINGAME_H

#include <iostream>
#include <SDL.h>
#include <memory>

#include "Terrain.h"
#include "Renderer.h"
#include "Player.h"

class MainGame
{
    public:
        MainGame(SDL_Window* window);
        virtual ~MainGame();

        void gameLoad();
        void gameUnload();
        void gameLoop();

    protected:

    private:
        SDL_Window* m_window;
        Renderer m_renderer;

        std::unique_ptr<Terrain> m_currentTerrain;

        Player m_player;
};

#endif // MAINGAME_H
