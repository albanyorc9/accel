#include "median.h"
#include <iostream>
#include <vector>

using std::vector;      using std::endl;
using std::cout;

int main()
{
    vector<double> test1 = {4.6, 8.7, 3.0, 7.9, 8.8};
    int test2[] = {2, 6, 4, 9};

    cout << "Median of test1: " << median(test1.begin(), test1.end(), 0.0) << "\n";
    cout << "Median of test2: " << median(test2, test2 + 4, 0) << endl;

    cout << "This is a filler string.";

    return 0;
}
