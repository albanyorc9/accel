#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using std::vector;          using std::cout;
using std::copy;            using std::endl;
using std::back_inserter;

void print_vec(const vector<int>& in){
    for (vector<int>::const_iterator iter = in.begin(); iter!= in.end(); iter++){
        cout << *iter << ' ';
    }
    cout << '\n';
    return;
}

int main()
{
    vector<int> u(10,100);
    vector<int> v(u);
    vector<int> w;
    copy(u.begin(), u.end(), back_inserter(w));

    print_vec(u);
    print_vec(v);
    print_vec(w);
    cout << endl;
    return 0;
}
