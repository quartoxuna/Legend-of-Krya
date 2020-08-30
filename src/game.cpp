#include <game.hpp>

#include <SFML/Window/Event.hpp>

namespace pacman {

/**
 * Constructor
 *
 * @init mWindow - The main game window
 */
Game::Game()
: mWindow(sf::VideoMode(800, 600), "SFML Application")
{}


/**
 * Main game loop
 *
 * @return void
 */
void Game::run()
{
    sf::Event event;

    while (mWindow.isOpen())
    {
        while (mWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                mWindow.close();
        }

        mWindow.clear(sf::Color::Magenta);
        mWindow.display();
    }
}


} // end of namespace pacman
