#include <iostream>
#include <string>
#include <vector>

using std::cin;     using std::cout;
using std::vector;  using std::string;
using std::endl;

int main()
{
    cout << "Enter the list of words, followed by end-of-file: ";
    vector<string> word_list;
    vector<int> counts;
    string x;
    typedef vector<string>::size_type vec_sz;
    bool found = false;
    while (cin >> x){
        found = false;
        if (word_list.size()==0){
            word_list.push_back(x);
            counts.push_back(1);
        }
        else{
            for (vec_sz i = 0; i < word_list.size(); i++){
                if (word_list[i] == x){
                    counts[i]++;
                    found = true;
                }
            }
            if (!found){
                word_list.push_back(x);
                counts.push_back(1);
            }
        }
    }

    for (vec_sz i = 0; i < word_list.size(); i++){
        cout << word_list[i] << " : " << counts[i] << "\n";
    }
    cout << endl;
    return 0;
}
