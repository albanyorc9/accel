// Only template definitions should be in this file.
#include <utility>

template<class In> bool equal(In b, In e, In d){
    while(b != e){
        if(*b != *d)
            return false;
        b++;
        d++;
    }
    return true;
}

template<class In, class X> In find(In b, In e, const X& t){
    while(b != e && *b != t){
        b++;
    }
    return b;
}

template<class In, class Out> Out cop(In b, In e, Out d){
    while(b != e){
        *d = *b;
        b++;
        d++;
    }
    return d;
}

template<class In, class Out, class Pred> Out rmv_copy_if(In b, In e, Out d, Pred p){
    while(b != e){
        if(!p(*b)){
            *d = *b;
            d++;
        }
        b++;
    }
    return d;
}

template<class In, class Out, class Func> Out tf(In b, In e, Out d, Func f){
    while(b != e){
        *d = f(*b);
        b++;
        d++;
    }
    return d;
}

template<class In, class Res> Res accum(In b, In e, Res t){
    Res ret = t;
    while(b != e){
        ret += *b;
        b++;
    }
    return ret;
}

template<class In, class Pred> In fif(In b, In e, Pred p){
    while(b != e && !p(*b))
        b++;
    return b;
}

template<class In, class Out, class X> Out rmv_copy(In b, In e, Out d, const X& t){
    while(b != e){
        if(!(*b == t)){
            *d = *b;
            d++;
        }
        b++;
    }
    return d;
}

template<class In> In srch(In b, In e, In b2, In e2){
    while(b != e){
        if(*b == *b2){
            if (equal(b2, e2, b))
                return b;
        }
        b++;
    }
    return b;
}

template<class For, class X> For rem(For b, For e, const X& t){
    For l(b);
    while(b != e){
        if(*b != t){
            *l = *b;
            l++;
        }
        b++;
    }
    return l;
}

template<class Bi, class Pred> Bi prt(Bi b, Bi e, Pred p){
    while(b != e){
        while(p(*b)){
            b++;
            if(b == e) return b;
        }
        do{
            e--;
            if(b == e)return b;
        } while(!p(*e));
        std::swap(*b, *e);
        b++;
    }
    return b;
}


