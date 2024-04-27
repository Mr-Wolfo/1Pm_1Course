#ifndef SUBSEA_BUBBLE_HPP
#define SUBSEA_BUBBLE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Circle.hpp"

namespace wlf {

	class Bubble : public Circle {
	private:
		bool m_hit;
		sf::Texture m_textureBubble;

	public:
		Bubble() = default;

		Bubble(float x, float y, float r, float dx, float dy) {
			Setup(x, y, r, dx, dy);
		}

		bool Setup(float x, float y, float r, float dx, float dy) override {
			m_x = x;
			m_y = y;
			m_r = r;
			m_dx = dx;
			m_dy = dy;
            m_hit = true;
			m_shape.setOrigin(m_r, m_r);
			m_shape.setRadius(m_r);
			m_shape.setPosition(m_x, m_y);

			// Загрузка текстуры
			if (!m_textureBubble.loadFromFile("assets\\bubble.png"))
			{
				std::cout << "Error while loading bubble.png" << std::endl;
				return false;
			}

			m_shape.setTexture(&m_textureBubble);

			return true;
		}

		// Движение
		void Move(float dt)
		{
			m_x += m_dx * dt;
			m_y += m_dy * dt;

			m_shape.setPosition(m_x, m_y);
		}
	};
}

#endif //SUBSEA_BUBBLE_HPP