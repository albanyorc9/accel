#include <iostream>
#include <string>

using std::cin;     using std::cout;
using std::endl;    using std::string;

int main()
{
    cout << "Enter your first name: ";
    string name;
    cin >> name;

    const string greeting = "Hello, " + name + "!";

    int pad_hor;
    int pad_ver;
    cout << "Enter amount of horizontal padding: ";
    cin >> pad_hor;
    cout << "Enter amount of vertical padding: ";
    cin >> pad_ver;

    const int rows = pad_ver * 2 + 3;
    const string::size_type cols = greeting.size() + pad_hor * 2 + 2;
    cout << "\n";

    for (int r = 0; r!= rows; r++){
        if(r == 0 || r == rows - 1){
            cout << string(cols,'*');
        }
        else{
            if(r == pad_ver + 1){
                cout << "*" + string(pad_hor, ' ') + greeting + string(pad_hor, ' ') + "*";
            }
            else{
                cout << "*" + string(cols - 2, ' ') + "*";
            }
        }
        cout << "\n";
    }

    cout << endl;

    return 0;
}
