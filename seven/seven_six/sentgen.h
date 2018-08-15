#ifndef GUARD_sentgen
#define GUARD_sentgen

#include <map>
#include <string>
#include <vector>
#include <iostream>

std::map<std::string, std::vector<std::vector<std::string>>> read_grammar(std::istream&);
std::vector<std::string> gen_sentence(const std::map<std::string, std::vector<std::vector<std::string>>>&);

#endif // GUARD_sentgen
