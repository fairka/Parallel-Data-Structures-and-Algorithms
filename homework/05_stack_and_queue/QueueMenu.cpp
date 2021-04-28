/*************************************************************************
 *
 * Assignment: ReplaceItemQueue driver file
 *
 * File Name: QueuMenu.cpp
 * Course:    CPTR 242
 */
#include "QueueMenu.h"
#include "StackType.h"
#include <fstream>
#include <iostream>

void QueueMenu(std::istream &inStream, std::ostream &outStream,
               std::string outputLabel) {
  std::string command; // operation to be executed

  ItemType item;
  ItemType itemNew;
  ItemType itemOld;
  int numCommands;

  QueueType queue;

  outStream << outputLabel << std::endl;
  inStream >> command;

  numCommands = 0;
  while (command != "Quit") {
    std::cout << command;
    if (command == "Menu") {
      outStream << "Menu options:" << std::endl;
      outStream << "  Enqueue <item>. Adds Item at the rear of Queue"
                << std::endl;
      outStream << "  Dequeue. Removes first item in Queue" << std::endl;
      outStream << "  IsEmpty. Returns true if Queue List is empty"
                << std::endl;
      outStream << "  IsFull. Returns true if Queue List reach max limit of "
                   "items it can hold"
                << std::endl;
      outStream << "  ReplaceItem <oldItem> <newItem>. Updates oldItem in "
                   "Queue with the newItem"
                << std::endl;
      outStream << "  Print. Prints Queue list" << std::endl;
      outStream << "  MakeEmpty. Clears Queue list" << std::endl;
      outStream << "  Quit. Quit application." << std::endl;
      outStream << "  Menu. Display menu." << std::endl;
      numCommands++;
    } else {
      try {
        if (command == "Enqueue") {
          inStream >> item;
          queue.Enqueue(item);
          outStream << item << " is enqueued." << std::endl;
        } else if (command == "Dequeue") {
          queue.Dequeue(item);
          outStream << item << " is dequeued. " << std::endl;
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
        } else if (command == "ReplaceItem") {
          inStream >> itemOld;
          inStream >> itemNew;
          queue.ReplaceItem(itemOld, itemNew);
          std::string s1(1, itemOld);
          std::string s2(1, itemNew);
          outStream << s1 + " was replaced with " + s2 << std::endl;
        } else if (command == "Print") {
          PrintQueue(outStream, queue);
        } else if (command == "MakeEmpty") {
          outStream << "Queue is now Empty." << std::endl;
          queue.MakeEmpty();
        } else {
          std::cout << command << " Command is not recognized." << std::endl;
        }
      } catch (FullQueue) {
        outStream << "FullQueue exception thrown." << std::endl;
      } catch (EmptyQueue) {
        outStream << "EmptyQueue exception thrown." << std::endl;
      }
    }
    numCommands++;
    std::cout << " Command number " << numCommands << " completed."
              << std::endl;
    inStream >> command;
  }
  outStream << "Testing completed." << std::endl;
  std::cout << "Quit" << std::endl << "Testing completed." << std::endl;
}

void PrintQueue(std::ostream &dataFile, QueueType &queue) {
  // Pre:  list has been initialized.
  //       dataFile is open for writing.
  // Post: Each component in list has been written to dataFile.
  //       dataFile is still open.
  QueueType tempQ;
  ItemType item;
  dataFile << "PrintQueue: ";

  if (queue.IsEmpty()) {
    dataFile << "List is empty.";
  }

  while (!queue.IsEmpty()) {
    queue.Dequeue(item);
    std::string s(1, item);
    dataFile << s + " ";
    tempQ.Enqueue(item);
  }
  // restore queue
  while (!tempQ.IsEmpty()) {
    tempQ.Dequeue(item);
    queue.Enqueue(item);
  }

  dataFile << std::endl;
}
