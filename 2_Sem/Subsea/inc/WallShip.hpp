#ifndef SUBSEA_WALLSHIP_HPP
#define SUBSEA_WALLSHIP_HPP

#include "EnemyClass.hpp"

namespace wlf
{
	class WallShip : public Enemy
	{
	private:
		float m_side = 0;

	public:

		WallShip() = default;

		void WallCheck()
		{
			if(m_x > 1980)
				Logic(2);
			else if(m_x < -80)
				Logic(3);
			else if(m_y > 1150)
				Logic(4);
			else if(m_y < -80)
				Logic(1);
		}

		void Logic(int i)
		{
			switch(i)
			{
				case 1: {
					m_x = -80;
					m_y = 50;
					m_angle = 0;
					m_side = acos(-1)/2;
					m_spriteEnemy.setRotation(90);
					break;
				}
				case 2:
				{
					m_x = 1980;
					m_y = 1030;
					m_angle = 180;
					m_side = 3*acos(-1)/2;
					m_spriteEnemy.setRotation(270);
					break;
				}
				case 3:
				{
					m_x = 1870;
					m_y = -80;
					m_angle = 90;
					m_side = acos(-1);
					m_spriteEnemy.setRotation(180);
					break;
				}
				case 4:
				{
					m_x = 50;
					m_y = 1150;
					m_angle = 270;
					m_side = 0;
					m_spriteEnemy.setRotation(270);
					break;
				}
			}
		}

		void Shoot() override
		{
			{
				m_bullet.push_back(new Bullet(m_x, m_y, m_bulletR,cos(m_side)*(m_dv + m_bulletSpeed),
											  sin(m_side)*(m_dv + m_bulletSpeed), m_bulletLifeTime, &m_textureBullet,  true));
			}
		}

		void MoveCheck(float dt) {
			WallCheck();
			m_radAngle = m_angle/180*acos(-1);
			Move(dt);
		}

		virtual ~WallShip()
		{
			for (int i = 0; i < m_bullet.size(); i++)
				delete m_bullet[i];
		}
	};
}

#endif //SUBSEA_WALLSHIP_HPP
