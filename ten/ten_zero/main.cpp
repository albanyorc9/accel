#include <iostream>
#include <string>
#include <fstream>

using std::cout;            using std::endl;
using std::string;          using std::ifstream;
using std::cerr;

int main(int argc, char **argv)
{
    int fail_count = 0;

    for(int i = 1; i < argc; i++){
        ifstream in(argv[i]);

        if(in){
            string s;
            while(getline(in, s))
                cout << s << '\n';
        }
        else {
            cerr << "cannot open file " << argv[i] << endl;
            fail_count++;
        }
    }
    cout << endl;
    return fail_count;
}
