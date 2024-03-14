#include <iostream>

int main()
{
    int a = 1;
    int b = 3;


    int& ref;
    ref = b;

    std::cout << a << std::endl;
    std::cout << ref << std::endl;
}