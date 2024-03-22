#ifndef INC_4_TASK_TRIANGLE_HPP
#define INC_4_TASK_TRIANGLE_HPP

#include "SFML/Graphics.hpp"

namespace wlf {
    class Triangle {
        float m_r, m_t;
        float m_x, m_y;
        sf::CircleShape m_shape;

    public:
        Triangle() = default;

        Triangle(float x, float y, float r, float t) {
            Setup(x, y, r, t);
        }

        void Setup(float x, float y, float r, float t) {
            m_x = x;
            m_y = y;
            m_r = r;
            m_t = t;
            m_shape.setRotation(m_t);
            m_shape.setRadius(m_r);
            m_shape.setPointCount(3);
            m_shape.setPosition(m_x, m_y);
            m_shape.setFillColor(sf::Color::Green);
        }

        sf::CircleShape Get() {
            return m_shape;
        }
    };
}

#endif //INC_4_TASK_TRIANGLE_HPP
