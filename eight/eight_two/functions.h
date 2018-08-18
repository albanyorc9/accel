#ifndef GUARD_functions
#define GUARD_functions

template<class In> bool equal(In, In, In);
template<class In, class X> In find(In, In, const X&);
template<class In, class Out> Out cop(In, In, Out);
template<class In, class Out, class Pred> Out rmv_copy_if(In, In, Out, Pred);
template<class In, class Out, class Func> Out tf(In, In, Out, Func);
template<class In, class Res> Res accum(In, In, Res);
template<class In, class Pred> In fif(In, In, Pred);
template<class In, class Out, class X> Out rmv_copy(In, In, Out, const X&);
template<class In> In srch(In, In, In, In);
template<class For, class X> For rem(For, For, const X&);
template<class Bi, class Pred> Bi prt(Bi, Bi, Pred);

#include "functions.cpp" // Template definitions found here

#endif // GUARD_functions
