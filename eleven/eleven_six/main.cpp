#include "vec.h"
#include <iostream>

using std::cout;        using std::endl;

int main()
{
    Vec<int> test;

    for(int i = 0; i != 10; i++){
        test.push_back(i);
    }

    test.erase(test.begin()+3);

    for(Vec<int>::const_iterator iter = test.begin(); iter != test.end(); iter++){
        cout << *iter << '\n';
    }
    cout << endl;
    return 0;
}
