#include "Terrain.h"
#include<stdio.h>

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
    m_levelSurface = SDL_CreateRGBSurface(0, width, height, 32, R_MASK, G_MASK, B_MASK, A_MASK);
    m_width = width;
    m_height = height;
    terrainGenerate();
    m_texture = SDL_CreateTextureFromSurface(renderer, m_levelSurface);

    //temporary

}

void Terrain::terrainDestroy()
{
    SDL_FreeSurface(m_levelSurface);
    SDL_DestroyTexture(m_texture);
}

void Terrain::terrainGenerate()
{

    //TEMPORARY
    //RGBA default_color = {0x00, 0xFF, 0x00, 0xFF};
    //m_heightMap = perlinNoiseGen(m_width, 16);
    perlinNoiseGen(m_width, 8);
    for(unsigned int x=0;x<m_width;++x)
    {
        printf("height: %d\n", (int)(m_heightMap[x]*(float)(m_height/2.0f)));
        int pixelHeight = (int)(m_heightMap[x]*(float)(m_height/2.0f));
        SDL_LockSurface(m_levelSurface);
        //putPixel(x, pixelHeight, m_levelSurface, 0xFFFFFFFF);
        for(unsigned int y=pixelHeight;y<m_height;++y)
        {
            putPixel(x, y, m_levelSurface, 0xFFFFFFFF);
        }
        SDL_UnlockSurface(m_levelSurface);
    }
    uint32_t* pixel = (uint32_t*)m_levelSurface->pixels+(m_height/2)*m_levelSurface->w;
    printf("%x\n", *pixel);
}

void Terrain::terrainUpdate()
{

}

void Terrain::perlinNoiseGen(int size, int octaves)
{
    //if(std::log2((double)octaves)-std::floor(std::log2((double)octaves))>0)
    //{
        //printf("Octaves is not a power of two!\n");
        //return nullptr;
    //}
    //else
    //{
        //std::vector<float> output;
        for(int i=0;i<size;++i)
        {
            m_noiseSeed.push_back((float)rand()/(float)RAND_MAX);
        }

        for(int n=0;n<size;++n)
        {
            float noise = 0.0f;
            float scale = 1.0f;
            float scaleAcc = 0.0f;
            for(int o=0;o<octaves;++o)
            {
                //printf("num: %d, octave, %d\n", n, o);
                int pitch = size >> o;
                //printf("pitch: %d\n", pitch);
                int sample1 = (n/pitch)*pitch;
                //printf("sample1: %d\n", sample1);
                int sample2 = (sample1+pitch)%size;
                //printf("sample2: %d\n", sample2);
                float blend = (float)(n-sample1)/(float)pitch;
                //printf("blend: %f\n", blend);
                float sampleFinal = (1.0f - blend)*m_noiseSeed[sample1]+blend*m_noiseSeed[sample2];
                //printf("sampleF: %f\n", sampleFinal);
                scaleAcc += scale;
                noise += sampleFinal*scale;
                //printf("noise: %f\n", noise);
                scale /= 2.0f;
                //printf("scale: %f\n", scale);

            }
            m_heightMap.push_back(noise/scaleAcc);
            printf("height successfully added: %f\n", m_heightMap[n]);
        }
        //return output;
    //}
}
