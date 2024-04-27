#ifndef INC_SUBSEA_SEAMOTH_HPP
#define INC_SUBSEA_SEAMOTH_HPP

#include <iostream>
#include "cmath"
#include <SFML/Graphics.hpp>
#include "Torpedo.hpp"
#include "Bullet.hpp"
#include "DefinitionsSeamoth.hpp"

namespace wlf
{
	class Seamoth
	{

		float m_x, m_y;
		float m_dv;
		float m_angle, m_radAngle;
		float m_r = 80;
		sf::Texture m_textureSeamoth;
		sf::Sprite m_spriteSeamoth;
		Torpedo *m_torpedo;
		std::vector<Bullet*> m_bullet;
		sf::Texture m_textureBullet;

	public:
		Seamoth() = default;
		Seamoth(float x, float y)
		{
			m_x = x;
			m_y = y;
		}

		bool Setup(float x, float y)
		{
			m_x = x;
			m_y = y;
			m_angle = 0;
			m_dv = 0;

			// Загрузка текстуры
			if (!m_textureSeamoth.loadFromFile("assets\\seamoth.png"))
			{
				std::cout << "Error while loading seamoth.png" << std::endl;
				return false;
			}

			if (!m_textureBullet.loadFromFile("assets\\Bullet.png"))
			{
				std::cout << "Error while loading EnemyBullet.png" << std::endl;
				return false;
			}

			m_spriteSeamoth.setTexture(m_textureSeamoth);

			m_spriteSeamoth.setScale(0.2f, 0.2f);
			m_spriteSeamoth.setOrigin(m_textureSeamoth.getSize().x/2, m_textureSeamoth.getSize().y/2);
			m_spriteSeamoth.setPosition(m_x, m_y);
			m_spriteSeamoth.setRotation(m_angle);

			m_radAngle = m_angle/180*acos(-1);

			m_torpedo = new Torpedo[m_clip];
			for (int i = 0; i < m_clip; i++)
				m_torpedo[i].Active(false);

			return true;
		}

		// Задание скорости
		void SetVelocity(float dv)
		{
			if (m_dv >= m_maxSpeed)
				m_dv = m_maxSpeed;
			else
				m_dv += dv;

			if (m_dv <= -50)
				m_dv = -50;
		}

		// Поворот корабля и текстуры
		void Rotate(float angle)
		{
			m_angle += angle;
			m_radAngle = m_angle/180*acos(-1);
			m_spriteSeamoth.setRotation(m_angle);
		}

		// Стрельба
		void Shoot(float &time, int type) {
			switch(type)
			{
				case 1:
				{
					if ((m_ammo > 0) and time >= m_torpedoCD)
					{
						m_torpedo[m_clip-m_ammo].Setup(m_x, m_y, m_torpedotR,cos(m_radAngle)*(m_dv + m_torpedoSpeed),
												sin(m_radAngle)*(m_dv + m_torpedoSpeed),m_angle, m_torpedoLifeTime, true);
						m_ammo -= 1;
						time = 0;
					}
					break;
				}
				case 2:
				{
					if (time >= m_bulletCD)
					{
						m_bullet.push_back(new Bullet(m_x, m_y, m_bulletR,cos(m_radAngle)*(m_dv + m_bulletSpeed),
													  sin(m_radAngle)*(m_dv + m_bulletSpeed), m_bulletLifeTime, &m_textureBullet, true));
						time = 0;
					}
				}
			}

		}

		// Движение Мотылька и снарядов
		void Move(float dt) {

			// Ограничение перемещения Мотылька
			if (m_x <= 1920 and m_x >= 0)
				m_x += m_dv * cos(m_radAngle) * dt;
			else if (m_x < 0)
				m_x = 0;
			else
				m_x = 1920;

			if (m_y <= 1080 and m_y >= 0)
				m_y += m_dv * sin(m_radAngle) * dt;
			else if (m_y < 0)
				m_y = 0;
			else
				m_y = 1080;

			// lim(m_dv) --> 0
			if (m_dv >= 0.1)
				m_dv -= 2;
			else if(m_dv <= 0.1)
				m_dv += 1;
			else
				m_dv = 0;

			m_spriteSeamoth.setPosition(m_x, m_y);

			for (int i = 0; i < m_clip; i++)
			{
				if (m_torpedo[i].Active())
					m_torpedo[i].Move(dt);
			}
			for (int i = 0; i < m_bullet.size(); i++)
			{
				if (m_bullet[i]->Active())
					m_bullet[i]->Move(dt);
				else {
					delete m_bullet[i];
					m_bullet.erase(m_bullet.begin() + i);
				}
			}
		}

		void delBul()
		{
			m_bullet.clear();
		}

		// Геттеры
		float x() { return m_x; }
		void x(float x) { m_x = x; }

		float y() { return m_y; }
		void y(float y) { m_y = y; }

		float r() { return m_r; }

		int Clip() { return m_clip; }
		int Ammo() { return m_ammo; }
		void Ammo(int value) { m_ammo = value; }

		Torpedo& GetTorpedo(int i) { return m_torpedo[i]; }

		Bullet* GetBullet(int i) { return m_bullet[i]; }
		int numberBullets() { return m_bullet.size(); }

		sf::Sprite Get() { return m_spriteSeamoth; }

		~Seamoth()
		{
			for (int i = 0; i < m_bullet.size(); i++)
				delete m_bullet[i];
			delete[] m_torpedo;
		}
	};
}

#endif //INC_SUBSEA_SEAMOTH_HPP
