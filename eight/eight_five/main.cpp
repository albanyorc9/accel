#include <iostream>
#include <vector>
#include <string>
#include <iterator>

#include "sentgen.h"

using std::vector;          using std::string;
using std::cin;             using std::cout;
using std::endl;            using std::ostream_iterator;

int main()
{
    ostream_iterator<string> out (cout, " ");
    gen_sentence(read_grammar(cin), out);

    return 0;
}
