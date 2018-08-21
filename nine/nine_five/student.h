#ifndef GUARD_student
#define GUARD_student

#include <iostream>
#include <string>

class Student_PF{
private:
    std::string n; // name
    double midterm;
    double fin_exam;
    static constexpr double pass = 60;
    double average() const {return (midterm + fin_exam) / 2;}

public:
    Student_PF();
    std::istream& read(std::istream&);
    char status() const { return average() > pass ? 'P':'F'; }
    std::string name() const { return n; }
};

bool compare_one(const Student_PF&, const Student_PF&);
bool compare_two(const Student_PF&, const Student_PF&);

#endif // GUARD_student
