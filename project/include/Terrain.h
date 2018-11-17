#ifndef TERRAIN_H
#define TERRAIN_H

#include<SDL.h>
#include<vector>

class Terrain
{
    public:
        Terrain();
        virtual ~Terrain();

        void terrainInit(SDL_Renderer* renderer, int width, int height);
        void terrainGenerate(); //TODO: should take generation parameters for the perlin noise algorithm
        void terrainDestroy();

        inline SDL_Texture* getTexture()
        { return m_texture; }

    private:
    std::vector<float> m_heightMap;
    SDL_Texture* m_texture;
};

#endif // TERRAIN_H
