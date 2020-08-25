#include <SFML/Graphics.hpp>

int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Application");

	// Start the game loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window on exit
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// Clear screen
		window.clear(sf::Color::Magenta);
		window.display();
	}

	return EXIT_SUCCESS;
}
