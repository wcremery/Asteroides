#include <SFML/Graphics.hpp>
#include<array>
#include "../include/Ship.h"
#include "../include/Asteroid.h"
#include "../include/Coordinates.h"

constexpr int WIDTH_WINDOW{800};
constexpr int HEIGHT_WINDOW{600};

int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH_WINDOW, HEIGHT_WINDOW), "SFML works!");
	auto chrono = sf::Clock();
	Coordinates::initialize_space(WIDTH_WINDOW, HEIGHT_WINDOW);
	auto ship = Ship{ sf::Color::Yellow };
	auto asteroid = Asteroid{};
	auto spaceObjects = std::array<SpaceObject*, 2>{&asteroid, &ship };

	while(window.isOpen())
	{
		auto evenement = sf::Event{};
		while(window.pollEvent(evenement))
		{
			if (evenement.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		ship.updateState();
		auto deltaTime = chrono.restart().asSeconds();
		for(auto* currentSpaceObject : spaceObjects)
		{
			currentSpaceObject->updateSpaceObject(deltaTime);
			if (currentSpaceObject != &ship)
			{
				currentSpaceObject->checkCollision(ship);
			}
		}

		window.clear();
		for (auto* currentSpaceObject : spaceObjects)
		{
			currentSpaceObject->display(window);
		}

		window.display();
	}

	return EXIT_SUCCESS;
}
