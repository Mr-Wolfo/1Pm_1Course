#ifndef INC_5_TASK_LAUNCHER_HPP
#define INC_5_TASK_LAUNCHER_HPP

#include <SFML/Graphics.hpp>
#include "Circle.hpp"
#include <string>
#include <iostream>
#include <thread>
#include <cmath>

namespace wlf {

	class Launcher {
	private:
        bool** m_hit;
		int m_width;
		int m_height;
		wlf::Circle* m_c;
		int m_n;
		sf::RenderWindow m_window;

	public:
		Launcher(int width, int height) {
			m_width = width;
			m_height = height;
		}

		void Setup(int n) {

			m_n = n;

            m_hit = new bool* [m_n];
            for (int i = 0; i < m_n; i++)
                m_hit[i] = new bool [m_n];

            for (int i = 0; i < m_n-1; i++)
                for (int j = i + 1; j < m_n; j++)
                    m_hit[i][j] = true;

			m_window.create(sf::VideoMode(m_width, m_height), "Task_5");

			m_c = new wlf::Circle[m_n];

			srand(time(0));
			for (int i = 0; i < m_n; i++) {
				int r = rand() % 60 + 40;
				int x = rand() % (1000 - 2*r) + r;
				int y = rand() % (800 - 2*r) + r;
				int dx = (rand() % 200);
				int dy = (rand() % 200);
				m_c[i].Setup(x, y, r, dx, dy);
			}
		}

		void TouchBorder(Circle& obj) 
		{
			float x = obj.X();
			float y = obj.Y();
			float r = obj.R();

			if (x + r >= m_width || x - r <= 0) {
				obj.dx(obj.dx());
			}
			if (y + r >= m_height || y - r <= 0) {
				obj.dy(obj.dy());
			}
		}

		void TouchCircle(Circle& obj, Circle& obj2, int i, int j)
        {
			float x1 = obj.X();
			float y1 = obj.Y();
            float r1 = obj.R();
            float dx1 = obj.dx();
            float dy1 = obj.dy();

			float x2 = obj2.X();
			float y2 = obj2.Y();
			float r2 = obj2.R();
			float dx2 = obj2.dx();
			float dy2 = obj2.dy();

            // Расстояние между шарами
			float Dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

            // Отталкивание
			if ((Dist < (r1 + r2)) and m_hit[i][j])
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

				obj.DX(dx1);
				obj.DY(dy1);
				obj2.DX(dx2);
				obj2.DY(dy2);
			}

            // Готовность к следующему столкновению
            if (Dist < (r1 + r2))
                m_hit[i][j] = false;
            else
                m_hit[i][j] = true;
		}

		void Life()
		{
			sf::Clock clock;
			while (m_window.isOpen())
			{
				sf::Event event;
				while (m_window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed) {
						m_window.close();
					}
				}

				float dt = clock.getElapsedTime().asSeconds();
				clock.restart();

				for (int i = 0; i < m_n; i++) {
					m_c[i].Move(dt);
				}

				for (int i = 0; i < m_n; i++) {
					TouchBorder(m_c[i]);
                    for (int j = i + 1; j < m_n; j++)
                        TouchCircle(m_c[i], m_c[j], i, j);
				}

				m_window.clear();
				for (int i = 0; i < m_n; i++) {
					m_window.draw(m_c[i].Get());
				}
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

#endif //INC_5_TASK_LAUNCHER_HPP
