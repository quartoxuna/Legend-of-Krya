#include <game.hpp>

/**
 * Default constructor
 */
Game::Game()
: mWindow(sf::VideoMode(800, 600), "SFML Application")
{}


/**
 * Main Game loop
 *
 * @return void
 */
void Game::run()
{
    while (mWindow.isOpen())
    {
        processEvents();
        update();
        draw();
    }
}


/**
 * Process events from main window
 *
 * @return void
 */
void Game::processEvents()
{
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            mWindow.close();
    }
}


/**
 * Update main window
 *
 * @return void
 */
void Game::update()
{}


/**
 * Draw main window
 *
 * @return void
 */
void Game::draw()
{
    mWindow.clear(sf::Color::Magenta);
    mWindow.display();
}
