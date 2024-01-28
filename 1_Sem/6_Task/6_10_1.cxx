#include <iostream>

int main()
{
	
	int j; //кол-во чисел в последовательности
	int sum = 0;
	int min;
	int i; //номер мин. числа ≠ ...1
	int x;
	int count = 1; //номер числа в последовательности
	bool flag = true;
	
	std::cin >> j;
	

	while (j)
	{
		std::cin >> x;
		
		if (flag == true) {
			min = x;
			flag = false;
		}
		
		if (x % 10 != 1) {
			sum += x;
			
			if (x < min) {
				min = x;
				i = count;
				}
			}
			
		count++;
		j--;
		
		}
	
	std::cout << "Сумма: " << sum << std::endl;
	std::cout << "Минимальное:  " << min << " | Его номер: " << i << std::endl;
	
	return 0;
		
}