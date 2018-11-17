#include "Window.h"

Window::Window(int w, int h) :m_width(w), m_height(h)
{

}

Window::~Window()
{
    //dtor
}

void Window::pollEvents(SDL_Event& e)
{
    while(SDL_PollEvent(e)!=0)
    { }
}

