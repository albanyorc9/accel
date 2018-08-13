#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using std::string;      using std::cin;
using std::map;         using std::cout;
using std::endl;        using std::pair;
using std::vector;

bool compare(const pair<string, int>& pair_a, const pair<string, int>& pair_b){
    return pair_a.second < pair_b.second;
}

int main()
{
    string s;
    map<string, int> counters;
    vector<pair<string, int>> output;

    while (cin >> s){
        counters[s]++;
    }

    for(map<string, int>::const_iterator iter = counters.begin(); iter != counters.end(); iter++){
        pair<string, int> p;
        p.first = iter->first;
        p.second = iter->second;
        output.push_back(p);
    }

    sort(output.begin(), output.end(), compare);

    for(vector<pair<string, int>>::const_iterator iter = output.begin(); iter != output.end(); iter++){
        cout << iter->first << '\t' << iter ->second << '\n';
    }
    cout << endl;
    return 0;
}
