#ifndef GUARD_median
#define GUARD_median

#include <algorithm>
#include <cstddef>

template<class RAI, class T> T median(RAI b, RAI e, T t){
    T nums[e-b];
    std::copy(b, e, nums);
    size_t dist = sizeof(nums) / sizeof(*nums);
    std::sort(nums, nums+dist);

    size_t mid = dist/2;

    return dist % 2 == 0 ? (nums[mid-1] + nums[mid])/2 : nums[mid];
}

#endif // GUARD_median
