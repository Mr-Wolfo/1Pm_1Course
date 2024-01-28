#include <iostream>
#include <cmath>

class Cone {

    int m_r, m_h;
    double m_l;

public:
    Cone() = default;
    Cone(int r, int h)
    {
        setR(r);
        setH(h);
        m_l = sqrt(r*r + h*h);

    }

    void setR(int r)
    {
        if (r <= 0)
            std::cout << "Неверное значение" << std::endl;
        m_r = r;
    }
    void setH(int h)
    {
        if (h <= 0)
            std::cout << "Неверное значение" << std::endl;
        m_h = h;
    }

    double Square()
    {
        return (M_PI * m_r * (m_r + m_l));
    }
    double Volume()
    {
        return (1.0/3 * M_PI * pow(m_r, 2) * m_h);
    }
};

int main ()
{
    Cone x(3, 4);
    std::cout << x.Square() << std::endl;
    std::cout << x.Volume() << std::endl;

    return 1;
}