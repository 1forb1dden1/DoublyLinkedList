#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>

//template <class T>
//struct node
//{
//  T     info;
//  node* next;
//  node* prev;
//};

template <class T>
class LinkedList 
{
  private:
    struct node
    {
      T     info;
      node* next;
      node* prev;
    };
    node* first; // node<T>* first
    node* last; // node<T>* last
    int length;

  public:
    LinkedList();
    ~LinkedList();
    void destroy();
    LinkedList(const LinkedList<T>& List);
    const LinkedList<T>& operator = (const LinkedList<T>& other);
    void copy(const LinkedList<T>&other);
    void printList(); 
    void deleteItem(T); 
    bool SearchItem(T const&); 
    void AddFront(T);    
    void AddBack(T);     
    bool isEmpty();
    int getLength();
    //Iterator begin();
    //Iterator end();
};

template<class T>
class Iterator
{
private:
  node* current; //pointer to current node in linked list.

public:
  Linkedlistiterator(); // constructor
  // current = null

  Linkedlistiterator(node* ptr); //overloaded constructor | current = ptr;

  T operator*();//function to overload the dereferencing operator *

  Linkedlistiterator<T> operator++(); // the iterator advance to the next node.

  bool operator == (const Linkedlistiterator<t>& right) const; // return true if this iterator is equal to the iterator specified by right.

  bool operator != (const Linkedlistiterator<t>& right) const; // return true if this iterator is not equal to the iterator to the right.

};


#endif
