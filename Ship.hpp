#pragma once

#include <SFML/Graphics.hpp>
#include "Vector.hpp"
#include "Coordinates.hpp"

class Ship {
	public:
		Ship() = default;
		~Ship();
		Ship(sf::Color const&);
		void Print(sf::RenderWindow&) const;
		void UpdateState();
		void UpdatePos(float);

	private:
		static constexpr float ACCELERATION{ 2500.f };
		static constexpr float FRICTION{ 2.f };
		static constexpr float ANGULAR_SPEED{ 50.f };
		sf::Texture texture{};
		sf::Sprite sprite{};
		Coordinates position{};
		Vector speed{ 0.f, 0.f };
		bool isAccelerate{ false };
		bool isTurningLeft{ false };
		bool isTurningRight{ false };
};