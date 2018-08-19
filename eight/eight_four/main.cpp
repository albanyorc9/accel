#include <iostream>
#include "swap.h"

using std::cout;        using std::endl;

int main()
{
    int a = 5;
    int b = 7;

    swap(a, b);

    cout << "A: " << a << "\tB: " << b << endl;

    return 0;
}
