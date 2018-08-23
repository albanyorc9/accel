#include "string_list.h"
#include "split.h"
#include <iostream>

using std::cout;        using std::endl;

int main()
{
    String_list test = split("The mongoose ate many fleas.");

    for(String_list::Iterator iter = test.begin(); !iter.compare(test.end()); iter.increment()){
        cout << iter.dereference() << '\n';
    }
    cout << endl;
    return 0;
}
