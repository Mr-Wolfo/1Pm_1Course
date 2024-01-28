#include <iostream>
#include <clocale>
#include <sstream>
#include "Func.hpp"

int main()
{
    setlocale(LC_ALL, "rus");
    string str = "Задана некая <строка>. Побочные символы тоже -->";
    string noSame[2000]; // Нет одинаковых букв
    string noVow[2000]; // Без гласных
    int size1 = 0; // noSame[size]
    int size2 = 0; // noVow[size]
    string word;

    istringstream in(str);
    while (getline(in, word, ' '))
    {
        // Приводит слова в норму
        word = mt::cleanWord(word);

        // Распределение слов
        if (!word.empty())
        {
            if (mt::idenLet(word))
            {
                noSame[size1] = word;
                size1++;
            }
            else
            {
                noVow[size2] = mt::vowelLet(word);
                size2++;
            }
        }
    }

    // Сортировка в обратном алфавитном порядке
    mt::sortWords(size1, noSame);

    // Вывод результата | слова без повторяющихся букв в обратном алфавитном порядке порядке
    for (int i = 0; i < size1; i++)
        cout << noSame[i] << " ";

    cout << endl;
    // Слова с удалёнными гласными
    for (int i = 0; i < size2; i++)
        cout << noVow[i] << " ";

    return 0;
}