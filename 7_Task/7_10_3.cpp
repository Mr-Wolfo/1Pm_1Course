#include <iostream>

int main() {
    int size_i, size_j;
    std::cin >> size_i >> size_j;
    int A[size_i][size_j];
    int col;
    int k;
    bool flag = true;

    for (int i = 0; i < size_i; i++)
        for (int j = 0; j < size_j; j++)
            std::cin >> A[i][j];

    for (int j = 0; j < size_j; j++) {

        int x = 0;

        for (int i = 0; i < size_i; i++) {

            if (A[i][j] % 10 != 3)
                x += 1;
        }

        if (flag) {
            col = x;
            flag = false;
        }

        if (x > col) {
            col = x;
            k = j;
        }

    }

    for (int j = 0; j < size_j; j++) {
        if (j == k)
            continue;
        for (int i = 0; i < size_i; i++)
            A[i][j] = -17;

    }

    for (int i = 0; i < size_i; i++) {
        for (int j = 0; j < size_j; j++)
            std::cout << A[i][j] << " ";
        std::cout << std::endl;
    }
}