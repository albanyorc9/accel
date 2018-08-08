#include <string>
#include <vector>
#include <iostream>
#include "pic_functions.h"

using std::cin;     using std::string;
using std::vector;  using std::cout;
using std::endl;

int main()
{
    string s;
    vector<string> pic_a;
    vector<string> pic_b;
    vector<string> combo;

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
    for(vector<string>::const_iterator iter = combo.begin(); iter != combo.end(); iter++){
        cout << *iter << "\n";
    }
    combo = hcat(pic_a, pic_b);
    cout << "\nHorizontal Concatenation \n\n";
    for(vector<string>::const_iterator iter = combo.begin(); iter != combo.end(); iter++){
        cout << *iter << "\n";
    }
    cout << endl;

    return 0;
}
