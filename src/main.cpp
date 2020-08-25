#include <game.hpp>

#include <iostream>
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
        std::cout << "Error - " << ex.what() << std::endl;
	}

	return EXIT_SUCCESS;
}
