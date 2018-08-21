#include "student.h"
#include <iostream>

using std::istream;

Student_PF::Student_PF(): midterm(0), fin_exam(0) {}

istream& Student_PF::read(istream& in){
    in >> n >> midterm >> fin_exam;
    return in;
}

bool compare_one(const Student_PF& x, const Student_PF& y){
    return x.name() < y.name();
}

bool compare_two(const Student_PF& x, const Student_PF& y){
    if(x.status() == y.status()){
        return x.name() < y.name();
    }
    else {
        return x.status() > y.status(); // P > F but we want P first
    }
}
