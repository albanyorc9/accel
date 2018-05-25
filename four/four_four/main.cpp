#include <iostream>
#include <iomanip>
#include <string>
#include "square.h"

int main()
{
    double required = 500;
    typedef std::string::size_type str_sz;
    str_sz ilen = std::to_string(required).length();
    str_sz sqlen = std::to_string(square(required)).length();

    for (double i = 0; i < required; i++){
        str_sz len = 1 + sqlen + (ilen - std::to_string(i).length());
        std::cout << i << std::setw(len) << square(i) << "\n";
    }
    std::cout << std::endl;
    return 0;
}
