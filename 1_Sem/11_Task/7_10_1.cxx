#include <iostream>

int main()
{
	int n;
	std::cin >> n;

    int* a = new int[n];
	int tmp;
	bool flag = true;
	
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
			flag = false;
	}

	// Блок сортировки
	if (flag) {
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

    delete[] a;
	return 0;

}