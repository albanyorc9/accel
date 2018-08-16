#include "functions.h"
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>

using std::vector;          using std::map;
using std::max;

double median(vector<double> in){
    vector<double>::size_type mid = in.size()/2;

    sort(in.begin(), in.end());
    return in.size() % 2 == 0 ? (in[mid] + in[mid-1])/2 : in[mid];
}

double mean(vector<double> in){
    double sum = 0;
    sum = accumulate(in.begin(), in.end(), 0.0);
    return sum / in.size();
}
double mode(vector<double> in){
    map<double, int> tracker;
    int most = 0;
    typedef vector<double>::const_iterator it;
    typedef map<double, int>::const_iterator jt;

    for(it iter = in.begin(); iter != in.end(); iter++){
        tracker[*iter]++;
        most = max(most, tracker[*iter]);
    }
    for (jt iter = tracker.begin(); iter != tracker.end(); iter++){
        if (iter->second == most){
            return iter->first;
        }
    }

}

