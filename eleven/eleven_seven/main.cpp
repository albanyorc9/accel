#include <string>
#include "vec.h"
#include <iostream>
#include "pic_functions.h"

using std::cin;     using std::string;
using std::cout;
using std::endl;

int main()
{
    string s;
    Vec<string> pic_a;
    Vec<string> pic_b;
    Vec<string> combo;

    cout << "Enter first picture: " << endl;
    while(getline(cin, s)){
        pic_a.push_back(s);
    }
    cin.clear();

    cout << "Enter second picture: " << endl;
    while(getline(cin, s)){
        pic_b.push_back(s);
    }

    pic_a = frame(pic_a);
    pic_b = frame(pic_b);

    combo = vcat(pic_a, pic_b);
    cout << "Vertical Concatenation \n\n";
    for(Vec<string>::const_iterator iter = combo.begin(); iter != combo.end(); iter++){
        cout << *iter << "\n";
    }
    combo = hcat(pic_a, pic_b);
    cout << "\nHorizontal Concatenation \n\n";
    for(Vec<string>::const_iterator iter = combo.begin(); iter != combo.end(); iter++){
        cout << *iter << "\n";
    }
    cout << endl;

    return 0;
}
