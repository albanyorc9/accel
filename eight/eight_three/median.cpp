#include <algorithm>

template<class RAI, class X> X median(RAI b, RAI e, const X& t){
    std::sort(b, e);
    X mid = *(b + (e - b)/2);
    return (e - b)%2 == 0 ? (mid + *(b - 1 + (e - b)/2))/2 : mid;
}
