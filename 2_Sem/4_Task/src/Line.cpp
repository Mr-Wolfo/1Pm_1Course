#include "SFML/Graphics.hpp"

namespace wlf {
    class Line {
        float m_len;
        float m_t;
        float m_x, m_y;
        sf::RectangleShape m_shape;

    public:
        Line() = default;

        Line(float x, float y, float t, float len) {
            Setup(x, y, t, len);
        }

        void Setup(float x, float y, float t, float len) {
            m_x = x;
            m_y = y;
            m_t = t;
            m_len = len;
            m_shape.setPosition(m_x, m_y);
            m_shape.setRotation(m_t);
            m_shape.setSize({m_len, 1});
            m_shape.setFillColor(sf::Color::Yellow);
        }

        sf::RectangleShape Get() {
            return m_shape;
        }
    };
}

