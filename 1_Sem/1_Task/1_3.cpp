#include <iostream>

int main() {

    unsigned char s = 2000; // в двочном -  0111 1101 0000, а запишется число 208


    /* В "unsigned char" может содержаться целое число от 0 до 255, если вводить число больше,
     * то произойдёт переполенение. Например для 256 - в переменную запишется число 0. Для 257 - 1, и т.д.
     * (Clion даже пишет об этом). Для числа побольше, допустим 2000 - будет 208.
     * Это происходит из-за того, что требуемое количество бит для числа не помещается в выделенную часть памяти.
     * Так, если в памяти также хранится знак числа - число может стать как отрицательным,
     * так и положительным, в зависимости от бита. Для положительных чисел доп. код такой же, как и прямой.
     * А для отрицательных - используется обратный код и к нему добавляется единица - так получается новое число
     * с учётом знака.
    */

    return 0;

}