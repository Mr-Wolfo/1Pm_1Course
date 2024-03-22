#include "Launcher.hpp"

int main()
{
    wlf::Launcher Shapes(1000, 800);
    Shapes.Setup(10);

    Shapes.Life();

    return 0;
}