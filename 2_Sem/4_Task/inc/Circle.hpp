#ifndef INC_4_TASK_CIRCLE_HPP
#define INC_4_TASK_CIRCLE_HPP

#include "SFML/Graphics.hpp"

namespace wlf
{
    class Circle
    {
        float m_r;
        float m_x, m_y;
        sf::CircleShape m_shape;

    public:
        Circle() = default;

        Circle(float x, float y, float r)
        {
            Setup(x, y, r);
        }

        void Setup(float x, float y, float r)
        {
            m_x = x;
            m_y = y;
            m_r = r;
            m_shape.setRadius(m_r);
            m_shape.setPosition(m_x, m_y);
            m_shape.setFillColor(sf::Color::Red);
        }

        sf::CircleShape Get()
        {
            return m_shape;
        }
    };
}

#endif //INC_4_TASK_CIRCLE_HPP
