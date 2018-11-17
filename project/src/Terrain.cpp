#include "Terrain.h"

Terrain::Terrain()
{
    //ctor
}

Terrain::~Terrain()
{
    terrainDestroy();
}

void Terrain::terrainInit(SDL_Renderer* renderer, int width, int height)
{
    m_texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, width, height);
    //temporary

}

void Terrain::terrainDestroy()
{
    SDL_DestroyTexture(m_texture);
}

void Terrain::terrainGenerate()
{

}
