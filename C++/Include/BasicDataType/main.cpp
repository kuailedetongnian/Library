#include <iostream>
#include <stdio.h>
#include "BasicDataType.hpp"

int main() {
    wxh::Int a = 123;
    wxh::Int b = 421;
    wxh::Byte c = 0b11101010;
    std::cout << a + b << std::endl;
    for(int i = 0; i < 8; i++)
    {
        std::cout << c[i];
    }
    return 0;
}
