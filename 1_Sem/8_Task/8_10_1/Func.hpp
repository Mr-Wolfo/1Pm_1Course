#pragma once
#ifndef HOMEWORK1_FUNC_HPP
#define HOMEWORK1_FUNC_HPP

namespace mt {
    bool symbolSearch(char* word, char* symbols);
    bool sameWords(char* word, char words[2000][50], int size);
    char my_tolower(char x);
    void tolower_main(char* word);
    void removeSigns(char* word);
    void sortLenWords(char words[2000][50], int size);
}

#endif //HOMEWORK1_FUNC_HPP
