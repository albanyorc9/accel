#include "split.h"
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using std::string;
using std::vector;

bool space(char c){
    return isspace(c);
}

bool not_space(char c){
    return !isspace(c);
}

vector<string> split(const string& str){
    typedef string::const_iterator iter;
    vector<string> ret;

    iter i = str.begin();
    while (i != str.end()){
        i = find_if(i, str.end(), not_space);
        iter j = find_if(i, str.end(), space);
        if (i != str.end())
            ret.push_back(string(i,j));
        i = j;
    }
    return ret;
}
