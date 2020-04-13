#ifndef SULIST_H
#define SULIST_H

#include <iostream>
#include "Dictionary.h"


template <class DataType>
class SUList{
private:
  struct ListNode{      // The nodes of the list
    ListNode* previous;//TODO make it double linked
    DataType data;      // The data stored in the node
    ListNode* next;     // The next node in the list
    ListNode& operator=(DataType T){
      std::cout<<"testing operator="<<std::endl;
      data = T;
    }
  };
  ListNode* head;      // The front of the list
  ListNode* tail;      // The last node of the list
public:
  SUList();                      // Default ctor
  SUList(const SUList&);         // Copy ctor
  ~SUList();                     // Destructor
  DataType getFront();           // Remove & return the front
  DataType getBack();            // Remove & return the back
  void putFront(const DataType&);// Add to the front
  void putBack(const DataType&); // Add to the back

  int size() const;              // Returns the number of elements
  bool contains(const DataType&);// Tests for membership
  SUList<DataType>& operator=(const SUList<DataType>&); // Overloaded assignment
  SUList<DataType>& operator+(SUList<DataType>); //+= where the first element on the lef thsould be the bigger one
  void display() const; //prints the contents of the list from frint to back
  DataType& operator[](int);//returns the datatype in node k or throws if problem
  void clear(); //Cleans out the whole linked list similar to delete but no douyble delete errors

};
#include "SUList.cpp"
#endif
