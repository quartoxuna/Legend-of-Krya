#include <game.hpp>

#include <SFML/Window/Event.hpp>
#include <SFML/System/Clock.hpp>

namespace pacman
{

/**
 * Constructor
 *
 * @init mWindow - The main game window
 */
Game::Game()
: mWindow(sf::VideoMode(800, 600), "SFML Application")
, mPlayer()
{}


/**
 * Main game loop
 *
 * @return void
 */
void Game::run()
{
    sf::Clock clock;
    sf::Time lastUpdate = sf::Time::Zero;

    while (mWindow.isOpen())
    {
        processEvents();

        lastUpdate += clock.restart();
        while (lastUpdate > TIME_PER_FRAME)
        {
            lastUpdate -= TIME_PER_FRAME;
            processEvents();
            update(TIME_PER_FRAME);
        }
        render();
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
        else
            mPlayer.processEvent(event);
    }
}


/**
 * Updates the main window
 *
 */
void Game::update(sf::Time dt)
{
    mPlayer.update(dt);
}


/**
 * Render the main window
 *
 */
void Game::render()
{
    mWindow.clear(sf::Color::Black);
    mWindow.draw(mPlayer);
    mWindow.display();
}


} // end of namespace pacman
