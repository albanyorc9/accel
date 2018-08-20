#ifndef GUARD_sentgen
#define GUARD_sentgen

#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <iterator>

std::map<std::string, std::vector<std::vector<std::string>>> read_grammar(std::istream&);
void gen_sentence(const std::map<std::string, std::vector<std::vector<std::string>>>&, std::ostream_iterator<std::string>&);

#endif // GUARD_sentgen
