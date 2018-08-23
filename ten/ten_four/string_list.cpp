#include "string_list.h"
#include <string>

// String_List functions
String_list::String_list(){
    head = new Node();
    tail = head;
    head->prev = 0;
}

String_list::Iterator String_list::begin() const{
    return Iterator(head);
}

String_list::Iterator String_list::end() const{
    return Iterator(tail);
}

bool String_list::empty() const{
    return head == tail;
}

String_list::size_type String_list::size() const{
    size_type ret = 0;
    Iterator iter = begin();
    while(!iter.compare(end())){
        ret++;
        iter.increment();
    }
    return ret;
}

void String_list::push_back(const std::string& s){
    Node* curr = tail;
    tail = new Node();
    curr->next = tail;
    tail->prev = curr;
    curr->value = s;
}

String_list::Iterator String_list::erase(String_list::Iterator it){
    Iterator ret = Iterator(it.point->next);
    it.point->prev->next = it.point->next;
    it.point->next->prev = it.point->prev;
    delete it.point;
    return ret;

}


// Iterator functions
String_list::Iterator::Iterator(Node* n){
    point = n;
}

String_list::Iterator::Iterator(const String_list::Iterator& it){
    point = it.point;
}

bool String_list::Iterator::compare(const String_list::Iterator& it) const{
    return point == it.point;
}

void String_list::Iterator::increment(){
    point = point->next;
}

void String_list::Iterator::decrement(){
    point = point->prev;
}

std::string String_list::Iterator::dereference(){
    return point->value;
}
