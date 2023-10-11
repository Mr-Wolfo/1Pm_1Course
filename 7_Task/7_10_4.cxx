#include <iostream>
#include <cmath> // В Clain 'sqrt' не заработал без него, как было на паре ))

int main()
{
    int A[20'000];
    int n;
	std::cin >> n;
	int comp;
    int tmp;

    // Блок ввода посл.
	for (int i = 0; i < n; i++)
		std::cin >> A[i];

    // Блок поиска чисел по условию и их удаления
	for (int i = 0; i < n; i++) {
        comp = 1;
        tmp = A[i];
        while (tmp) {
            comp *= (tmp % 10);
            tmp /= 10;
        }
        if (comp % 70 == 0) {
            for (int j = i; j < n - 1; j++)
                A[j] = A[j + 1];
            n--;
        }
    }

    bool isPrime;
    // Поиск простых чисел и их дубликат
	for (int i = 0; i < n; i++) {
        isPrime = true;
        for (int x = 2; x <= sqrt(A[i]); x++) {
            if (A[i] % x == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            for (int j = n; j > i; j--)
                A[j] = A[j - 1];
            n++;
            i++;
        }
    }

    //Блок вывода посл.
    for (int x = 0; x < n; x++) {
        std::cout << A[x] << " ";
    }

    return 0;
}
