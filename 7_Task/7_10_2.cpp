#include <iostream>

int main() {
    int size;
    std::cin >> size;
    int a[size];
    int ci, cj;
    int comp_i, comp_j;
    int sum_i, sum_j;
    int tmp;

    // Блок ввода последовательности
    for (int x = 0; x<size; x++)
        std::cin >> a[x];

    for (int i = 0; i<size; i++) {
        for (int j = i+1; j<size; j++) {
                comp_i = 1;
                comp_j = 1;
                sum_i = 0;
                sum_j = 0;
                ci = a[i];
                cj = a[j];
                while (ci) {
                    comp_i *= ci % 10;
                    sum_i += ci % 10;
                    ci /= 10;
                }
                while (cj) {
                    comp_j *= cj % 10;
                    sum_j += cj % 10;
                    cj /= 10;
                }
                if (comp_i > comp_j) {
                    tmp = a[i];
                    a[i] = a[j];
                    a[j] = tmp;
                }
                else if (comp_i == comp_j && sum_i > sum_j) {
                    tmp = a[i];
                    a[i] = a[j];
                    a[j] = tmp;
                }
                else if (a[i] > a[j]){
                    tmp = a[i];
                    a[i] = a[j];
                    a[j] = tmp;
                }
        }
    }

    //Блок вывода посл.
    for (int x = 0; x<size; x++) {
        std::cout << a[x] << " ";
    }

}