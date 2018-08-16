#include "functions.h"
#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

template<class T, class num> num eval(T func, vector<num> in){
    return func(in);
}

int main()
{
    typedef double num_type;

    num_type x;
    vector<num_type> entries;

    while(cin >> x){
        entries.push_back(x);
    }

    cout << "\nThe median of the entered values is " << eval(median, entries);
    cout << ".\nThe mean of the entered values is " << eval(mean, entries);
    cout << ".\nThe mode of the entered values is " << eval(mode, entries);
    cout << '.' << endl;
    return 0;
}
