#include <iostream>
#include <vector>
#include <string>
#include "in_to_vec.h"

using std::cin;     using std::vector;
using std::string;  using std::cout;
using std::endl;

int main()
{
    typedef vector<string>::size_type vec_sz;
    // read words into a vector
    vector<string> words;
    read(cin, words);

    // count total words and display
    vec_sz total = words.size();
    cout << "There were " << total << " words entered." << endl;

    // count occurences of each word and display
    while (words.size()!= 0){
        string current = words[0];
        int count = 0;
        vector<string> temp;

        for (vec_sz i = 0; i != words.size(); i++){
            if (words[i] == current){
                count++;
            }
            else{
                temp.push_back(words[i]);
            }
        }

        cout << "The word \'" << current << "\' appeared " << count << " time(s)." << endl;
        words = temp;
    }
    return 0;
}
