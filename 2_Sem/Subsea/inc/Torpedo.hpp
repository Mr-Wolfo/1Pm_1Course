#ifndef INC_SUBSEA_TORPEDO_HPP
#define INC_SUBSEA_TORPEDO_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Circle.hpp"

namespace wlf {

	class Torpedo : public Circle {
	private:
		float m_angle;
		bool m_active = true;
		float m_lifeTime;
		sf::Texture m_textureBullet;

	public:
		Torpedo() = default;

		Torpedo(float x, float y, float r, float dx, float dy, float angle, float lifeTime, bool flag) {
			Setup(x, y, r, dx, dy, angle, lifeTime ,flag);
		}

		bool Setup(float x, float y, float r, float dx, float dy, float angle, float lifeTime, bool flag) {
			m_x = x;
			m_y = y;
			m_r = r;
			m_dx = dx;
			m_dy = dy;
			m_angle = angle;
			m_active = flag;
			m_lifeTime = lifeTime;
			m_shape.setOrigin(m_r, m_r);
			m_shape.setRadius(m_r);
			m_shape.setRotation(m_angle);
			m_shape.setPosition(m_x, m_y);

			// Загрузка текстуры
			if (!m_textureBullet.loadFromFile("assets\\Torpedo.png"))
			{
				std::cout << "Error while loading Torpedo.png" << std::endl;
				return false;
			}

			m_shape.setTexture(&m_textureBullet, false);
			return true;
		}

		// Поворот текстуры при ударах
		void Rotate(float rotate) {
			m_angle = rotate;
			m_shape.setRotation(m_angle);
		}

		// Движение
		void Move(float dt)
		{
			m_lifeTime -= dt;
			m_x += m_dx * dt;
			m_y += m_dy * dt;

			m_shape.setPosition(m_x, m_y);

			// Стремление скорости к нулю

			if (m_dx > 0.1)
				m_dx -= 0.1;
			else if (m_dx < -0.1)
				m_dx += 0.1;
			else
				m_dx = 0;

			if (m_dy > 0.1)
				m_dy -= 0.1;
			else if (m_dy < -0.1)
				m_dy += 0.1;
			else
				m_dy = 0;

			// Окончание времени жизни Торпеды. Тут должен быть бабах

			if (m_lifeTime <= 0) {
				Setup(0, 0, 0, 0, 0,0, 0, false);
			}
		}

		// Флаг активности торпеды
		bool Active() { return m_active; }
		void Active(bool flag) { m_active = flag; }
	};
}

#endif //INC_SUBSEA_TORPEDO_HPP
