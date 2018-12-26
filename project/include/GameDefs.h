#ifndef GAMEDEFS_H_INCLUDED
#define GAMEDEFS_H_INCLUDED

//RGB MASKS
#include<SDL.h>
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
#define R_MASK 0xFF000000
#define G_MASK 0x00FF0000
#define B_MASK 0x0000FF00
#define A_MASK 0x000000FF
#else
#define A_MASK 0xFF000000
#define B_MASK 0x00FF0000
#define G_MASK 0x0000FF00
#define R_MASK 0x000000FF
#endif

#include<stdint.h>
#include<stdio.h>

static void putPixel(const uint32_t x, const uint32_t y, SDL_Surface* screen, const uint32_t RGBA)
{
    uint32_t* getPixel = (uint32_t*)screen->pixels+y*screen->w+x;
    *getPixel = RGBA;
}

#endif // GAMEDEFS_H_INCLUDED
