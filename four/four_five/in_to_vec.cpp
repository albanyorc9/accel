#include "in_to_vec.h"


using std::istream;     using std::vector;
using std::string;

istream& read(istream& in, vector<string>& words){
    if (in){
        words.clear();

        string x;
        while (in >> x){
            words.push_back(x);
        }

        in.clear();
    }
    return in;
}
