#ifndef TERRAIN_H
#define TERRAIN_H

#include"GameDefs.h"

#include<SDL.h>
#include<vector>
#include<stdint.h>
#include<algorithm>
#include<cmath>

typedef struct
{
    uint8_t R, G, B, A;
    inline uint32_t ToUint32() const
    { uint32_t num=0; return num|R|G|B|A;}
} RGBA;

class Terrain
{
    public:
        Terrain();
        virtual ~Terrain();

        void terrainInit(SDL_Renderer* renderer, int width, int height);
        void terrainGenerate(); //TODO: should take generation parameters for the perlin noise algorithm
        void terrainDestroy();

        void terrainUpdate();

        inline SDL_Surface* getLevelData()
        { return m_levelSurface; }

        inline SDL_Texture* getLevelTexture() const
        { return m_texture; }

    private:

    void perlinNoiseGen(int size, int octaves); //OCTAVES SHOULD ALWAYS BE A POWER OF TWO!!!!

    std::vector<float> m_perlinNoise;
    std::vector<float> m_noiseSeed;

    std::vector<float> m_heightMap;
    std::vector<RGBA> m_pallete;
    SDL_Texture* m_texture;
    SDL_Surface* m_levelSurface;
    unsigned int m_width, m_height;
};

#endif // TERRAIN_H
