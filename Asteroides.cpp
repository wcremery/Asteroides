// Asteroides.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <SFML/Graphics.hpp>
#include "Ship.hpp"

constexpr int WINDOW_WIDTH{ 800 };
constexpr int WINDOW_HEIGHT{ 600 };

int main()
{
	sf::RenderWindow window{ sf::VideoMode{WINDOW_WIDTH, WINDOW_HEIGHT}, "Asteroids game !" };
	Coordinates::initiateSpace(WINDOW_WIDTH, WINDOW_HEIGHT);
	auto ship = Ship{ sf::Color{255,255,255 } };
	auto chrono = sf::Clock{};

	while (window.isOpen())
	{
		auto event = sf::Event{};		

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}			
		}
		
		ship.UpdateState();
		ship.UpdatePos(chrono.restart().asSeconds());
		window.clear();
		ship.Print(window);
		window.display();
	}
	return 0;
}
