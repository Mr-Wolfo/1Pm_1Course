#ifndef SUBSEA_LAUNCHER_HPP
#define SUBSEA_LAUNCHER_HPP

#include <SFML/Graphics.hpp>
#include "Bubble.hpp"
#include <string>
#include <iostream>
#include <thread>
#include <cmath>
#include "Seamoth.hpp"
#include "Torpedo.hpp"
#include "UI.hpp"
#include "WallShip.hpp"
#include "FollowShip.hpp"

namespace wlf {

	class Launcher {
	private:
		bool **m_hit;
		int m_width;
		int m_height;
		wlf::Bubble *m_c;
		int m_n;
		float m_timeSpawnEnemyWall = 0;
		float m_timeSpawnEnemyFollow = 0;
		int m_score = 0;

		sf::RenderWindow m_window;
		sf::Texture m_textureBackground;
		sf::Sprite m_spriteBackground;
		Seamoth m_ship;
		UI m_ui;
		WallShip m_enemyWall;
		FollowShip m_enemyFollow;


	public:
		Launcher(int width, int height) {
			m_width = width;
			m_height = height;
		}

		bool Setup(int n) {

			m_n = n;

			m_hit = new bool *[m_n];
			for (int i = 0; i < m_n; i++)
				m_hit[i] = new bool[m_n];

			for (int i = 0; i < m_n - 1; i++)
				for (int j = i + 1; j < m_n; j++)
					m_hit[i][j] = true;

			m_window.create(sf::VideoMode(m_width, m_height), "Subnautica 2");
			m_window.setFramerateLimit(144);

			// Загрузка текстуры фона
			if (!m_textureBackground.loadFromFile("assets\\background.jpg")) {
				std::cout << "Error while loading background.jpg" << std::endl;
				return false;
			}
			m_spriteBackground.setTexture(m_textureBackground);

			// Создание Мотылька
			if (!m_ship.Setup(1920/2, 1080/2))
				return false;

			m_c = new wlf::Bubble[m_n];

			srand(time(0));
			for (int i = 0; i < m_n; i++)
				SetupBubble(m_c[i]);

			m_ui.Setup();
			m_ui.ViewAmmo();
			m_ui.ViewScore(m_score);

			m_enemyWall.Setup(0, -81);
			m_enemyFollow.Spawn(m_ship.x());

			return true;
		}

		void SetupBubble(Circle &obj)
		{
			int r = rand() % 60 + 40;
			int x = rand() % (1000 - 2 * r) + r;
			int y = rand() % (800 - 2 * r) + r;
			int dx = (rand() % 200);
			int dy = (rand() % 200);
			obj.Setup(x, y, r, dx, dy);
		}

		bool TouchBorder(Circle &obj) {
			float x = obj.x();
			float y = obj.y();
			float r = obj.R();
			bool flag = false;

			if (x + r >= m_width || x - r <= 0) {
				obj.dx(-obj.dx());
				flag = true;
			}
			if (y + r >= m_height || y - r <= 0) {
				obj.dy(-obj.dy());
				flag = true;
			}
			return flag;
		}

		// Для пузырей var = 0, только расстояние var = 2, остальные случаи var = 1
		bool TouchObject(Circle &obj, Circle &obj2, int var, int i, int j) {
			float x1 = obj.x();
			float y1 = obj.y();
			float r1 = obj.R();
			float dx1 = obj.dx();
			float dy1 = obj.dy();

			float x2 = obj2.x();
			float y2 = obj2.y();
			float r2 = obj2.R();
			float dx2 = obj2.dx();
			float dy2 = obj2.dy();

			bool flag = false;

			// Расстояние между объектами
			float Dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

			// Определение Только столкновения
			if (var == 2) {
				if (Dist <= (r1 + r2))
					flag = true;
			}

			// Отталкивание
			else if ((Dist <= (r1 + r2)) and (m_hit[i][j] + var))
			{
				float Dx = x2 - x1;
				float Dy = y2 - y1;

				float s = Dx / Dist;
				float e = Dy / Dist;

				float Vn1 = dx2 * s + dy2 * e;
				float Vn2 = dx1 * s + dy1 * e;
				float Vt1 = -dx2 * e + dy2 * s;
				float Vt2 = -dx1 * e + dy1 * s;

				float temp = Vn2;
				Vn2 = Vn1;
				Vn1 = temp;

				dx1 = Vn2 * s - Vt2 * e;
				dy1 = Vn2 * e + Vt2 * s;
				dx2 = Vn1 * s - Vt1 * e;
				dy2 = Vn1 * e + Vt1 * s;

				obj.dx(dx1);
				obj.dy(dy1);
				obj2.dx(dx2);
				obj2.dy(dy2);

				flag = true;
			}

			// Для пузырей
			if (var == 0) {
				if (Dist < (r1 + r2))
					m_hit[i][j] = false;
				else
					m_hit[i][j] = true;
			}
			return flag;
		}

