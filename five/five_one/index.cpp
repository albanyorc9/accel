#include "index.h"
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <cctype>

using std::string;      using std::max;
using std::vector;      using std::cout;
using std::endl;

typedef vector<string> Line;

struct Rotation{
    Line source;
    Line::size_type seperator;
};

typedef vector<Rotation> Index;

void generate_rotations(Index& index, const vector<Line>& input){
    for(vector<Line>::size_type i = 0; i != input.size(); i++){
        for(Line::size_type j = 0; j != input[i].size(); j++){
            Rotation rot;
            rot.source = input[i];
            rot.seperator = j;
            index.push_back(rot);
        }
    }
}

string to_lower_case(const string& s){
    string ret;
    for (string::const_iterator iter = s.begin(); iter != s.end(); iter++){
        ret += tolower(*iter);
    }
    return ret;
}

string rot_to_string(const Rotation& rot){
    string ret;
    for(Line::size_type i = rot.seperator; i != rot.source.size(); i++){
        ret += rot.source[i];
    }
    ret = to_lower_case(ret);
    return ret;
}

bool compare(const Rotation& rot_a, const Rotation& rot_b){
    string a = rot_to_string(rot_a);
    string b = rot_to_string(rot_b);

    return a < b;
}

void sort_rotations(Index& index){
    sort(index.begin(), index.end(), compare);
}

string::size_type get_spacing(const vector<Line>& input){
    string::size_type maxlen = 0;
    string s;
    for (vector<Line>::const_iterator iter = input.begin(); iter != input.end(); iter++){
        if(iter->size() < 2){
            s = "";
        }
        else{
            s = accumulate(iter->begin(), iter->end() - 2, s);
        }

        maxlen = max(maxlen, s.size());
    }
    return maxlen;
}

void print_rotation(const Rotation& rot, const string::size_type& spacing){
    string a;
    string b;
    for (Line::size_type i = 0; i < rot.seperator; i++){
        a += rot.source[i];
        if(i != rot.seperator - 1){
            a += " ";
        }
    }
    for (Line::size_type i = rot.seperator; i < rot.source.size(); i++){
        b += rot.source[i] + " ";
    }
    cout << string(spacing - a.size(), ' ') << a << string(10, ' ') << b << '\n';

}

void print_index(const vector<Line>& input){
    Index index;
    string::size_type spacing;

    generate_rotations(index, input);
    sort_rotations(index);
    spacing = get_spacing(input);

    for(Index::const_iterator iter = index.begin(); iter != index.end(); iter++){
        print_rotation(*iter, spacing);
    }
    cout << endl;
}
