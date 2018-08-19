#include <iostream>
#include <vector>
#include "median.h"

using std::vector;
using std::cout;
using std::endl;

int main()
{
    vector<double> vec = {6,7,4,5,8};

    cout << median(vec.begin(), vec.end(), 0.0) << endl;

    return 0;
}
