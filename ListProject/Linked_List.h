/*intiially had my class separated into a .h and .cpp file. But, I was wondering there was a linker error when I would include "Linked_List.h" in my main file. Through some 
digging,I found out that the linker cannot find my defined template class when searching for it. When the compiler compiles, the template will be set to a certain type.
But, when the linker looks for that specific type in the cpp files. It will never find it unless we create a cpp file for every single type. This is why I only have a .h file 
and why I didn't separate them into a .h and .cpp file. */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>

template <class T>
struct node
{
  T        info;
  node<T>* next;
  node<T>* prev;
};

template <class T>
class LinkedList 
{
private:
  node<T>*  first; 
  node<T>*   last; 
  int      length;

public:

  class Iterator
  {
  private:
    node<T>* current; 
  public:
    Iterator()
    {
      current = NULL;
    }
    Iterator(node<T>* ptr)
    {
      current = ptr;
    }
    T& operator*()
    {
      return current->info;
    }
    Iterator& operator++()
    {
      current = current->next;
      return *this;
    }
    Iterator& operator--()
    {
      current = current->prev;
      return *this;
    }
    bool operator==(const Iterator& right) const
    {
      return(current == right.current);
    }
    bool operator!=(const Iterator& right) const
    {
      return (current != right.current);
    }
  };

  LinkedList()
  {
    first = NULL;
    last = NULL;
    T length = 0;
  }
  ~LinkedList()
  {
    destroy();
  } 
  void destroy()
  {
    node<T>* h;

    while (first != NULL)
    {
      h = first;
      first = first->next;
      delete h;
    }
    length = 0;
  }
  LinkedList(const LinkedList<T>& other)
  {
    copy(other);
  }
  const LinkedList<T>& operator = (const LinkedList<T>& other)
  {
    if (this != &other)
    {
      destroy();
      copy(other);
    }
    return *this;
  }
  void copy(const LinkedList<T>& other)
  {
    length = other.length;

    if (other.first == NULL)
    {
      first = NULL;
    }

    else
    {
      first = new node<T>;
      first->info = other.first->info;

      node<T>* p = other.first->next;
      node<T>* q = first;

      while (p != NULL)
      {
        q->next = new node<T>;
        q = q->next;
        q->info = p->info;
        p = p->next;
      }
      q->next = NULL;
    }
  }
  void printList()
  {
    if (first == NULL) { std::cout << "\nThe list is empty.\n"; }
    else
    {
      node<T>* first_next = first;
      while (first_next != NULL)
      {
        std::cout << first_next->info << " ";
        first_next = first_next->next;
      }
      std::cout << "\n";
    }
  }
  void deleteItem(T item)
  {
    if (first == NULL) { std::cout << " The list is empty."; }
    else
    {
      node<T>* p = first;
      if (p == nullptr)
      {
        std::cout << "The list is empty. " << std::endl;
      }
      else if (p->info == item)
      {
        first = p->next;
        p->next->prev = nullptr;
        p->next = nullptr;
        delete p; length--;
        std::cout << "\nThe number has been deleted\n" << std::endl;
      }
      else
      {
        node<T>* p = first;
        while (p->next != nullptr && p->info != item)
        {
          p = p->next;
        }
        if (p->info == item)
        {
          p->prev->next = p->next;
          p->next->prev = p->prev;
          delete p; length--;
          std::cout << "\nThe number has been deleted\n" << std::endl;
        }
      }
    }
  }
  bool SearchItem(T const& item)
  {
    node<T>* p;
    if (first == nullptr)
    {
      return false;
    }
    if (last->info == item || first->info == item)
    {
      return true;
    }
    else
    {
      p = first;
      while (p->next != nullptr && p->info != item)
      {
        p = p->next;
      }
      if (p->info == item)
      {
        return true;
      }
    }
    return false;
  }
  void AddFront(T item)
  {
    node<T>* Node;
    Node = new node<T>;
    Node->info = item;
    Node->prev = NULL;
    Node->next = first;
    if (first == NULL)
    {
      last = Node;
      first = Node;
    }
    else
    {
      first->prev = Node;
      first = Node;
    }
    length++;
  }
  void AddBack(T item)
  {
    node<T>* Node;
    Node = new node<T>;
    Node->info = item;
    Node->next = NULL;
    Node->prev = last;
    if (first == NULL)
    {
      last = Node;
      first = Node;
    }
    else
    {
      last->next = Node;
      last = Node;
    }
    length++;
  }
  bool isEmpty()
  {
    return first == NULL;
  }
  int getLength()
  {
    return length;
  }
  Iterator firstnode()
  {
    return Iterator(first);
  }
  Iterator lastnode()
  {
    return Iterator(last);
  }
  Iterator end()
  {
    return Iterator(nullptr);
  }
};

#endif

