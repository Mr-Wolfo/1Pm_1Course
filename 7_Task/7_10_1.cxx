#include <iostream>

int main()
{
	int size;
	std::cin >> size;
	int num = 0;
	int a[size];
	int tmp;
	int cl;
	bool flag = false;
	
	// Блок ввода последовательности
	for (int j = 0; j<size; j++)
			std::cin >> a[j];
	
	// Блок суммы цифр чисел посл.
	for (int j = 0; j<size; j++) {
		cl = a[j];
		while (cl) {
			num += cl % 10;
			cl /= 10;
		}
		if (num == 12)
			flag = true;
		num = 0;
	}
	
	// Блок сортировки
	if (flag != true) {
		for (int i = 0; i<size; i++) {
			for (int j = i+1; j<size; j++)
				if (a[i]>a[j]) {
					tmp = a[i];
					a[i] = a[j];
					a[j] = tmp;
				}
		}
	}
	
	//Блок вывода посл.
	for (int j = 0; j<size; j++) {
			std::cout << a[j] << " ";
	}
	
	return 0;
	
}