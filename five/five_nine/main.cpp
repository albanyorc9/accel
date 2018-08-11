#include <iostream>
#include <list>
#include <string>
#include "extract_upper.h"

using std::cin;     using std::cout;
using std::list;    using std::endl;
using std::string;

int main()
{
    string s;
    list<string> input;
    cout << "Enter words to seperate.\n";
    while (cin >> s){
        input.push_back(s);
    }

    list<string> upper = extract_upper(input);
    cout << "Lowercase words\n";
    for (list<string>::const_iterator iter = input.begin(); iter!= input.end(); iter++){
        cout << *iter << " ";
    }
    cout << "\n\nUppercase words\n";
    for (list<string>::const_iterator iter = upper.begin(); iter!= upper.end(); iter++){
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}
