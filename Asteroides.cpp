// Asteroides.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window{ sf::VideoMode{800, 600}, "Asteroids game !" };
	while (window.isOpen())
	{
		auto event = sf::Event{};
		auto circle = sf::CircleShape{100};

		circle.setFillColor(sf::Color::Red);
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		
		window.clear(sf::Color::Black);
		window.draw(circle);
		window.display();
	}
	return 0;
}
