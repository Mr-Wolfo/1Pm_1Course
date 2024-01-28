#include <iostream>

int main() {

    int n;
    std::cin >> n;

    int tmp;
    int* a = new int[n];
    int* sum = new int[n];
    int* comp = new int[n];

    // Блок ввода последовательности
    for (int x = 0; x < n; x++)
        std::cin >> a[x];

    // Блок вычислений
    for (int i = 0; i < n; i++) {
        comp[i] = 1;
        sum[i] = 0;
        tmp = a[i];
        while (tmp) {
            comp[i] *= tmp % 10;
            sum[i] += tmp % 10;
            tmp /= 10;
        }
    }

    // Основной блок
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Условия
            if ((comp[i] > comp[j]) ||
                (comp[i] == comp[j] && sum[i] > sum[j]) ||
                (comp[i] == comp[j] && sum[i] == sum[j] && a[i] > a[j])) {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
                tmp = comp[i];
                comp[i] = comp[j];
                comp[j] = tmp;
                tmp = sum[i];
                sum[i] = sum[j];
                sum[j] = tmp;
            }
        }
    }

    //Блок вывода посл.
    for (int x = 0; x < n; x++) {
        std::cout << a[x] << " ";
    }

    delete[] a;
    delete[] sum;
    delete[] comp;
    return 0;
}