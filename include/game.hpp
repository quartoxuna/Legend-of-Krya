#pragma once

#include <SFML/Graphics.hpp>

class Game
{
    public:
        Game();

        void run();
        void processEvents();
        void update();
        void draw();

    private:
        sf::RenderWindow mWindow;
};
