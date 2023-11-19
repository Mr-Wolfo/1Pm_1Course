#include <iostream>
#include <fstream>
#include <clocale>
#include "Func.hpp"

int main()
{
    setlocale(LC_ALL, "rus");
    std::ifstream in("assets/8_10_3.txt"); // ������������ cmake-build-debug/8_10_1.exe
    if (!in.is_open())
    {
        std::cout << "File error" << std::endl;
        return -1;
    }

    string words;
    string word;

    while (in >> word)
    {
        // ����� ������� ���� ������ � ��������� �������� ��������
        mt::doubLet(word);
        words.append(word);
    }

    in.close();

    // ����� ������ � ����
    std::ofstream out("complete/8_10_3.txt");
    out << words;
    out.close();
}