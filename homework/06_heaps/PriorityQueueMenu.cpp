/****************************************************************************
 *
 * File Name:  PriorityQueueDriver.cpp
 * Course:     CPTR 242
 * Source:     Book Provided Code
 *
 */
// Test driver
#include <iostream>
typedef int ItemType;
#include "PriorityQueueType.h"

void PriorityQueueMenu(std::istream &inStream, std::ostream &outStream,
                       const std::string &outputLabel) {
  // operation to be executed
  std::string command;

  ItemType item;
  PriorityQueueType<int> queue(5);
  int numCommands;

  outStream << outputLabel << std::endl;
  inStream >> command;

  numCommands = 0;
  while (command != "Quit") {
    try {
      if (command == "Menu") {
        outStream << "Select options" << std::endl;
        outStream << "  Enqueue. Adds item to queue using recursion."
                  << std::endl;
        outStream << "  Dequeue. Removes item to queue using recursion."
                  << std::endl;
        outStream << "  EnqueueIterative. Adds item to queue using iteration."
                  << std::endl;
        outStream
            << "  DequeueIterative. Removes item to queue using iteration."
            << std::endl;
        outStream << "  IsEmpty. Returns whether queue is empty." << std::endl;
        outStream << "  MakeEmpty. Returns the queue to the empty state."
                  << std::endl;
        outStream << "  IsFull. Returns whether queue is full." << std::endl;
        outStream << "  Quit. Quit application." << std::endl;
        outStream << "  Menu. Display menu." << std::endl;
      } else if (command == "Enqueue") {
        inStream >> item;
        queue.Enqueue(item);
        outStream << item << " is enqueued." << std::endl;
      } else if (command == "Dequeue") {
        queue.Dequeue(item);
        outStream << item << " is dequeued." << std::endl;
      } else if (command == "EnqueueIterative") {
        inStream >> item;
        queue.EnqueueIterative(item);
        outStream << item << " is enqueued (iterative)." << std::endl;
      } else if (command == "DequeueIterative") {
        queue.DequeueIterative(item);
        outStream << item << " is dequeued (iterative)." << std::endl;
      } else if (command == "IsEmpty") {
        if (queue.IsEmpty()) {
          outStream << "Queue is empty." << std::endl;
        } else {
          outStream << "Queue is not empty." << std::endl;
        }
      } else if (command == "IsFull") {
        if (queue.IsFull()) {
          outStream << "Queue is full." << std::endl;
        } else {
          outStream << "Queue is not full." << std::endl;
        }
      } else if (command == "MakeEmpty") {
        queue.MakeEmpty();
      }
    } catch (FullPriorityQueue) {
      outStream << "FullQueue exception thrown." << std::endl;
    } catch (EmptyPriorityQueue) {
      outStream << "EmtpyQueue exception thrown." << std::endl;
    }
    numCommands++;
    std::cout << " Command number " << numCommands << " completed."
              << std::endl;
    inStream >> command;
  };

  std::cout << "Testing completed." << std::endl;
}
