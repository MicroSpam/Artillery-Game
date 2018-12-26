#include "Renderer.h"

Renderer::Renderer(SDL_Window* window)
{
    m_sdlRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

Renderer::~Renderer()
{
    SDL_DestroyRenderer(m_sdlRenderer);
}

void Renderer::drawTerrain(Terrain* terrain)
{
    m_levelToDraw = terrain->getLevelTexture();
}

void Renderer::drawScreen()
{
    SDL_SetRenderDrawColor(m_sdlRenderer, 0, 0, 0, 0);
    SDL_RenderClear(m_sdlRenderer);

    //draw queues to screen

    if(m_levelToDraw != nullptr)
    {
        SDL_RenderCopy(m_sdlRenderer, m_levelToDraw, NULL, NULL);
    }

    SDL_RenderPresent(m_sdlRenderer);
}
