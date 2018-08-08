#include "pic_functions.h"
#include <string>
#include <vector>

using std::string;      using std::max;
using std::vector;

string::size_type width(const vector<string>& v){
    string::size_type maxlen = 0;
    for(vector<string>::const_iterator iter = v.begin();
    iter != v.end(); iter++){
        maxlen = max(maxlen, iter->size());
    }
    return maxlen;
}

vector<string> frame(const vector<string>& v){
    vector<string> ret;
    string::size_type maxlen = width(v);
    string border(maxlen + 4, '*');

    ret.push_back(border);

    for(vector<string>::const_iterator iter = v.begin();
    iter != v.end(); iter++){
        ret.push_back("* " + *iter + string(maxlen - iter->size(), ' ') + " *");
    }

    ret.push_back(border);
    return ret;
}

vector<string> vcat(const vector<string>& top, const vector<string>& bottom){
    vector<string> ret = top;
    ret.insert(ret.end(), bottom.begin(), bottom.end());
    return ret;
}

vector<string> hcat(const vector<string>& left, const vector<string>& right){
    vector<string> ret;
    string::size_type width1 = width(left) + 1;

    vector<string>::size_type i = 0, j = 0;

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
