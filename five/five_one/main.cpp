#include <iostream>
#include <string>
#include <vector>
#include "index.h"
#include "split.h"

using std::cin;         using std::string;
using std::cout;        using std::vector;

int main()
{
    vector<string> raw;
    vector<vector<string>> input;
    string line;
    cout << "Enter lines to be indexed.\n";
    while(getline(cin, line)){
        raw.push_back(line);
    }

    for(vector<string>::const_iterator iter = raw.begin(); iter != raw.end(); iter++){
        input.push_back(split(*iter));
    }

    cout << "\n-Permuted Index-\n";
    print_index(input);

    return 0;
}
