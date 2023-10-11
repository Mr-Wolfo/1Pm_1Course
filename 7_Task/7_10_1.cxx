#include <iostream>

int main()
{
    int a[10'000];
	int n;
	std::cin >> n;

	int tmp;
	bool flag = false;
	
	// Блок ввода последовательности
	for (int j = 0; j<n; j++)
			std::cin >> a[j];
	
	// Блок суммы цифр чисел посл.
	for (int j = 0; j<n; j++) {
        int num = 0;
		tmp = a[j];
		while (tmp) {
			num += tmp % 10;
			tmp /= 10;
		}
		if (num == 12)
			flag = true;
	}

	// Блок сортировки
	if (flag != true) {
		for (int i = 0; i<n; i++) {
			for (int j = i+1; j<n; j++)
				if (a[i]>a[j]) {
					tmp = a[i];
					a[i] = a[j];
					a[j] = tmp;
				}
		}
	}

	//Блок вывода посл.
	for (int j = 0; j < n; j++) {
			std::cout << a[j] << " ";
	}

	return 0;

}