#ifndef GUARD_pic_functions
#define GUARD_pic_functions

#include <string>
#include "vec.h"

std::string::size_type width(const Vec<std::string>&);
Vec<std::string> frame(const Vec<std::string>&);
Vec<std::string> vcat(const Vec<std::string>&, const Vec<std::string>&);
Vec<std::string> hcat(const Vec<std::string>&, const Vec<std::string>&);

#endif // GUARD_pic_functions
