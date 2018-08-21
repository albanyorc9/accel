#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "student.h"

using std::cin;             using std::endl;
using std::cout;            using std::vector;
using std::string;          using std::max;

int main()
{
    vector<Student_PF> records;
    Student_PF record;
    string::size_type maxlen = 0;

    cout << "Enter each student's name followed by midterm then exam. End with eof.\n";
    while(record.read(cin)){
        records.push_back(record);
        maxlen = max(maxlen, record.name().size());
    }

    sort(records.begin(), records.end(), compare_two); // 9-5 vs 9-6 change compare type

    for(vector<Student_PF>::const_iterator iter = records.begin(); iter != records.end(); iter++){
        cout << iter->name() << string(maxlen + 1 - iter->name().size(),' ') << iter->status() << '\n';
    }
    cout << endl;
    return 0;
}
