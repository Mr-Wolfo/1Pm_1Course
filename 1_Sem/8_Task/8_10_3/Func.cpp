#include <string>
#include <cstring>
#include <iostream>

using namespace std;

namespace mt {

    // Понижение регистра буквы
    char my_tolower (char x)
    {
        if (-65 <= x && x <= -33)
            return x + 32;
        else if (x == -88)
            return x + 16;
        else
            return x;
    }

    // Повышение регистра буквы
    char my_toupper (char x)
    {
        if (-32 <= x && x <= 0)
            return x - 32;
        else if (x == -72)
            return x - 16;
        else
            return x;
    }

    // Поиск гласных подряд
    bool isVowel(char let)
    {
        char c[] {'э', 'а', 'о', 'у', 'ы', 'э', 'е', 'ё', 'и' , 'ю', 'я'};
        for (int i = 0; i < strlen(c); i++)
        {
            if (my_tolower(let) == c[i]) {
                return 1;
            }
        }
        return 0;
    }

    // Повышение регистра всего слова
    void upper(string & word)
    {
        for (int i = 0; i < word.size(); i++)
            word[i] = my_toupper(char(word[i]));
    }

    // Это буква?
    bool isLet(char x)
    {
        if (-65 <= x && x <= 0 || x == -88 || x == -72)
            return true;
        return false;
    }

    // Вставка скобки после слова, но до знаков препинания
    void insAfterWord(string & word, string tmp)
    {
        if (!tmp.empty())
        {
            tmp.insert(0, "(");
            tmp.insert(tmp.size(), ")");
            int i = word.size();
            while (i--)
                if (isLet(word[i]) == 1)
                {
                    mt::upper(word);
                    word.insert(i+1, tmp);
                    break;
                }
        }
    }

    // Основная функция обработки слова
    void doubLet (string & word)
    {
        int x = word.size();
        string tmp;
        for (int i = 1; i < x; i++)
        {
            if (mt::isVowel(word[i]) && word[i] == word[i-1])
            {
                tmp += word[i];;
            }
        }
        insAfterWord(word, tmp);
        word.append(" ");
    }
}