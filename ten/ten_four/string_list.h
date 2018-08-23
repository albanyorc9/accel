#ifndef GUARD_string_list
#define GUARD_string_list

#include <string>
#include <cstddef>

// Node
struct Node{
    Node* prev;
    Node* next;
    std::string value;
};

class String_list{
public:
    // Constructors
    String_list();

    // Iterator
    class Iterator{
    public:
        Iterator(Node*);
        Iterator(const Iterator&);

        bool compare(const Iterator&) const;
        void increment();
        void decrement();
        std::string dereference();

        Node* point;

    };

    // Members
    typedef size_t size_type;

    // Functions
    Iterator begin() const;
    Iterator end() const;
    bool empty() const;
    size_type size() const;
    void push_back(const std::string&);
    Iterator erase(Iterator);

private:
    // Members
    Node* head;
    Node* tail;

};

#endif // GUARD_string_list
