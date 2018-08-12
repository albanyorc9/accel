#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::copy;

int main()
{
    vector<int> u(10,100);
    vector<int> v;

    // This program returns an exception!
    copy(u.begin(),u.end(),v.begin());
    return 0;
}
