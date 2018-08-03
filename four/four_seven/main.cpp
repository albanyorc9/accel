#include <iostream>
#include <vector>

using std::vector;  using std::endl;
using std::cin;     using std::cout;

int main()
{
    // read numbers into a vector
    vector<double> num_list;
    double x;
    while (cin >> x){
        num_list.push_back(x);
    }

    // output mean of the numbers
    typedef vector<double>::size_type vec_sz;
    double average = 0;
    for (vec_sz i = 0; i != num_list.size(); i++){
        average += num_list[i];
    }
    average /= num_list.size();

    cout << "The mean of the entered numbers is " << average << "." << endl;

    return 0;
}
