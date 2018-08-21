#include "student.h"
#include <iostream>
#include <vector>

using std::istream;
using std::vector;

istream& read_hw(istream& in, vector<double>& hw){
    if (in){
        hw.clear();

        double x;
        while (in >> x){
            hw.push_back(x);
        }

        in.clear();
    }
    return in;
}

istream& Student_info::read(istream& in){
    in >> n >> midterm >> final;
    read_hw(in, homework);
    return in;
}

double grade(double midterm, double final, const vector<double>& hw){
    return 0.2 * midterm + 0.4 * final + 35;
}

double Student_info::grade() const{
    return ::grade(midterm, final, homework);
}

bool compare(const Student_info& x, const Student_info& y){
    return x.name() < y.name();
}

Student_info::Student_info() : midterm(0), final(0) {}

Student_info::Student_info(istream& is) { read(is); }
