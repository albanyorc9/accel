#include <cstddef>
#include <string>

template<class A> std::string grade(A n){
    static const char* const letters[] = {
        "A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"
    };

    static const A numbers[] = {
        97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0
    };

    static const std::size_t ngrades = sizeof(numbers)/sizeof(*numbers);

    for(std::size_t i = 0; i < ngrades; i++){
        if(n >= numbers[i])
            return letters[i];
    }
    return "?\?\?";

}
