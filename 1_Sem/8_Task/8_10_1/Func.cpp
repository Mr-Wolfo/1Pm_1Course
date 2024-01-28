#include <cstring>

namespace mt {
    // Поиск символов в слове
    bool symbolSearch(char *word, char *symbols) {
        for (int j = 0; j < 3; j++) {
            if (strchr(word, symbols[j]) != nullptr) { // Если символ имеется в строке, то выдаёт адрес
                return false;
            }
        }
        return true;
    }

    // Поиск одинаковых слов
    bool sameWords(char* word, char words[2000][50], int size) {
        for (int i = 0; i < size; i++) {
            if ((strcmp(word, words[i])) == 0){
                return false;
            }
        }
        return true;
    }

    // Понижение регистра
    char my_tolower (char x) {
        if (-65 <= x && x <= -33) {
            return x + 32;
        }
        else if (x == -88)
            return x + 16;
        return x;
    }

    // for tolower
    void tolower_main(char* word)
    {
        for (int i = 0; i < strlen(word); i++) {
            word[i] = my_tolower(word[i]);
        }
    }

    // Очищение слова от посторонних символов
    void removeSigns(char* word) {
        int count  = 0;
        for (int i = 0; i < strlen(word); i++) {
            if((-32 <= word[i] && word[i] <= 0) || (word[i] == -72)) {
                word[count] = word[i];
                count += 1;
            }
            else
                continue;
        }
        word[count] = '\0';
    }

    // Сортировка по длине слов
    void sortLenWords(char words[2000][50], int size) {
        for (int i = 0; i < size; i++)
            for (int j = i + 1; j < size; j++) {
                if (strlen(words[i]) < strlen(words[j])) {
                    char tmp[50];
                    strcpy(tmp, words[i]);
                    strcpy(words[i], words[j]);
                    strcpy(words[j], tmp);
                }
            }
    }
}
