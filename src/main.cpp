#include <game.hpp>
#include <exception>

int main()
{
    try
    {
        Game game;
        game.run();
    }
    catch (std::exception ex)
    {
        std::cerr << "ERROR: " << ex.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCESS;
}
