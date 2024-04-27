#include "Launcher.hpp"

bool Start(wlf::Launcher* Shapes)
{
	Shapes->Setup(15);
	if(!Shapes->Life())
		return true;
	else
		return false;
}


int main()
{
    wlf::Launcher Shapes(1920, 1080);

	bool flag = true;

	while(flag)
		flag = Start(&Shapes);

    return 0;
}

