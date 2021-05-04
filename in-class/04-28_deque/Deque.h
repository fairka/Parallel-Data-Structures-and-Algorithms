#ifndef DEQUE_H
#define DEQUE_H

#include "DoublyLinkedList.h"

class Deque {
private:
   LinkedList linkedList;

public:
   Deque() {
   }
   
   void PushFront(int newData) {
      // TODO
      //adds new head
      Node* newNode = new Node(newData);
       
      linkedList.Prepend(newNode);
   }
   
   void PushBack(int newData) {
      // TODO
      //adds new tail
      Node* newNode = new Node(newData);
       
      linkedList.Append(newNode);
   }

   int PopFront() {
      // TODO
      //removes head
      
      linkedList.Remove(linkedList.getHead());
   }
   
   int PopBack() {
      // TODO
      //removes tail
      linkedList.Remove(linkedList.getTail());
   }

   int PeekFront() {
      // TODO
      //prints head
      
   }
   
   int PeekBack() {
      // TODO
      //prints tail 
   }
   
   void Print(std::ostream& printStream) {
      linkedList.PrintList(printStream);
   }
};

#endif