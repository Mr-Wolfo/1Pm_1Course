#ifndef INC_SUBSEA_CIRCLE_HPP
#define INC_SUBSEA_CIRCLE_HPP

#include "SFML/Graphics/CircleShape.hpp"

namespace wlf {

	class Circle {
	protected:
		float m_r;
		float m_x, m_y;
		float m_dx, m_dy;
		sf::CircleShape m_shape;

	public:
		Circle() = default;

		virtual bool Setup(float x, float y, float r, float dx, float dy) { return false; };

		float x() { return m_x; }

		void x(float x) { m_x = x; }

		float y() { return m_y; }

		void y(float y) { m_y = y; }

		float dx() { return m_dx; }

		void dx(float dx) { m_dx = dx; }

		float dy() { return m_dy; }

		void dy(float dy) { m_dy = dy; }

		float R() { return m_r; };

		sf::CircleShape Get() { return m_shape; }

	};
}

#endif //INC_SUBSEA_CIRCLE_HPP
