#include "Linked_List.h"

template <class T>
LinkedList<T>::LinkedList()
{
  first = NULL;
  last = NULL;
  T length = 0;
}

template <class T>
LinkedList<T>::~LinkedList()
{
  destroy();
}

template <class T>
void LinkedList<T>::destroy()
{
  node* h;

  while (first != NULL )
  {
    h = first;
    first = first->next;
    delete h;
   }
    length = 0;
}

template <class T>
LinkedList<T> ::LinkedList(const LinkedList<T>& other)
{
  copy(other);
}

template <class T>
const LinkedList<T>& LinkedList<T> :: operator = (const LinkedList<T>& other)
{
  if (this != &other)
  {
    destroy();
    copy(other);
  }
  return *this;
}

template <class T>
void LinkedList<T> :: copy(const LinkedList<T>& other)
{
  length = other.length;

  if (other.first == NULL)
  {
    first = NULL;
  }

  else
  {
    first = new node;
    first->info = other.first->info;

    node* p = other.first->next;
    node* q = first;

    while (p != NULL)
    {
      q->next = new node;
      q = q->next;
      q->info = p->info;
      p = p->next;
    }
    q->next = NULL;
  }
}

template <class T>
int LinkedList<T> :: getLength()
{
  return length; 
}

template <class T>
bool LinkedList<T> :: isEmpty()
{
  return first == NULL; 
}

template<class T>
void LinkedList<T> :: deleteItem(T item)
{
  if (first == NULL) { std::cout << " The list is empty."; }
  else
  {
    node* p = first;
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
      node* p = first;
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

template<class T>
bool LinkedList<T> :: SearchItem(T const& item)
{
  node* p;
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

template<class T>
void LinkedList<T> :: AddFront(T item)
{
  node* Node;
  Node = new node;
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

template<class T>
void LinkedList<T> ::AddBack(T item)
{
  node* Node;
  Node = new node;
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

template<class T>
void LinkedList<T> :: printList()
{
  if (first == NULL){ std::cout << "\nThe list is empty.\n"; }
  else
  {
    node* first_next = first;
    std::cout << "\n";
    while (first_next != NULL)
    {
      std::cout << first_next->info << " " ;
      first_next = first_next -> next;
    }
    std::cout << "\n";
  }
}
