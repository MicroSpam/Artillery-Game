#ifndef RENDERER_H
#define RENDERER_H

#include<memory>
#include<SDL.h>

#include"Terrain.h"

class Renderer
{
    public:
        Renderer(SDL_Window* window);
        virtual ~Renderer();

        void drawScreen();
        void drawTerrain(Terrain* terrain);

        inline SDL_Renderer* getRenderer()
        { return m_sdlRenderer; }

    protected:

    private:
    SDL_Renderer* m_sdlRenderer;
};

#endif // RENDERER_H
