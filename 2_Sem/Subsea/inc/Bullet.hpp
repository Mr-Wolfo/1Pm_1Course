#ifndef SUBSEA_BULLET_HPP
#define SUBSEA_BULLET_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Circle.hpp"

namespace wlf {

	class Bullet : public Circle {
	private:
		bool m_active = true;
		float m_lifeTime;
		float m_angle = 0;
		sf::Texture m_textureBullet;

	public:
		Bullet() = default;

		Bullet(float x, float y, float r, float dx, float dy, float lifeTime, sf::Texture *Texture, bool flag) {
			m_shape.setTexture(Texture);
			Setup(x, y, r, dx, dy, lifeTime ,flag);
		}

		bool Setup(float x, float y, float r, float dx, float dy, float lifeTime, bool flag) {
			m_x = x;
			m_y = y;
			m_r = r;
			m_dx = dx;
			m_dy = dy;
			m_active = flag;
			m_lifeTime = lifeTime;
			m_shape.setOrigin(m_r, m_r);
			m_shape.setRadius(m_r);
			m_shape.setPosition(m_x, m_y);
			return true;
		}

		// Движение
		void Move(float dt)
		{
			m_lifeTime -= dt;
			m_x += m_dx * dt;
			m_y += m_dy * dt;

			m_angle += 15;
			m_shape.setRotation(m_angle);

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

			// Окончание времени жизни пули

			if (m_lifeTime <= 0) {
				Setup(0, 0, 0, 0, 0, 0, false);
			}
		}

		// Флаг активности пули
		bool Active() { return m_active; }
	};
}

#endif //SUBSEA_BULLET_HPP
