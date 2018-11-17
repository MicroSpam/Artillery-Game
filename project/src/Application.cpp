#include "Application.h"

Application::Application()
{
    m_success = SDL_Init(SDL_INIT_VIDEO);
    m_e = new SDL_Event;
}

Application::~Application()
{
    //dtor
}

int Application::Init()
{
    if(m_success == 0);
    {
        m_appWindow = SDL_CreateWindow("artillery",
                                        SDL_WINDOWPOS_UNDEFINED,
                                        SDL_WINDOWPOS_UNDEFINED,
                                        m_windowWidth,
                                        m_windowHeight,
                                        SDL_WINDOW_SHOWN);
        //TODO: Add error handling
        m_game = new MainGame(m_appWindow);
        m_game->gameLoad();
    }
    return m_success;
}

void Application::Close()
{
    SDL_DestroyWindow(m_appWindow);
    delete m_e;
    delete m_game;
    SDL_Quit();
}

void Application::Update()
{
    while(m_open)
    {
        while(SDL_PollEvent(m_e)!=0)
        {
            if(m_e->type == SDL_QUIT)
            m_open = 0;
        }

        //game code
        m_game->gameLoop();
    }
}
