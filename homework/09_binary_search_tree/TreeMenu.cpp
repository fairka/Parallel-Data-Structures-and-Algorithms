/****************************************************************************
 *
 * File Name:  TreeMenu.cpp
 * Course:     CPTR 242
 * Source:     Book Provided Code
 *
 */
// Test driver
#include <cctype>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

#include "TreeType.h"

void TreeMenu(std::istream &inStream, std::ostream &outStream,
              std::string outputLabel) {
  std::string command; // operation to be executed

  char item;
  std::string orderItem;
  TreeType tree;
  OrderType order;
  int count = 0;
  bool found;
  bool finished;
  int numCommands;

  outStream << outputLabel << std::endl;
  inStream >> command;

  numCommands = 0;
  while (command != "Quit") {
    std::cout << command;
    if (command == "Menu") {
      outStream << "Menu options:" << std::endl;
      outStream << "  CountLeaves. Number of leaf nodes in the tree is returned"
                << std::endl;
      outStream << "  CountSingleChildren. Number of nodes with only a single "
                   "child returned."
                << std::endl;
      outStream << "  CountGreaterThan <value>. Number of nodes with values "
                   "greater than input value returned."
                << std::endl;
      outStream << "  PutItem <item>. Places item in Binary Tree" << std::endl;
      outStream << "  DeleteItem <item>. Deletes "
                   "item from Binary Tree"
                << std::endl;
      outStream << "  GetItem <item>. Returns a boolean variable if item is "
                   "found in Binary Tree"
                << std::endl;
      outStream << "  GetLength. Returns length of Binary Tree" << std::endl;
      outStream << "  GetNextItem <order>. Returns the next item in the "
                   "desired order."
                << std::endl;
      outStream << "  IsFull. Returns a boolean variable if Binary Tree is full"
                << std::endl;
      outStream
          << "  ResetTree <order>. Resets Binary Tree depending on user order"
          << std::endl;
      outStream << "  PrintTree. Prints Binary Tree" << std::endl;
      outStream << "  MakeEmpty. Empty Graph" << std::endl;
      outStream << "  Quit. Quit application." << std::endl;
      outStream << "  Menu. Display menu." << std::endl;
    } else {
      if (command == "CountLeaves") {
        count = tree.CountLeaves();
        outStream << "There are " << count << " leaves in the tree."
                  << std::endl;
      } else if (command == "CountSingleChildren") {
        count = tree.CountSingleChildren();
        outStream << "There are " << count << " single children in the tree."
                  << std::endl;
      } else if (command == "CountGreaterThan") {
        inStream >> item;
        ItemType itemType = ItemType(item);
        count = tree.CountGreaterThan(itemType);
        outStream << "There are " << count << " nodes greater than " << item
                  << " in the tree." << std::endl;
      } else if (command == "PutItem") {
        inStream >> item;
        tree.PutItem(item);
        outStream << item;
        outStream << " is inserted" << std::endl;
      } else if (command == "DeleteItem") {
        inStream >> item;
        tree.DeleteItem(item);
        outStream << item;
        outStream << " is deleted" << std::endl;
      } else if (command == "GetItem") {
        inStream >> item;
        item = tree.GetItem(item, found);
        if (found) {
          outStream << item << " found in list." << std::endl;
        } else {
          outStream << item << " not in list." << std::endl;
        }
      } else if (command == "GetLength") {
        outStream << "Number of nodes is " << tree.GetLength() << std::endl;
      } else if (command == "IsEmpty") {
        if (tree.IsEmpty()) {
          outStream << "Tree is empty." << std::endl;
        } else {
          outStream << "Tree is not empty." << std::endl;
        }
      } else if (command == "PrintTree") {
        if (tree.GetLength() > 0) {
          tree.Print(outStream);
          outStream << std::endl;
        } else {
          outStream << "Binary Tree is empty." << std::endl;
        }
      } else if (command == "ResetTree") {
        inStream >> orderItem;
        if (orderItem == "PRE_ORDER") {
          order = PRE_ORDER;
        } else if (orderItem == "IN_ORDER") {
          order = IN_ORDER;
        } else {
          order = POST_ORDER;
        }
        tree.ResetTree(order);
      } else if (command == "GetNextItem") {
        inStream >> orderItem;
        if (orderItem == "PRE_ORDER") {
          order = PRE_ORDER;
        } else if (orderItem == "IN_ORDER") {
          order = IN_ORDER;
        } else {
          order = POST_ORDER;
        }
        item = tree.GetNextItem(order, finished);
        outStream << "Next item is: " << item << std::endl;
        if (finished) {
          outStream << orderItem << " traversal is complete." << std::endl;
        }
      } else if (command == "IsFull") {
        if (tree.IsFull()) {
          outStream << "Tree is full." << std::endl;
        } else {
          outStream << "Tree is not full." << std::endl;
        }
      } else if (command == "MakeEmpty") {
        tree.MakeEmpty();
        outStream << "Tree has been made empty." << std::endl;
      } else {
        std::cout << " (Command not recognized)";
      }
    }
    numCommands++;
    std::cout << " Command is completed." << std::endl;
    inStream >> command;
  }
  outStream << "Testing completed." << std::endl;
  std::cout << "Quit" << std::endl << "Testing completed." << std::endl;
}
