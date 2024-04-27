#ifndef SUBSEA_TEXT_HPP
#define SUBSEA_TEXT_HPP

#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"

namespace wlf
{
	class Title
	{
	private:
		sf::Font m_font;
		sf::Text m_text;
		float m_x;
		float m_y;

	public:

		Title() = default;

		Title(float x, float y)
		{
			if (!m_font.loadFromFile("fonts\\arial.ttf"))
			{
				std::cout << "Error" << std::endl;
				exit(-1);
			}
			m_text.setFont(m_font);
			Setup(x, y);
		}

		void Setup(float x, float y)
		{
			m_x = x;
			m_y = y;
			m_text.setPosition(x, y);
		}

		sf::Text* Get() { return &m_text; }

		float x() { return m_x; }

		float y() { return m_y; }

		~Title() = default;

	};
}

#endif //SUBSEA_TEXT_HPP
