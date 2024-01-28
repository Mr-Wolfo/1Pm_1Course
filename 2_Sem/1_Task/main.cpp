#include <iostream>
#include "inc/Func.h"
#define FileName "StartTime.txt"

int main() {

    int count = wlf::readFile(FileName);

    wlf::writeFile(FileName, count);

    return 0;
}
