#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;     using std::cout;
using std::endl;    using std::vector;
using std::sort;

int main()
{
    cout << "Enter list of integers, followed by end-of-file: ";

    // accept list of integers
    vector<int> int_list;
    int x;
    while(cin >> x){
        int_list.push_back(x);
    }

    // check if at least 4 ints entered
    typedef vector<int>::size_type vec_sz;
    vec_sz size = int_list.size();

    if(size < 4){
        cout << "\nYou must enter at least 4 integers. Please try again." << endl;
        return 1;
    }
    // sort list
    sort(int_list.begin(), int_list.end());

    // print each quartile

    for (vec_sz i = 0; i < size; i++){
        if (i == 0){
            cout << "Q1: ";
        }
        if (i == size / 4){
            cout << "\nQ2: ";
        }
        if (i == size / 2){
            cout << "\nQ3: ";
        }
        if (i == 3 * size / 4){
            cout << "\nQ4: ";
        }
        cout << int_list[i] << " ";
    }
    cout << endl;
    return 0;
}
