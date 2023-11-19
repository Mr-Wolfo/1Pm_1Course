#include <string>

using namespace std;

namespace mt
{
    // ��������� ��������
    char my_tolower (char x)
    {
        if (-65 <= x && x <= -33)
            return x + 32;
        else if (x == -88)
            return x + 16;
        else
            return x;
    }

    // for my_tolower
    void tolower_main(string & word)
    {
        for (int i = 0; i < word.size(); i++)
            word[i] = my_tolower(char(word[i]));
    }

    // �������� ����� �� ����������� ��������
    void removeSigns(string & word)
    {
        int count  = 0;
        for (int i = 0; i < word.size(); i++)
        {
            if((-32 <= word[i] && word[i] <= 0) || (word[i] == -72))
            {
                word[count] = word[i];
                count += 1;
            }
            else
                continue;
        }
        word = word.substr(0, count);
    }

    // ����� ���������� ����
    bool idenLet(string word)
    {
        for (int i = 0; i < word.size(); i++)
            for (int j = i + 1; j < word.size(); j++)
            {
                if (word[i] == word[j])
                    return false;
            }
        return true;
    }

    // ����� � �������� ���� ������� ����
    string vowelLet(string word)
    {
        string c[] = {"�", "�", "�", "�", "�", "�", "�", "�", "�", "�"};
        for (int i = 0; i < 10; i++)
        {
            while(word.find(c[i]) != string::npos)
            {
                word.erase(word.find(c[i]), 1);
            }
        }
        return word;
    }

    // ������� ������� �������
    string cleanWord (string str)
    {
        mt::tolower_main(str);
        mt::removeSigns(str);
        return str;
    }

    // ���������� � �������� ���. �������
    void sortWords(int size, string *str) {
        for (int i = 0; i < size; i++)
            for (int j = i + 1; j < size; j++)
            {
                if (str[i].compare(str[j]) == -1)
                    ::swap(str[i], str[j]);
            }
    }
}
