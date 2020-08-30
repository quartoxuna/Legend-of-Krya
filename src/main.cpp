#include <game.hpp>

#include <iostream>
#include <exception>

int main()
{
    try
    {
        pacman::Game game;
        game.run();
    }
    catch (std::exception ex)
    {
        std::cerr << "ERROR: " << ex.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
