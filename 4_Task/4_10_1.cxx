#include <iostream>

int main()
{
	unsigned int A;
	unsigned int B;
	unsigned int C;
	
	std::cin >> A >> B >> C;
	
	if ( (A + B) % C == 0 && C % B == 0)
		std::cout << (A+B) / C - C / B << std::endl;
	else if ( (A + B) % C == 0 && C % B != 0)
		std::cout << (A+B) / C + B * C << std::endl;
	else 
		std::cout << A+B+C << std::endl;
		
	return 0;
	
}