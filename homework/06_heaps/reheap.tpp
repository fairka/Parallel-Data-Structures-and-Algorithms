/****************************************************************************
 *
 * Homework 09: Implement ReheapDown and ReheapUp functions using iteration.
 *
 * File Name:  reheap.tpp
 * Name:       ?
 * Course:     CPTR 242
 * Date:       ?
 * Time Taken: ?
 */
#include "Heap.h"

using namespace std;

template <class ItemType>
void HeapType<ItemType>::ReheapDownIterative(int root, int bottom) {
  // TODO Implement a Iterative ReheapDown Function.
  int maxChild;
  int rightChild;
  int leftChild;

  leftChild = root * 2 + 1;
  rightChild = root * 2 + 2;
  if (leftChild <= bottom) {
    if (leftChild == bottom) {
      maxChild = leftChild;
    } else {
      if (elements[leftChild] <= elements[rightChild]) {
        maxChild = rightChild;
      } else {
        maxChild = leftChild;
      }
    }
    if (elements[root] < elements[maxChild]) {
      Swap(elements[root], elements[maxChild]);
      ReheapDown(maxChild, bottom);
    }
  }
}

template <class ItemType>
void HeapType<ItemType>::ReheapUpIterative(int root, int bottom) {
  // TODO Implement a Iterative ReheapUp Function.
  int parent;

  if (bottom > root) {
    parent = (bottom - 1) / 2;
    if (elements[parent] < elements[bottom]) {
      Swap(elements[parent], elements[bottom]);
      ReheapUp(root, parent);
    }
  }
}
