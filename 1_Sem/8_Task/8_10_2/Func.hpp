#pragma once
#ifndef h8Lab2_FUNC_HPP
#define h8Lab2_FUNC_HPP

using namespace std;

namespace mt {
    char my_tolower(char x);
    void tolower_main(string & word);
    void removeSigns(string & word);
    bool idenLet(string word);
    string vowelLet(string word);
    string cleanWord (string words);
    void sortWords(int size, string *str);
}

#endif //h8Lab2_FUNC_HPP
