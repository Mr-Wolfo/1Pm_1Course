#ifndef SUBSEA_UI_HPP
#define SUBSEA_UI_HPP

#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"
#include "Text.hpp"

namespace wlf
{
	class UI
	{
	private:
		std::vector<Title*> m_text;
		Title test;

	public:

		void Setup()
		{
			m_text.push_back(new Title(1600, 0));
			m_text[0]->Get()->setCharacterSize(48);
			m_text[0]->Get()->setFillColor(sf::Color::Red);

			m_text.push_back(new Title(1600, 50));
			m_text[1]->Get()->setCharacterSize(48);
			m_text[1]->Get()->setFillColor(sf::Color::Green);
		}

		void ViewAmmo() {m_text[0]->Get()->setString("Torpedo: " + std::to_string(m_ammo) + "/" + std::to_string(m_clip)); }
		void ViewScore(int score) {m_text[1]->Get()->setString("Score: " + std::to_string(score)); }

		Title* Get(int i) { return m_text[i]; }

		void SetString(int i, std::string str) { m_text[i]->Get()->setString(str); }

	};
}

#endif //SUBSEA_UI_HPP
