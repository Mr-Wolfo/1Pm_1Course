#ifndef SUBSEA_FOLLOWSHIP_HPP
#define SUBSEA_FOLLOWSHIP_HPP

#include "EnemyClass.hpp"

namespace wlf
{
	class FollowShip : public Enemy
	{
	private:
		sf::Texture m_textureEnemyInvis;
		bool m_visible = true;
		float m_invisTime = 5;
		float m_invisCD = 10;
		float m_clock = 0;

	public:

		FollowShip() = default;

		void Spawn(float x)
		{
			if (!m_textureEnemyInvis.loadFromFile("assets\\EnemyInvis.png"))
			{
				std::cout << "Error while loading EnemyInvis.png" << std::endl;
				exit(-1);
			}
			m_dv = 100;
			if (x > 1920/2)
				Setup(-80, 1080/2);
			else
				Setup(2000, 1080/2);
		}

		void Logic(float time)
		{
			m_clock += time;
			if ((m_clock > m_invisCD) and m_visible)
			{
				m_spriteEnemy.setTexture(m_textureEnemyInvis);
				m_visible = false;
				m_clock = 0;
			}
			else if (m_clock > m_invisTime and !m_visible)
			{
				m_spriteEnemy.setTexture(m_textureEnemy);
				m_visible = true;
				m_clock = 0;
			}
		}

		void Rotate(float x, float y)
		{
			x = (x - m_x);
			y = (y - m_y);
			m_radAngle = atan2(y, x);
			m_angle = m_radAngle/acos(-1)*180;
			m_spriteEnemy.setRotation(m_angle);
		}

		void MoveCheck(float dt, float x, float y) {
			Rotate(x, y);
			Logic(dt);
			Move(dt);
		}

		virtual ~FollowShip()
		{
			for (int i = 0; i < m_bullet.size(); i++)
				delete m_bullet[i];
		}
	};
}

#endif //SUBSEA_FOLLOWSHIP_HPP
