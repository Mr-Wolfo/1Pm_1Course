#ifndef SUBSEA_ENEMYCLASS_HPP
#define SUBSEA_ENEMYCLASS_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Bullet.hpp"

namespace wlf
{
	class Enemy
	{
	protected:

		float m_maxSpeed = 500; // Максимальная скорость

		int m_bulletR = 10; // Размер пули
		float m_bulletSpeed = 400; // Скорость пули
		float m_bulletLifeTime = 5; // Время жизни пули (сек)
		float m_bulletCD = 3; // Время перезарядки пули (сек)

		bool m_active;

		float m_r = 80;
		float m_time = 0;
		float m_x, m_y;
		float m_dv = 200;
		float m_angle, m_radAngle;
		sf::Texture m_textureEnemy;
		sf::Sprite m_spriteEnemy;
		std::vector<Bullet*> m_bullet;
		sf::Texture m_textureBullet;

	public:

		bool Setup(float x, float y)
		{
			m_x = x;
			m_y = y;
			m_angle = 0;
			m_active = true;

			// Загрузка текстуры
			if (!m_textureEnemy.loadFromFile("assets\\Enemy.png"))
			{
				std::cout << "Error while loading Enemy.png" << std::endl;
				return false;
			}

			if (!m_textureBullet.loadFromFile("assets\\EnemyBullet.png"))
			{
				std::cout << "Error while loading EnemyBullet.png" << std::endl;
				return false;
			}

			m_spriteEnemy.setTexture(m_textureEnemy);

			m_spriteEnemy.setScale(0.15f, 0.15f);
			m_spriteEnemy.setOrigin(m_textureEnemy.getSize().x/2, m_textureEnemy.getSize().y/2);
			m_spriteEnemy.setPosition(m_x, m_y);
			m_spriteEnemy.setRotation(m_angle);

			m_radAngle = m_angle/180*acos(-1);

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



		virtual void Shoot()
		{
			m_bullet.push_back(new Bullet(m_x, m_y, m_bulletR,cos(m_radAngle)*(m_dv + m_bulletSpeed),
											  sin(m_radAngle)*(m_dv + m_bulletSpeed), m_bulletLifeTime, &m_textureBullet, true));
		}
		 void Move(float dt) {

			m_x += m_dv * cos(m_radAngle) * dt;
			m_y += m_dv * sin(m_radAngle) * dt;

			m_spriteEnemy.setPosition(m_x, m_y);

			m_time += dt;
			if(m_time > m_bulletCD)
			{
				Shoot();
				m_time = 0;
			}
			 MoveBullets(dt);
		}

		void MoveBullets(float dt)
		{
			for (int i = 0; i < m_bullet.size(); i++)
				if (m_bullet[i]->Active())
					m_bullet[i]->Move(dt);
				else {
					delete m_bullet[i];
					(m_bullet.erase(m_bullet.begin() + i));
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

		Bullet* GetBullet(int i) { return m_bullet[i]; }
		int numberBullets() { return m_bullet.size(); }

		sf::Sprite Get() { return m_spriteEnemy; }

		bool Active() { return m_active; }
		void Active(bool flag) { m_active = flag; }

		virtual ~Enemy()
		{
			for (int i = 0; i < m_bullet.size(); i++)
				delete m_bullet[i];
		}
	};
}

#endif //SUBSEA_ENEMYCLASS_HPP
