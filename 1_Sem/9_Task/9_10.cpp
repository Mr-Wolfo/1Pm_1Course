#include "Func.hpp"

int main() {

    int A[100][100];
    int size;

    // Ввод матрицы
    size = mt::inputMatrix(A);

    // Обработка матрицы
    if (mt::contain(A, size))
        for (int i = 0; i < size; i++)
            mt::sortMatrix (A[i], size);

    // Вывод матрицы
    mt::outputMatrix(A, size);
}
