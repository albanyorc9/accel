#include "extract_upper.h"
#include <list>
#include <string>
#include <cctype>

using std::list;    using std::isupper;
using std::string;

list<string> extract_upper(list<string>& in){
    list<string> upper;
    list<string>::const_iterator iter = in.begin();

    while (iter!= in.end()){
        if (isupper((*iter)[0])){
            upper.push_back(*iter);
            iter = in.erase(iter);
        }
        else {
            iter++;
        }
    }

    return upper;
}

