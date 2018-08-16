#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;              using std::endl;
using std::domain_error;
using std::cout;

template<class T> T median(vector<T> v){
    typedef typename vector<T>::size_type vec_sz;

    vec_sz size = v.size();
    if (size == 0)
        throw domain_error("median of an empty vector");

    sort(v.begin(), v.end());

    vec_sz mid = size/2;

    return size % 2 == 0 ? (v[mid] + v[mid-1])/2 : v[mid];
}

int main()
{
    vector<double> vec{1,7,12,54,89,70,3,23.5,45};

    cout << "The median is " << median(vec) << "." << endl;

    return 0;
}
