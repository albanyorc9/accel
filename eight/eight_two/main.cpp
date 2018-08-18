#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <iterator>

#include "functions.h"

using std::cout;            using std::endl;
using std::string;          using std::boolalpha;
using std::list;            using std::vector;

double mult(double x){
    return 2 * x;
}

bool pred(double x){
    return x < 5;
}

int main()
{
    // Set cout to print bool as string instead of int
    cout << boolalpha;

    { // Tests for the equal function
        vector<string> test_1a = {"Hello", "Mark", "How", "It", "Be"};
        vector<string> test_1b = {"Hello", "Mark", "How", "It", "Be"};
        list<int> test_2a = {6,8,0,5,3,6,1};
        list<int> test_2b = {6,8,0,5,3,6,1};
        vector<double> test_3a = {3.5, 6.8, 9.3, 5.5, 1.2};
        vector<double> test_3b = {3.5, 6.8, 9.3, 4.0, 1.2};

        cout << "equal\n";
        cout << "Req\tActual\n";
        cout << true << '\t' << equal(test_1a.begin(), test_1a.end(), test_1b.begin()) << '\n';
        cout << true << '\t' << equal(test_2a.begin(), test_2a.end(), test_2b.begin()) << '\n';
        cout << false << '\t' << equal(test_3a.begin(), test_3a.end(), test_3b.begin()) << '\n';

    }
    cout << '\n';

    { // Tests for the find function
        vector<string> test_1a = {"Greg", "Joseph", "Emily"};
        string test_1b = "Joseph";
        list<int> test_2a = {6,4,3,7,5,3,4};
        int test_2b = 5;
        vector<int> test_3a = {1,2,3,4,5,6,7,8,9,10};
        int test_3b = 11;

        cout << "find\n";
        cout << "Req\tActual\n";
        cout << true << '\t' << (test_1a.end() != find(test_1a.begin(), test_1a.end(), test_1b)) << '\n';
        cout << true << '\t' << (test_2a.end() != find(test_2a.begin(), test_2a.end(), test_2b)) << '\n';
        cout << false << '\t' << (test_3a.end() != find(test_3a.begin(), test_3a.end(), test_3b)) << '\n';
    }
    cout << '\n';

    { // Tests for the copy function. Named cop because of name conflict.
        vector<int> test_1a = {1,2,3,4,5};
        vector<int> test_1b = {6,7,8,9,0};
        vector<int> test_2a = {1,2,3,4,5};
        vector<int> test_2b = {6,7,8,9,0};
        vector<int> test_2c = {1,2,3,4,5,6,7,8,9,0};

        cop(test_1b.begin(),test_1b.end(),test_1a.begin());
        cop(test_2b.begin(), test_2b.end(), back_inserter(test_2a));

        cout << "copy\n";
        cout << "Req\tActual\n";
        cout << true << '\t' << (test_1a == test_1b) << '\n';
        cout << true << '\t' << (test_2a == test_2c) << '\n';
    }
    cout << '\n';

    { // Tests for remove_copy_if.
        vector<double> test_1a = {3,4,5,6,7};
        vector<double> test_1b = {3,4,5,6,7};
        vector<double> test_1c = {3,4,5,6,7,5,6,7};
        vector<double> test_2a = {7,7,7};
        vector<double> test_2b = {2,2,2};

        rmv_copy_if(test_1a.begin(), test_1a.end(), back_inserter(test_1b), pred);
        rmv_copy_if(test_2a.begin(), test_2a.end(), test_2b.begin(), pred);
        cout << "remove_copy_if\n";
        cout << "Req\tActual\n";
        cout << true << '\t' << (test_1b == test_1c) << '\n';
        cout << true << '\t' << (test_2b == test_2a) << '\n';
    }
    cout << '\n';

    { // Tests for transform.
        vector<double> test_1a = {2,4,6,8};
        vector<double> test_1b;
        vector<double> test_1c = {4,8,12,16};
        vector<double> test_2a = {3.5,6.5,80};
        vector<double> test_2b = {7,13,160};

        tf(test_1a.begin(), test_1a.end(), back_inserter(test_1b), mult);
        tf(test_2a.begin(), test_2a.end(), test_2a.begin(), mult);

        cout << "transform\n";
        cout << "Req\tActual\n";
        cout << true << '\t' << (test_1b == test_1c) << '\n';
        cout << true << '\t' << (test_2b == test_2a) << '\n';

    }
    cout << '\n';

    { // Tests for accumulate.
        vector<int> test_1a = {5,6,9};
        vector<string> test_2a = {"he","ll","o"};
        string s;

        cout << "accumulate\n";
        cout << "Req\tActual\n";
        cout << true << '\t' << (20 == accum(test_1a.begin(), test_1a.end(), 0)) << '\n';
        cout << true << '\t' << ("hello" == accum(test_2a.begin(), test_2a.end(), s)) << '\n';

    }
    cout << '\n';

    { // Tests for find_if.
        vector<double> test_1a = {7,9,10,12};
        vector<double> test_2a = {7,9,2,12};

        cout << "find_if\n";
        cout << "Req\tActual\n";
        cout << true << '\t' << (test_1a.end() == fif(test_1a.begin(), test_1a.end(), pred)) << '\n';
        cout << false << '\t' << (test_2a.end() == fif(test_2a.begin(), test_2a.end(), pred)) << '\n';

    }
    cout << '\n';

    { // Tests for remove_copy.
        vector<double> test_1a = {3,4,5,6,7};
        vector<double> test_1b = {4,8,4,9,4};
        vector<double> test_1c = {3,4,5,6,7,8,9};
        vector<double> test_2a = {7,7,7};
        vector<double> test_2b = {2,2,2};

        rmv_copy(test_1b.begin(), test_1b.end(), back_inserter(test_1a), 4);
        rmv_copy(test_2a.begin(), test_2a.end(), test_2b.begin(), 4);

        cout << "remove_copy\n";
        cout << "Req\tActual\n";
        cout << true << '\t' << (test_1c == test_1a) << '\n';
        cout << true << '\t' << (test_2a == test_2b) << '\n';

    }
    cout << '\n';

    { // tests for search.
        string test_1a = "bebebo";
        string test_1b = "bebo";
        vector<int> test_2a = {6,7,8,4,3,78,5,6};
        vector<int> test_2b = {4,3,78};
        string test_3a = "racecar";
        string test_3b = "nox";

        cout << "search\n";
        cout << "Req\tActual\n";
        cout << true << '\t' << (test_1a.end() != srch(test_1a.begin(), test_1a.end(), test_1b.begin(), test_1b.end())) << '\n';
        cout << true << '\t' << (test_2a.end() != srch(test_2a.begin(), test_2a.end(), test_2b.begin(), test_2b.end())) << '\n';
        cout << true << '\t' << (test_3a.end() == srch(test_3a.begin(), test_3a.end(), test_3b.begin(), test_3b.end())) << '\n';
    }
    cout << '\n';

    { // Tests remove function.
        string test_1a = "mekeke";
        string test_1b = "mkk";
        vector<int> test_2a = {4,5,4,6,7,4,5,3,5,4};
        vector<int> test_2b = {5,6,7,5,3,5};

        cout << "remove\n";
        cout << "Req\tActual\n";
        cout << true << '\t' << equal(test_1a.begin(), rem(test_1a.begin(), test_1a.end(), 'e'), test_1b.begin()) << '\n';
        cout << true << '\t' << equal(test_2a.begin(), rem(test_2a.begin(), test_2a.end(), 4), test_2b.begin()) << '\n';
    }
    cout << '\n';

    { // Testing partition.
        vector<double> test_1a = {4,5,5,4,5,4};
        vector<double> test_1b = {4,4,4,5,5,5};
        vector<double> test_2a = {5,5,5,5,5,4,5};
        vector<double> test_2b = {4,5,5,5,5,5,5};

        prt(test_1a.begin(), test_1a.end(), pred);
        prt(test_2a.begin(), test_2a.end(), pred);

        cout << "partition\n";
        cout << true << '\t' << (test_1a == test_1b) << '\n';
        cout << true << '\t' << (test_2a == test_2b) << '\n';

    }
    cout << '\n';
    cout << endl;
    return 0;
}
