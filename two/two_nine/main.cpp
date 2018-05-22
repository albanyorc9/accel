#include <iostream>

int main()
{
    std::cout << "Enter the first number: ";
    int num_one;
    std::cin >> num_one;

    std::cout << "Enter the second number: ";
    int num_two;
    std::cin >> num_two;

    if(num_one >= num_two){
        std::cout << num_one << " >= " << num_two << std::endl;
    }
    else {
        std::cout << num_two << " > " << num_one << std::endl;
    }
    return 0;
}
