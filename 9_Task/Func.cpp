#include <iostream>
#include <cmath>

namespace mt
{
    // Ввод матрицы и её размеров
    int inputMatrix(int A[100][100])
    {
        int size;
        std::cin >> size;
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                std::cin >> A[i][j];
        return size;
    }

    // Проверка числа на простоту
    bool isPrime(int c) {
        if (c < 0) // Отрицательные числа не простые
            return false;
        for (int x = 2; x <= sqrt(c); x++)
        {
            if (c % x == 0)
                return false;
        }
        return true;
    }

    // Проверка на содержание столбца без простых чисел и суммой элементов == 0
    bool contain(int A[100][100], int size)
    {
        bool Prime;
        int sum;
        for (int j = 0; j < size; j++)
        {
            sum = 0;
            for (int i = 0; i < size; i++)
            {
                Prime += mt::isPrime(A[i][j]);
                sum += A[i][j];
            }
            if (!Prime && sum == 0)
                return true;
        }
        return false;

    }

    // Сортировка элементов строк по модулю числа
    void sortMatrix (int A[100], int size)
    {
        for (int i = 0; i < size; i++)
            for (int j = i + 1; j < size; j++)
            if (abs(A[i]) < abs(A[j]))
                std::swap(A[i], A[j]);
    }

    // Вывод матрицы в консоль
    void outputMatrix(int A[100][100], int size)
    {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++)
                std::cout << A[i][j] << " ";
            std::cout << std::endl;
        }
    }
}