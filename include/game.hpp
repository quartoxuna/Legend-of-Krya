#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

namespace pacman {

class Game
{
    public:
        Game();

     public:
        void run();

     private:
        sf::RenderWindow mWindow;
};

} // end of namespace pacman
