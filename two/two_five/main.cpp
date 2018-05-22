#include <iostream>
#include <string>
int main()
{
    // shape parameters
    const int square_side = 4;
    const int rec_x = 5;
    const int rec_y = 3;
    const int triangle_side = 4;

    // output square
    for(int i = 0; i < square_side; i++){
        std::cout << std::string(square_side, '*') + "\n";
    }
    std::cout << "\n";

    // output rectangle
    for(int i = 0; i < rec_y; i++){
        std::cout << std::string(rec_x, '*') + "\n";
    }
    std::cout << "\n";

    // output triangle
    for (int i = 0; i < triangle_side; i++){
        std::cout << std::string(i + 1, '*') + "\n";
    }

    // flush buffer
    std::cout << std::endl;
    return 0;
}
