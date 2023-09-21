#include <iostream>

int main()
{
	short x;
	std::cin >> x;
	
	std::cout << (x == -1 ? "Negative number": "Positive number");

	return 0;
}

/*
В данном случае тернарный оператор сокращает код значительно, в отличие от конструкций switch-case / if-else. Но при условии, что "x" заведомо не может быть отличным от значений -1/1.

Вот код на switch-case:

switch(x)
	{
		case -1:std::cout << "Negative number";
		break;
		case 1:std::cout << "Positive number";
		break;
		default:std::cout << "Error";
	}
*/