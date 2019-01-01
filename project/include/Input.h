#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include <SDL.h>
#include <stdint.h>
#include <vector>

static int getKey(SDL_Scancode key)
{
    const uint8_t* keyboardState = SDL_GetKeyboardState(NULL);
    return keyboardState[key];
}

typedef struct
{
    int x, y, b1, b2, scroll;
} mouse_data;

static mouse_data getMouseAbs()
{
    int x, y;
    SDL_GetMouseState(&x, &y);
    mouse_data pos {x, y, 0, 0, 0};
    return pos;
}

static int getMouseButton()
{
    return 0;
}

#endif // INPUT_H_INCLUDED
