#include <iostream>

int main() {

    int A[100][100];
    int n, m;
    std::cin >> n >> m;

    int max_count;
    int column;
    bool flag = true;

    // Блок ввода матрицы
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            std::cin >> A[i][j];

    // Поиск столбца с меньшим кол-вом чисел % 10 == 3
    for (int j = 0; j < m; j++) {
        // Поиск кол-во чисел % 10 != 3
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (A[i][j] % 10 != 3)
                count += 1;
        }
        if (flag) {
            max_count = count;
            flag = false;
        }
        if (count > max_count) {
            max_count = count;
            column = j;
        }
    }

    // Блок замены элементов на -17
    for (int j = 0; j < m; j++) {
        if (j == column)
            continue;
        for (int i = 0; i < n; i++)
            A[i][j] = -17;
    }

    // Блок вывода матрицы
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            std::cout << A[i][j] << " ";
        std::cout << std::endl;
    }

    return 0;
}