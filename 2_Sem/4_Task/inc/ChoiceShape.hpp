#ifndef INC_4_TASK_CHOICESHAPE_HPP
#define INC_4_TASK_CHOICESHAPE_HPP

#include "Circle.hpp"
#include "Triangle.hpp"
#include "Rectangle.hpp"
#include "Line.hpp"
#include <iostream>

namespace wlf
{
    class ChoiceShape
    {
        int m_v;
        int m_N;
        wlf::Circle* Cg;
        wlf::Triangle* Tg;
        wlf::Rectangle* Rg;
        wlf::Line* Lg;

    public:

        ChoiceShape(int v, int N)
        {
            m_v = v;
            m_N = N;
            switch(m_v)
            {
                case 1:
                {
                    Cg = new wlf::Circle[N];
                    m_Circle();
                    break;
                }
                case 2:
                {
                    Tg = new wlf::Triangle[N];
                    m_Triangle();
                    break;
                }
                case 3:
                {
                    Rg = new wlf::Rectangle[N];
                    m_Rectangle();
                    break;
                }

                case 4:
                {
                    Lg = new wlf::Line[N];
                    m_Line();
                    break;
                }

            }
        };

        void m_Circle()
        {
            srand(time(0));
            for (int i = 0; i < m_N; i++) {
                int x = rand() % 1000;
                int y = rand() % 700;
                int r = rand() % 100 + 1;
                Cg[i].Setup(x, y, r);
            }
        }

        void m_Triangle()
        {
            srand(time(0));
            for (int i = 0; i < m_N; i++) {
                int x = rand() % 1000;
                int y = rand() % 700;
                int r = rand() % 100 + 1;
                int t = rand() % (360 + 1);
                Tg[i].Setup(x, y, r, t);
            }
        }

        void m_Rectangle()
        {
            srand(time(0));
            for (int i = 0; i < m_N; i++) {
                int x = rand() % 1000;
                int y = rand() % 700;
                int t = rand() % (360 + 1);
                int len = rand() % (200 + 5);
                int wid = rand() % (200 + 5);
                Rg[i].Setup(x, y, t, len, wid);
            }
        }

        void m_Line()
        {
            srand(time(0));
            for (int i = 0; i < m_N; i++) {
                int x = rand() % 1000;
                int y = rand() % 700;
                int t = rand() % (360 + 1);
                int len = rand() % (300 + 25);
                Lg[i].Setup(x, y, t, len);
            }
        }

        void Display()
        {
            sf::RenderWindow window(sf::VideoMode(1000, 700), "4_Task");

            while (window.isOpen())
            {
                sf::Event event;
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        window.close();
                }

                window.clear();
                switch(m_v)
                {
                    case 1:
                        for (int i = 0; i < m_N; i++)
                            window.draw(Cg[i].Get());
                        break;
                    case 2:
                        for (int i = 0; i < m_N; i++)
                            window.draw(Tg[i].Get());
                        break;
                    case 3:
                        for (int i = 0; i < m_N; i++)
                            window.draw(Rg[i].Get());
                        break;
                    case 4:
                        for (int i = 0; i < m_N; i++)
                            window.draw(Lg[i].Get());
                        break;
                }
                window.display();
            }

        }

    };

}

#endif //INC_4_TASK_CHOICESHAPE_HPP
