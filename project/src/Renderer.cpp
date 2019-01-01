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

void Renderer::drawScreen(Camera& camera)
{
    SDL_SetRenderDrawColor(m_sdlRenderer, 0, 0, 0, 0);
    SDL_RenderClear(m_sdlRenderer);
    Vector2f cam_pos = camera.GetTransform().GetVector2f(Vector2f(0.0f, 0.0f));
    SDL_Rect cam_transform = { };

    //draw queues to screen

    if(m_levelToDraw != nullptr)
    {
        SDL_RenderCopy(m_sdlRenderer, m_levelToDraw, NULL, NULL);
    }

    SDL_RenderPresent(m_sdlRenderer);
}
