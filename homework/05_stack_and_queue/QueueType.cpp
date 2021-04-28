/*************************************************************************
 *
 * Assignment: QueueType implementation file
 *
 * File Name: QueueType.cpp
 * Course:    CPTR 242
 * Date:        ?
 */

#include "QueueType.h"

// Default class constructor
// Post: Top have been initialized.
QueueType::QueueType() {

  // TODO
}

// Post: Top and QueueStack have been reset to the empty state.
void QueueType::MakeEmpty() {

  // TODO
}

// Returns true if the queue is empty; false otherwise.
bool QueueType::IsEmpty() const {

  // TODO
}

// Returns true if the queue is full; false otherwise.
bool QueueType::IsFull() const {

  // TODO
}

// Post: If (queue is not full) newItem is at the rear of the queue;
//       otherwise a FullQueue exception is thrown.
void QueueType::Enqueue(ItemType newItem) {
  ItemType tmpItem;

  if (queueStack.IsFull()) {
    throw FullQueue();
  } else {
    // TODO
  }
}

// Post: If (queue is not empty) the front of the queue has been
//       removed and a copy returned in item;
//       otherwise a EmptyQueue exception has been thrown.
void QueueType::Dequeue(ItemType &item) {
  if (queueStack.IsEmpty())
    throw EmptyQueue();
  else {
    // TODO
  }
}

// Post: If (queue is empty) do nothing else search for oldItem in QueueStack,
// replace oldItem in newItem without breaking the order of Items
void QueueType::ReplaceItem(ItemType oldItem, ItemType newItem) {

  // TODO
}
