#ifndef QUEUE_H
#define QUEUE_H

#include "SinglyLinkedList.h"

class Queue {
private:
   LinkedList linkedList;

public:
   Queue() {
   }
   
   void Enqueue(int newData) {
      // Create a new node
      Node* newNode = new Node(newData);
       
      // Insert as list tail (end of queue)
      linkedList.Append(newNode);
   }
   
   int Dequeue() {
      // Copy list head's data
      int dequeuedItem = linkedList.GetHeadData();
      
      // Remove list head
      linkedList.RemoveAfter(nullptr);
      
      // Return dequeued item
      return dequeuedItem;
   }
   
   void Print(std::ostream& printStream) {
      linkedList.PrintList(printStream);
   }
};

#endif