#include "MainGame.h"

MainGame::MainGame(SDL_Window* window) : m_window(window), m_renderer(window), m_camera(Vector2f(0.0f, 0.0f), 1.0f)
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
    m_currentTerrain->terrainInit(m_renderer.getRenderer(), 800, 600);
}

void MainGame::gameUnload()
{
    m_currentTerrain->terrainDestroy();
}

void MainGame::gameLoop()
{
    m_player.PlayerTerrainUpdate(m_currentTerrain->getLevelData());
    m_renderer.drawTerrain(m_currentTerrain.get());

    m_renderer.drawScreen(m_camera);
}
