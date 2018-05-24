#include <iostream>
#include <algorithm>

using std::cin;     using std::cout;
using std::endl;    using std::string;
using std::min;     using std::max;

int main()
{
    cout << "Enter list of words, followed by end-of-file: ";
    typedef string::size_type str_sz;
    str_sz shortest;
    str_sz longest;
    bool init = false;
    string x;
    while (cin >> x){
        if (!init){
            shortest = x.size();
            longest = x.size();
            init = true;
        }
        else{
            shortest = min(shortest, x.size());
            longest = max(longest, x.size());
        }
    }

    cout << "Longest word had length " << longest << ".\n";
    cout << "Shortest word had length " << shortest << "." << endl;

    return 0;
}
