#include <iostream>
#include <string>

int main()
{
    std::cout << "What is your name?: ";
    std::string name;
    std::cin >> name;

    std::cout << "Hello, " + name + ".\nAnd what is yours?: ";
    std::cin >> name;
    std::cout << "Hello, " + name + "; nice to meet you two!" << std::endl;
    return 0;
}
