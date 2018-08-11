#include "palindrome.h"
#include <string>

using std::string;

bool check_pal(const string& s){
    typedef string::const_iterator string_iter;
    string_iter it = s.begin();
    string_iter rt = s.end();
    rt--;
    while(it < rt){
        if (*it != *rt){
            return false;
        }
        it++;
        rt--;
    }
    return true;
}
