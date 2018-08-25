#ifndef GUARD_vec
#define GUARD_vec

#include <cstddef>
#include <memory>

template<class T> class Vec{
public:
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef T value_type;

    Vec() { create(); }
    explicit Vec(size_type n, const T& t = T()) { create(n, t); }

    Vec(const Vec& v) { create(v.begin(), v.end()); }
    Vec& operator=(const Vec&);
    ~Vec() { uncreate(); }

    T& operator[](size_type i){ return data[i]; }
    const T& operator[](size_type i) const { return data[i]; }

    void push_back(const T& t){
        if(avail == limit)
            grow();
        unchecked_append(t);
    }

    size_type size() const { return avail - data; }

    void clear() { uncreate(); }
    iterator erase(iterator position){
        iterator current = position;
        while(current != avail - 1){
            *current = *(current + 1);
            current++;
        }
        alloc.destroy(current);
        avail--;
        return position;
    }

    iterator begin() { return data; }
    const_iterator begin() const { return data; }

    iterator end() { return avail; }
    const_iterator end() const {return avail; }

private:
    iterator data;
    iterator avail;
    iterator limit;

    std::allocator<T> alloc;

    void create();
    void create(size_type, const T&);
    void create(const_iterator, const_iterator);

    void uncreate();

    void grow();
    void unchecked_append(const T&);
};

template <class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs){
    if(&rhs != this){
        uncreate();
        create(rhs.begin(), rhs.end());
    }
    return *this;
}

template <class T> void Vec<T>::create(){
    data = avail = limit = 0;
}

template <class T> void Vec<T>::create(size_type n, const T& val){
    data = alloc.allocate(n);
    limit = avail = data + n;
    uninitialized_fill(data, limit, val);
}

template <class T> void Vec<T>::create(const_iterator i, const_iterator j){
    data = alloc.allocate(j - i);
    limit = avail = uninitialized_copy(i, j, data);
}

template <class T> void Vec<T>::uncreate(){
    if(data){
        iterator it = avail;
        while(it != data)
            alloc.destroy(--it);
        alloc.deallocate(data, limit-data);
    }
    data = limit = avail = 0;
}

template <class T> void Vec<T>::grow(){
    size_type new_size = std::max(2 * (limit - data), ptrdiff_t(1));

    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = std::uninitialized_copy(data, avail, new_data);

    uncreate();

    data = new_data;
    avail = new_avail;
    limit = data + new_size;
}

template <class T> void Vec<T>::unchecked_append(const T& val){
    alloc.construct(avail++, val);
}

#endif // GUARD_vec
