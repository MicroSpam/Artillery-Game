#include "MainGame.h"

MainGame::MainGame(SDL_Window* window) : m_window(window), m_renderer(window)
{
    //ctor
}

MainGame::~MainGame()
{
    m_currentTerrain->terrainDestroy();
}

void MainGame::gameLoad()
{
    m_currentTerrain = std::make_unique<Terrain>();
    m_currentTerrain->terrainInit(m_renderer.getRenderer(), 1024, 1024);
}

void MainGame::gameUnload()
{
    m_currentTerrain->terrainDestroy();
}

void MainGame::gameLoop()
{

    m_renderer.drawTerrain(m_currentTerrain.get());

    m_renderer.drawScreen();
}