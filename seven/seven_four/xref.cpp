#include "xref.h"
#include "split.h"
#include <map>
#include <string>
#include <vector>
#include <iostream>

using std::map;         using std::string;
using std::vector;      using std::istream;

map<string, vector<int>> xref(istream& in){
    string line;
    int line_number = 0;
    map<string, vector<int>> ret;

    while(getline(in, line)){
        line_number++;

        vector<string> words = split(line);
        for(vector<string>::const_iterator iter = words.begin(); iter != words.end(); iter++){
            if(ret[*iter].size() == 0){
                ret[*iter].push_back(line_number);
            }
            else{
                if(ret[*iter].back() != line_number){
                    ret[*iter].push_back(line_number);
                }
            }
        }
    }
    return ret;
}
