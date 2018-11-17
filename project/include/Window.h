#ifndef WINDOW_H
#define WINDOW_H

#include"SDL.h"

class Window
{
    public:
        Window(int w, int h);
        virtual ~Window();

        void pollEvents(SDL_Event& e);
        void display();

    private:
        const int m_width, m_height;

        SDL_Window* m_window;
};

#endif // WINDOW_H
