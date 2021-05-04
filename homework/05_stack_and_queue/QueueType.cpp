/*************************************************************************
 *
 * Assignment: QueueType implementation file
 *
 * File Name: QueueType.cpp
 * Course:    CPTR 242
 * Date:        ?
 */

#include "QueueType.h"
#include "ItemType.h"
#include "StackType.h"
using namespace std;

// Default class constructor
// Post: Top have been initialized.
QueueType::QueueType() {
  int top = -1;
  // TODO
}

// Post: Top and QueueStack have been reset to the empty state.
void QueueType::MakeEmpty() {
  top = -1;
  while (tmpStack.IsFull() ) {
    tmpStack.Pop();
  }
  while(queueStack.IsFull()){
      queueStack.Pop();
  }
  // TODO
}

// Returns true if the queue is empty; false otherwise.
bool QueueType::IsEmpty() const {
    if(queueStack.IsEmpty()){
        return true;
    }else {
        return false;
  // TODO
}
}

// Returns true if the queue is full; false otherwise.
bool QueueType::IsFull() const {
     if(queueStack.IsFull()){
        return true;
    }else {
        return false;
  // TODO
}
}

// Post: If (queue is not full) newItem is at the rear of the queue;
//       otherwise a FullQueue exception is thrown.
void QueueType::Enqueue(ItemType newItem) {

  if (queueStack.IsFull()) {
    throw FullQueue();
  } else {
      queueStack.Push(newItem);
    } 

}

// Post: If (queue is not empty) the front of the queue has been
//       removed and a copy returned in item;
//       otherwise a EmptyQueue exception has been thrown.
void QueueType::Dequeue(ItemType &item) {
  if (queueStack.IsEmpty()){
    throw EmptyQueue();
  } else {
      ItemType tmpVar;
      while(!queueStack.IsEmpty()){
          tmpVar = queueStack.Top();
          queueStack.Pop();
          tmpStack.Push(tmpVar);
      }
        tmpStack.Pop();
        item = tmpVar;
        while(!tmpStack.IsEmpty()){
            tmpVar = tmpStack.Top();
            tmpStack.Pop();
            queueStack.Push(tmpVar);
        }
    }
}
    // TODO


// Post: If (queue is empty) do nothing else search for oldItem in QueueStack,
// replace oldItem in newItem without breaking the order of Items
void QueueType::ReplaceItem(ItemType oldItem, ItemType newItem) {
      ItemType item;
	  StackType tempStack;
      ItemType tmpVar;

      if(queueStack.IsEmpty()){
          return;
      }
      while(!queueStack.IsEmpty()){
          tmpVar = queueStack.Top();
          queueStack.Pop();
          if(tmpVar == oldItem){
              tmpVar = newItem;
          }
          tmpStack.Push(tmpVar);
      }
        while(!tmpStack.IsEmpty()){
            tmpVar = tmpStack.Top();
            tmpStack.Pop();
            queueStack.Push(tmpVar);
        }
    }



  // TODO