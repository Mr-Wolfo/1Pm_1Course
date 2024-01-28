#include <iostream>

int main()
{
	setlocale(LC_ALL, "RUS");
	int N;
	
	std::cin >> N;
	
	switch(N)
	{
		case 1:std::cout << "SSD M.2 256 GB";
			break;
		case 2:std::cout << "Термопаста 10 г.";
			break;
		case 3:std::cout << "Видеокарта GT1030 2GB";
			break;
		case 4:std::cout << "ОЗУ SO-DIMM 8 GB ×2";
			break;
		case 5:std::cout << "Коврик для мыши";
			break;
		default:std::cout << "Неверный идентификатор товара.";
	}
	
	return 0;
}