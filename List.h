#ifndef LIST_H
#define LIST_H
/* List.h
 *
 * doubly-linked, double-ended list with Iterator interface
 * Project UID c1f28c309e55405daf00c565d57ff9ad
 * EECS 280 Project 4
 */

#include <iostream>
#include <cassert> //assert
#include <cstddef> //NULL


template <typename T>
class List {
  //OVERVIEW: a doubly-linked, double-ended list with Iterator interface
public:

  //EFFECTS:  returns true if the list is empty
    bool empty() const{
        return (first == nullptr || last == nullptr);
    }

  //EFFECTS: returns the number of elements in this List
  //HINT:    Traversing a list is really slow.  Instead, keep track of the size
  //         with a private member variable.  That's how std::list does it.
    int size() const{
        return size_list;
    }
    
    List& operator=(const List &rhs){
        if (this == &rhs){
            return *this;
        }
        clear();
        copy_all(rhs);
        return *this;
    }
    

  //REQUIRES: list is not empty
  //EFFECTS: Returns the first element in the list by reference
    T & front(){
        assert(!empty());
        return first -> datum;
    }

  //REQUIRES: list is not empty
  //EFFECTS: Returns the last element in the list by reference
    T & back(){
        assert(!empty());
        return last -> datum;
    }

  //EFFECTS:  inserts datum into the front of the list
    void push_front(const T &datum){
        Node *p = new Node;
        p -> datum = datum;
        if (empty()){
            last = p;
            p -> next = nullptr;
        }else{
            p -> next = first;
            first -> prev = p;
        }
        p -> prev = nullptr;
        first = p;
        size_list++;
    }

  //EFFECTS:  inserts datum into the back of the list
    void push_back(const T &datum){
        Node *p = new Node;
        p -> datum = datum;
        if (empty()){
            first = p;
            p -> prev = nullptr;
        }else{
            p -> prev = last;
            last -> next = p;
        }
        p -> next = nullptr;
        last = p;
        size_list++;
    }

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the front of the list
    void pop_front(){
        assert(!empty());
        if (first == last){
            delete last;
            first = nullptr;
            last = nullptr;
        }else{
            Node *pop = first;
            first = pop -> next;
            delete pop;
            first -> prev = nullptr;
        }
        size_list--;
    }

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the back of the list
    void pop_back(){
        assert(!empty());
        if(last == first){
         delete first;
         first = nullptr;
         last = nullptr;
        }
        else{
         Node *pop = last;
         last = pop -> prev;
         delete pop;
         last -> next = nullptr;
        }
        size_list--;
    }

  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes all items from the list
    void clear(){
        while (!empty()){
            pop_front();
        }
       
    }
  // You should add in a default constructor, destructor, copy constructor,
  // and overloaded assignment operator, if appropriate. If these operations
  // will work correctly without defining these, you can omit them. A user
  // of the class must be able to create, copy, assign, and destroy Lists
    //default constructor
    List() : first(nullptr), last(nullptr), size_list(0){}
    //copy constructor
    List(const List<T> &other) : first(nullptr), last(nullptr),size_list(0)
    {copy_all(other);}
    //destructor
    ~List(){
        clear();
    }

private:
  //a private type
  struct Node {
    Node *next;
    Node *prev;
    T datum;
  };

  //REQUIRES: list is empty
  //EFFECTS:  copies all nodes from other to this
    void copy_all(const List<T> &other){
        for (Node *n = other.first; n; n = n -> next){
            push_back(n -> datum);
        }
    }
  Node *first;   // points to first Node in list, or nullptr if list is empty
  Node *last;    // points to last Node in list, or nullptr if list is empty
  int size_list;
public:
  ////////////////////////////////////////
  class Iterator {
    //OVERVIEW: Iterator interface to List

    // You should add in a default constructor, destructor, copy constructor,
    // and overloaded assignment operator, if appropriate. If these operations
    // will work correctly without defining these, you can omit them. A user
    // of the class must be able to create, copy, assign, and destroy Iterators.

    // Your iterator should implement the following public operators: *,
    // ++ (prefix), default constructor, == and !=.

  public:
    // This operator will be used to test your code. Do not modify it.
    // Requires that the current element is dereferenceable.
    Iterator& operator--() {
      assert(node_ptr);
      node_ptr = node_ptr -> prev;
      return *this;
    }
      
    T& operator*() const{
      assert(node_ptr);
      return node_ptr -> datum;
    }
    Iterator& operator++() {
      assert(node_ptr);
      node_ptr = node_ptr -> next;
      return *this;
    }
   
    bool operator==(Iterator rhs) const{
        return node_ptr == rhs.node_ptr;
    }
      
    bool operator!=(Iterator rhs) const{
        return node_ptr != rhs.node_ptr;
      }

      
    Iterator() : node_ptr(nullptr){}
      
  private:
    Node *node_ptr; //current Iterator position is a List node
    // add any additional necessary member variables here
    
    // add any friend declarations here
    friend class List;
    // construct an Iterator at a specific position
    Iterator(Node *p) : node_ptr(p){}

  };//List::Iterator
  ////////////////////////////////////////

  // return an Iterator pointing to the first element
    Iterator begin() const{
        return Iterator(first);
    }
      

  // return an Iterator pointing to "past the end"
    Iterator end() const {
        return Iterator();
    }

  //REQUIRES: i is a valid, dereferenceable iterator associated with this list
  //MODIFIES: may invalidate other list iterators
  //EFFECTS: Removes a single element from the list container
    void erase(Iterator i){
        Node *victim = i.node_ptr;
        if (i.node_ptr == first){
            pop_front();
        }
        else if (i.node_ptr == last){
            pop_back();
        }
        else{
        victim -> prev -> next = victim -> next;
        victim -> next -> prev = victim -> prev;
        delete victim;
        size_list--;
        }
    }

  //REQUIRES: i is a valid iterator associated with this list
  //EFFECTS: inserts datum before the element at the specified position.
    void insert(Iterator i, const T &datum){
        if (i.node_ptr == first){
            push_front(datum);
        }else if (i == end()){
            push_back(datum);
        }else{
            //Node *nt = new Node;
            Node *after = i.node_ptr->prev;
            Node *nt = new Node;
      //       n->datum = datum;
      // it.node_ptr->next = n;
      // n->prev = it.node_ptr;
      // n->next = after;
      // after->prev = n;

            // nt -> next = i.node_ptr;
            // nt -> prev = i.node_ptr -> prev;
            // nt -> datum = datum;
            // i.node_ptr -> prev -> next = nt;
            // i.node_ptr -> prev = nt;
            // size_list++;

            //
            nt -> next = i.node_ptr;
            nt -> prev = after;
            nt -> datum = datum;
            after -> next = nt;
            after = nt;
            //delete after;
            size_list++;
        }
    }

};//List


////////////////////////////////////////////////////////////////////////////////
// Add your member function implementations below or in the class above
// (your choice). Do not change the public interface of List, although you
// may add the Big Three if needed.  Do add the public member functions for
// Iterator.


#endif // Do not remove this. Write all your code above this line.
