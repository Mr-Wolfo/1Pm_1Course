#include <iostream>
#include <iomanip>

int main() {

    bool flag = false;
    char ch = 66;
    unsigned char unCh = 87;
    short int shin = -55;
    unsigned short int unShin = 55;
    int in = -16256;
    unsigned int unIn = 16256;
    long int loIn = -23020;
    unsigned long int unLoIn = 23020;
    long long int loLoIn = -123456789;
    unsigned long long int unLoLoIn = 123456789;
    float fl = 33.5462f;
    double dou = 4.34725432354;
    long double loDou = 4.347254323544287;

    std::cout << "bool: " << flag << " byte: " << sizeof(flag) << std::endl;
    std::cout << "char: " << ch << " byte: " << sizeof(ch) << std::endl;
    std::cout << "unsigned char: " << unCh << " byte: " << sizeof(unCh) << std::endl;
    std::cout << "short: " << shin << " byte: " << sizeof(shin) << std::endl;
    std::cout << "unsigned short: " << unShin << " byte: " << sizeof(unShin) << std::endl;
    std::cout << "int: " << in << " byte: " << sizeof(in) << std::endl;
    std::cout << "unsigned int: " << unIn << " byte: " << sizeof(unIn) << std::endl;
    std::cout << "long: " << loIn << " byte: " << sizeof(loIn) << std::endl;
    std::cout << "unsigned long: " << unLoIn << " byte: " << sizeof(unLoIn) << std::endl;
    std::cout << "long long: " << loLoIn << " byte: " << sizeof(loLoIn) << std::endl;
    std::cout << "unsigned long long: " << unLoLoIn << " byte: " << sizeof(unLoLoIn) << std::endl;
    std::cout << "float: " << fl << " byte: " << sizeof(fl) << std::endl;
    std::cout << "double: " << std::setprecision(16) << dou << " byte: " << sizeof(dou) << std::endl;
    std::cout << "long double: " << loDou << " byte: " << sizeof(loDou) << std::endl;

    return 0;

}