		bool Life() {
			float time = 5;
			sf::Clock clock;
			while (m_window.isOpen()) {
				sf::Event event;
				while (m_window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed) {
						m_window.close();
					}
				}

				float dt = clock.getElapsedTime().asSeconds();
				clock.restart();

				if (time < 5)
					time += dt;

				// Клавиатура
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
					m_ship.SetVelocity(4);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
					m_ship.SetVelocity(-4);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
					m_ship.Rotate(-1.5);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
					m_ship.Rotate(1.5);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
					m_ship.Shoot(time, 1);
					m_ui.ViewAmmo();
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
						m_ship.Shoot(time, 2);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
					m_ship.Ammo(8);
					m_ui.ViewAmmo();
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
					m_window.close();
					return true;
				}

				// Пузыри
				for (int i = 0; i < m_n; i++) {
					m_c[i].Move(dt);
				}

				// Пули
				for (int i = 0; i < m_ship.numberBullets(); i++)
				{
					if (m_ship.GetBullet(i)->Active()) {
						TouchBorder(*m_ship.GetBullet(i));
						for (int j = 0; j < m_n; j++) {
							if(TouchObject(*m_ship.GetBullet(i), m_c[j], 1, 0, 0))
								m_c[j].Setup(0, 0, 0, 0, 0);
						}
						if(m_enemyWall.Active())
							if (sqrt(pow(m_enemyWall.x() - m_ship.GetBullet(i)->x(), 2)
							+ pow(m_enemyWall.y() - m_ship.GetBullet(i)->y(), 2)) < m_ship.GetBullet(i)->R() + m_enemyWall.r())
							{
								m_enemyWall.Active(false);
								m_score += 1;
								m_ui.ViewScore(m_score);
							}
						if(m_enemyFollow.Active())
							if (sqrt(pow(m_enemyFollow.x() - m_ship.GetBullet(i)->x(), 2)
								 + pow(m_enemyFollow.y() - m_ship.GetBullet(i)->y(), 2)) < m_ship.GetBullet(i)->R() + m_enemyFollow.r())
							{
								m_enemyFollow.Active(false);
								m_score += 1;
								m_ui.ViewScore(m_score);
							}
					}
				}

				for (int i = 0; i < m_enemyWall.numberBullets(); i++)
				{
					if (m_enemyWall.GetBullet(i)->Active()) {
						TouchBorder(*m_enemyWall.GetBullet(i));
						if (sqrt(pow(m_ship.x() - m_enemyWall.GetBullet(i)->x(), 2)\
						+ pow(m_ship.y() - m_enemyWall.GetBullet(i)->y(), 2)) < m_enemyWall.GetBullet(i)->R() + m_ship.r())
						{
							// УНичтожение корабля игрока --> перезапуск
							m_ship.delBul();
							m_enemyWall.delBul();
							m_enemyFollow.delBul();
							m_score = 0;
							return false;
						}
						for (int j = 0; j < m_n; j++) {
							TouchObject(*m_enemyWall.GetBullet(i), m_c[j], 1, 0, 0);
						}
					}
				}

