#include "pic_functions.h"
#include <string>
#include "vec.h"

using std::string;      using std::max;

string::size_type width(const Vec<string>& v){
    string::size_type maxlen = 0;
    for(Vec<string>::const_iterator iter = v.begin();
    iter != v.end(); iter++){
        maxlen = max(maxlen, iter->size());
    }
    return maxlen;
}

Vec<string> frame(const Vec<string>& v){
    Vec<string> ret;
    string::size_type maxlen = width(v);
    string border(maxlen + 4, '*');

    ret.push_back(border);

    for(Vec<string>::const_iterator iter = v.begin();
    iter != v.end(); iter++){
        ret.push_back("* " + *iter + string(maxlen - iter->size(), ' ') + " *");
    }

    ret.push_back(border);
    return ret;
}

Vec<string> vcat(const Vec<string>& top, const Vec<string>& bottom){
    Vec<string> ret = top;
    for(Vec<string>::const_iterator iter = bottom.begin(); iter != bottom.end(); iter++){
        ret.push_back(*iter);
    }
    return ret;
}

Vec<string> hcat(const Vec<string>& left, const Vec<string>& right){
    Vec<string> ret;
    string::size_type width1 = width(left) + 1;

    Vec<string>::size_type i = 0, j = 0;

    while (i != left.size() || j != right.size()){
        string s;
        if (i != left.size())
            s = left[i++];
        s += string(width1 - s.size(), ' ');
        if (j != right.size())
            s += right[j++];
        ret.push_back(s);
    }
    return ret;
}
