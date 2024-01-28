#include <iostream>
#include <clocale>
#include <sstream>
#include "Func.hpp"

int main()
{
    setlocale(LC_ALL, "rus");
    string str = "������ ����� <������>. �������� ������� ���� -->";
    string noSame[2000]; // ��� ���������� ����
    string noVow[2000]; // ��� �������
    int size1 = 0; // noSame[size]
    int size2 = 0; // noVow[size]
    string word;

    istringstream in(str);
    while (getline(in, word, ' '))
    {
        // �������� ����� � �����
        word = mt::cleanWord(word);

        // ������������� ����
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

    // ���������� � �������� ���������� �������
    mt::sortWords(size1, noSame);

    // ����� ���������� | ����� ��� ������������� ���� � �������� ���������� ������� �������
    for (int i = 0; i < size1; i++)
        cout << noSame[i] << " ";

    cout << endl;
    // ����� � ��������� ��������
    for (int i = 0; i < size2; i++)
        cout << noVow[i] << " ";

    return 0;
}