#include <iostream>
#include "src/ChoiceShape.cpp"

int main()
{
    int v; int N;

    // 1 - Круг, 2 - Треугольник, 3 - Прямоугольник, 4 - Линия
    // N - Кол-во
    std::cin >> v;
    std::cin >> N;

    wlf::ChoiceShape ms(v, N);
    ms.Display();

    return 0;
}