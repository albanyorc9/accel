#include "grade.h"
#include <iostream>

using std::cout;        using std::endl;

int main()
{
    double n = 95;

    cout << "The letter grade of " << n << " is " << grade(n) << "." << endl;

    return 0;
}
