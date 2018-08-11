#include <iostream>
#include <fstream>
#include <string>
#include "palindrome.h"

using std::cout;        using std::endl;
using std::string;      using std::ifstream;

int main()
{
    string line;
    string longest = "";

    ifstream dict ("words_alpha.txt");
    if (dict.is_open()){
        cout << "- List of Palindromes -\n\n";
        while(getline(dict, line)){
            if(check_pal(line)){
                if(line.size() > longest.size()){
                    longest = line;
                }
                cout << line << '\n';
            }
        }
        dict.close();
        cout << "The longest palindrome is: " << longest;
    }
    else{
        cout << "Unable to open dictionary file.";
    }

    cout << endl;

    return 0;
}
