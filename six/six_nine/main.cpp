#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using std::vector;          using std::cout;
using std::string;          using std::endl;
using std::accumulate;


int main()
{
    string s;
    string out;
    vector<string> in{"hello", "chaps", "how's", "it", "going."};
    out = accumulate(in.begin(), in.end(), out);

    cout << out << endl;

    return 0;
}
