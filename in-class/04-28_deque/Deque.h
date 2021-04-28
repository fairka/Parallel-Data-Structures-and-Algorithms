#ifndef DEQUE_H
#define DEQUE_H

#include "DoubleLinkedList.h"

class Deque {
private:
   LinkedList linkedList;

public:
   Deque() {
   }
   
   void PushFront(int newData) {
      // TODO
   }
   
   void PushBack(int newData) {
      // TODO
   }

   int PopFront() {
      // TODO
   }
   
   int PopBack() {
      // TODO
   }

   int PeekFront() {
      // TODO
   }
   
   int PeekBack() {
      // TODO
   }
   
   void Print(std::ostream& printStream) {
      linkedList.PrintList(printStream);
   }
};

#endif