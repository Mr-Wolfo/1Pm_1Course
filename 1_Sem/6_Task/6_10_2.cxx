#include <iostream>

int main()
{
	int N;
	std::cin >> N;
	
	int L;
	int count = 0;
	int k = 100;
	int number;
	int i = 0;
	
	for (i; i < 10; ++i) {
		L = N;
		while (L) {
			if (L % 10 == i)
				count++;
			L /= 10;
		}
		if (count != 0 && count < k) {
			k = count;
			number = i;
			}
		count = 0;
	}
	
	std::cout << number << std::endl;
	
}