				for (int i = 0; i < m_enemyFollow.numberBullets(); i++)
				{
					if (m_enemyFollow.GetBullet(i)->Active()) {
						TouchBorder(*m_enemyFollow.GetBullet(i));
						if (sqrt(pow(m_ship.x() - m_enemyFollow.GetBullet(i)->x(), 2)
						+ pow(m_ship.y() - m_enemyFollow.GetBullet(i)->y(), 2)) < m_enemyFollow.GetBullet(i)->R() + m_ship.r())
						{
							// УНичтожение корабля игрока --> перезапуск
							m_ship.delBul();
							m_enemyWall.delBul();
							m_enemyFollow.delBul();
							m_score = 0;
							return false;
						}
						for (int j = 0; j < m_n; j++) {
							TouchObject(*m_enemyFollow.GetBullet(i), m_c[j], 1, 0, 0);
						}
					}
				}

				// Торпеды
				for (int i = 0; i < m_ship.Clip(); i++)
				{
					if (m_ship.GetTorpedo(i).Active()) {
						if (TouchBorder(m_ship.GetTorpedo(i)))
							m_ship.GetTorpedo(i).Rotate(atan2(m_ship.GetTorpedo(i).dy(),
															  m_ship.GetTorpedo(i).dx()) * 180 / acos(-1));
						for (int j = 0; j < m_n; j++)
							if (TouchObject(m_ship.GetTorpedo(i), m_c[j], 2, 0, 0))
							{
								m_ship.GetTorpedo(i).Rotate(atan2(m_ship.GetTorpedo(i).dy(),
																  m_ship.GetTorpedo(i).dx()) * 180 / acos(-1));
								m_c[j].Setup(0, 0, 0, 0, 0);
							}
					}
				}

				// Обработка столкновения пузырей
				for (int i = 0; i < m_n; i++) {
					TouchBorder(m_c[i]);
					for (int j = i + 1; j < m_n; j++)
							TouchObject(m_c[i], m_c[j], 0, i, j);
				}

				// Спавн врагов
				if (m_enemyWall.Active())
					m_enemyWall.MoveCheck(dt);
				else if(m_timeSpawnEnemyWall > 15)
				{
					m_enemyWall.Setup(0, -81);
					m_timeSpawnEnemyWall = 0;
				}
				else
				{
					m_timeSpawnEnemyWall += dt;
					m_enemyWall.MoveBullets(dt);
				}

				if(m_enemyFollow.Active())
					m_enemyFollow.MoveCheck(dt, m_ship.x(), m_ship.y());
				else if(m_timeSpawnEnemyFollow > 15)
				{
					m_enemyFollow.Spawn(m_ship.x());
					m_timeSpawnEnemyFollow = 0;
				}
				else
				{
					m_timeSpawnEnemyFollow += dt;
					m_enemyFollow.MoveBullets(dt);
				}

				m_ship.Move(dt);

				m_window.clear();

				m_window.draw(m_spriteBackground);

				for (int i = 0; i < m_ship.Clip()-m_ship.Ammo(); i++)
				{
					if (m_ship.GetTorpedo(i).Active())
						m_window.draw(m_ship.GetTorpedo(i).Get());
				}
				for (int i = 0; i < m_ship.numberBullets(); i++)
					if (m_ship.GetBullet(i)->Active())
						m_window.draw(m_ship.GetBullet(i)->Get());

				for (int i = 0; i < m_enemyWall.numberBullets(); i++)
					if (m_enemyWall.GetBullet(i)->Active())
						m_window.draw(m_enemyWall.GetBullet(i)->Get());

				for (int i = 0; i < m_enemyFollow.numberBullets(); i++)
					if (m_enemyFollow.GetBullet(i)->Active())
						m_window.draw(m_enemyFollow.GetBullet(i)->Get());


				if (m_enemyWall.Active())
					m_window.draw(m_enemyWall.Get());
				if (m_enemyFollow.Active())
					m_window.draw(m_enemyFollow.Get());

				m_window.draw(m_ship.Get());

				for (int i = 0; i < m_n; i++) {
					m_window.draw(m_c[i].Get());
				}

				m_window.draw(*m_ui.Get(0)->Get());
				m_window.draw(*m_ui.Get(1)->Get());

				m_window.display();
			}
		}

		~Launcher()
		{
			delete[] m_c;
			for (int i = 1; i < m_n; i++)
				delete[] m_hit[i];
			delete[] m_hit;
		}
	};
}

#endif //SUBSEA_LAUNCHER_HPP
