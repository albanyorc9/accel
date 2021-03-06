#include "xref.h"
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using std::cin;         using std::cout;
using std::endl;        using std::map;
using std::vector;      using std::string;

int main()
{
    cout << "Enter lines to be indexed.\n";
    map<string, vector<int>> index = xref(cin);

    int out_count = 0;

    for(map<string, vector<int>>::const_iterator iter = index.begin(); iter != index.end(); iter++){
        cout << iter->first << "\t";
        for(vector<int>::const_iterator jter = iter->second.begin(); jter != iter->second.end(); jter++){
            cout << *jter << ' ';
            out_count++;
            if(out_count == 10){
                cout << "\n\t";
                out_count = 0;
            }
        }
        cout << '\n';
        out_count = 0;
    }
    cout << endl;

    return 0;
}
