#include <iostream>

class String {
    char *str;
    int m_len;

public:
    // Конструктор
    String(int len) {
        m_len = len;
        str = new char[len];
    }

    // Конструктор копирования
    String(const String &other) : String(other.m_len) {
        for (int i = 0; i < m_len; i++)
            str[i] = other.str[i];
    }

    // Оператор присваивания
    String &operator=(const String &other) {
        delete[] str;
        m_len = other.m_len;

        str = new char[m_len];
        for (int i = 0; i < m_len; i++)
            str[i] = other.str[i];

        return *this;
    }

    void StrOut() {
        std::cout << m_len << std::endl;
    }

    // Деструктор
    ~String() {
        delete[] str;
    }
};

int main ()
{
    String A(5);
    A.StrOut();
    String B(11);
    B.StrOut();

    B = A;
    B.StrOut();

    String C(B);
    C.StrOut();

    return 1;
}