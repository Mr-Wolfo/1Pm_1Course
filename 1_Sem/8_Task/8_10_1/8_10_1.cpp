#include <iostream>
#include <fstream>
#include <cstring>
#include <clocale>
#include "Func.hpp"

int main() {
    setlocale(LC_ALL, "rus");
    std::ifstream in("assets/8_10_1.txt"); // относительно cmake-build-debug/8_10_1.exe
    if (!in.is_open()) {
        std::cout << "File error" << std::endl;
        return -1;
    }

    char words[2000][50];
    int size = 0; // далее words[size]
    char symbols[3] = {-32, -31, -30}; // {а, б, в} Буквы, которые НЕ должны присутствовать в словах. Clain...
    char word[50];

    // Отбор слов в массив
    while (in >> word) {
        mt::tolower_main(word);
        mt::removeSigns(word);
        // std::cout << "--> " << word << std::endl;  Для ручной проверки обработки считываемых данных
        if ((mt::symbolSearch(word, symbols)) && (mt::sameWords(word, words, size))) {
            strcpy(words[size], word);
            size++;
        }
    }

    in.close();

    // Сортировка
    mt::sortLenWords(words, size);

    // Вывод данных в файл
    std::ofstream out("complete/8_10_1.txt");
    for (int i = 0; i < size; i++)
        out << words[i] << " "; // Если построчно, то вместо " " -- std::endl
    out.close();

    return 0;
}
