#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>

namespace wlf
{
    // Читает файл и считывает кол-во строк = кол-во предыдущих запусков + 1 (для исчисления порядкового номера)
    int readFile(const std::string& file)
    {
        std::ifstream in(file);
        int k = 0;
        if(in.is_open())
        {
            std::string tmp;

            while(!in.eof())
            {
                getline(in, tmp);
                k++;
            }
        }
        return k;
    }

    // Записывает в файл порядковый номер и дату/время.
    void writeFile(const std::string& file, int n)
    {
        // auto - автоматически "угадывает" тип переменной
        auto time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::tm tm = *std::localtime(&time);

        std::ofstream out(file, std::ios_base::app);
        // Преобразовывает секунды в привычное отображение
        out << n << " " << std::put_time(&tm, "%Y-%m-%d %H:%M:%S") << std::endl;
        out.close();
    }
}
