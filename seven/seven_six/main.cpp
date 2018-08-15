#include <iostream>
#include <vector>
#include <string>

#include "sentgen.h"

using std::vector;          using std::string;
using std::cin;             using std::cout;
using std::endl;

int main()
{
    vector<string> sentence = gen_sentence(read_grammar(cin));

    vector<string>::const_iterator it = sentence.begin();
    if(!sentence.empty()){
        cout << *it;
        it++;
    }
    while (it != sentence.end()){
        cout << " " << *it;
        it++;
    }
    cout << endl;
    return 0;
}
