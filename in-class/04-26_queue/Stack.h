#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "SinglyLinkedList.h"

class Stack {
private:
   LinkedList linkedList;

public:
   Stack() {
   }
   
   void Push(int newData) {
      // Create a new node and prepend
      Node* newNode = new Node(newData);
      linkedList.Prepend(newNode);
   }
   
   int Pop() {
      // Copy list head's data
      int poppedItem = linkedList.GetHeadData();
      
      // Remove list head
      linkedList.RemoveAfter(nullptr);
      
      // Return popped item
      return poppedItem;
   }
   
   void Print(std::ostream& printStream) {
      linkedList.PrintList(printStream);
   }
};

#endif