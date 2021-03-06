#include <iostream>
#include "Linked_List.h"


int printmenu()
{
  int x;
  std::cout << "\n1: Print the list.";
  std::cout << "\n2: Add an item to the front of the list";
  std::cout << "\n3: Add an item to the back of the list";
  std::cout << "\n4: Delete an item from the list";
  std::cout << "\n5: Search the list for a item";
  std::cout << "\n6: Return the number of items in the list";
  std::cout << "\n7: Iterate from the front";
  std::cout << "\n8: Iterate from the back";
  std::cout << "\n9: Quit.\n\n";
  std::cin >> x; std::cout << "\n";

  return x;
}
void insertItemFront(LinkedList<int>& l)
{
  int num;
  std::cout << "\nEnter insertion number: "; std::cin >> num;
  l.AddFront(num);
  std::cout << "\nThe number has been inserted\n" << std::endl;
}
void insertItemBack(LinkedList<int>& l)
{
  int num;
  std::cout << "\nEnter insertion number: "; std::cin >> num;
  l.AddBack(num);
  std::cout << "\nThe number has been inserted\n" << std::endl;
}
void deleteListItem(LinkedList<int>& l)
{
  int num;
  std::cout << "\nEnter the number to delete: "; std::cin >> num;
  l.deleteItem(num);
}
void searchList(LinkedList<int>& l)
{
    int num = 0;
    std::cout << "\nFind Number: "; std::cin >> num;
    if (l.SearchItem(num) == 0)
    {
        std::cout << "The item is not in the list. \n";
    }
    else
    {
        std::cout << "The item is in the list. \n";
    }
}
void Length(LinkedList<int>& l)
{
  int length;
  length = l.getLength();
  std::cout << "\nThis List has " << length << " nodes." << std::endl;
}
void IterateFront(LinkedList<int>& l, LinkedList<int>::Iterator i)
{
  std::cout << "\n";
  for (auto i = l.firstnode(); i != l.end(); ++i)
  {
    std::cout << * i << " ";
  }
  std::cout << "\n";
}
void IterateBack(LinkedList<int>& l, LinkedList<int>::Iterator i)
{
  std::cout << "\n";
  for (auto i = l.lastnode(); i != l.end(); --i)
  {
    std::cout << *i << " ";
  }
  std::cout << "\n";
}

int main()
{
  LinkedList<int> List; LinkedList<int> List2; LinkedList<int>::Iterator iterator;
  int choice;
  choice = printmenu();
  while (choice != 9)
  {
    switch (choice)
    {
    case 1: List.printList(); break;
    case 2: insertItemFront(List); break;
    case 3: insertItemBack(List); break;
    case 4: deleteListItem(List); break;
    case 5: searchList(List); break;
    case 6: Length(List); break;
    case 7: IterateFront(List, iterator); break;
    case 8: IterateBack(List, iterator); break;

    default: std::cout << "\n Enter a valid choice: ";
    }
    choice = printmenu();
  }
  std::cout << "\n----------------------------\n" << std::endl;
  std::cout << "Testing Copy constructor, and destructor. \n";
  List2 = List;
  std::cout << "\nCopying List in List2. \n";
  std::cout << "\nList 2: "; List2.printList();
  std::cout << "\nPrinting List2. \n";
  List2.~LinkedList();
  std::cout << "\nDeleting List2. \n";
  List2.printList();

}
