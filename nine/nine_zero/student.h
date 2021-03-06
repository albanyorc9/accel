#ifndef GUARD_student
#define GUARD_student

#include <string>
#include <vector>
#include <iostream>

class Student_info{
public:
    std::string name() const {return n;}
    bool valid() const {return !homework.empty();}
    Student_info();
    Student_info(std::istream&);

    std::istream& read(std::istream&);

    double grade() const;
private:
    std::string n;
    double midterm, final;
    std::vector<double> homework;
};
bool compare(const Student_info&, const Student_info&);

#endif // GUARD_student
