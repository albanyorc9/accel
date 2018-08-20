#include "sentgen.h"
#include "split.h"
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <iterator>

using std::vector;          using std::string;
using std::map;             using std::istream;
using std::rand;            using std::domain_error;
using std::logic_error;     using std::ostream_iterator;

typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;

Grammar read_grammar(istream& in){
    Grammar ret;
    string line;

    while(getline(in, line)){
        vector<string> entry = split(line);
        if(!entry.empty()){
            ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
        }
    }
    return ret;
}

bool bracketed(const string& s){
    return s.size() > 1 && s[0] == '<' && s[s.size()-1] == '>';
}

int nrand(int n){
    if(n <= 0 || n > RAND_MAX)
        throw domain_error("Argument to nrand is out of range");

    const int bucket_size = RAND_MAX / n;
    int r;

    do r = rand() / bucket_size;
    while(r >= n);

    return r;
}

void gen_sentence(const Grammar& g, ostream_iterator<string>& out){
    vector<string> stack;
    stack.push_back("<sentence>");

    while(!stack.empty()){
        if(!bracketed(stack.back())){
            *out = stack.back();
            out++;
            stack.pop_back();
        }
        else {
            Grammar::const_iterator it = g.find(stack.back());
            if (it == g.end()){
                throw logic_error("empty rule");
            }
            else {
                const Rule_collection& c = it->second;
                const Rule& r = c[nrand(c.size())];
                stack.pop_back();
                copy(r.rbegin(), r.rend(), back_inserter(stack));
            }
        }
    }
    return;
}
