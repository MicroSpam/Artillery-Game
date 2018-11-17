#ifndef APPLICATION_H
#define APPLICATION_H

#include<SDL.h>
#include"MainGame.h"
#include<iostream>

class Application
{
    public:
        Application();
        virtual ~Application();

        int Init();//TODO: init should take command line parameters
        void Close();

        void Update();

    private:
        int m_windowWidth = 640, m_windowHeight = 480;

        SDL_Window* m_appWindow;
        SDL_Event* m_e;

        int m_success, m_open = 1;

        MainGame* m_game;

};

#endif // APPLICATION_H
