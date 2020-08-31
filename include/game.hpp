#pragma once

#include <player.hpp>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>

const float FPS = 60.f;
const sf::Time TIME_PER_FRAME = sf::seconds(1.f / FPS);

namespace pacman
{

class Game
{
    public:
        Game();

    public:
        void run();

    private:
        void processEvents();
        void update(sf::Time deltaTime);
        void render();

    private:
        sf::RenderWindow mWindow;
        Player           mPlayer;
};

} // end of namespace pacman
