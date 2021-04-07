/*************************************************************************
 *
 * Assignment: Test driver for Search
 *
 * File Name: SearchTest.cpp
 * Course:    CPTR 242
 */
#include "BinarySearch.h"
#include "ItemType.h"
#include "LinearSearch.h"
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>

std::ostream &operator<<(std::ostream &os, const std::vector<ItemType> &input) {
  os << "[";
  bool first = true;
  for (auto const &i : input) {
    if (first) {
      first = false;
    } else {
      os << ", ";
    }
    i.Print(os);
  }
  os << "]";
  return os;
}

inline bool fileExists(const std::string &name) {
  if (FILE *file = fopen(name.c_str(), "r")) {
    fclose(file);
    return true;
  } else {
    return false;
  }
}

void searchDriver(std::istream &inStream, std::ostream &outStream,
                  std::string outputLabel) {

  std::string command;      // operation to be executed
  std::ifstream listInFile; // file list data
  std::string data;         // data to be loaded

  int number;
  ItemType item;
  std::vector<ItemType> list;
  int location;
  int comparisons;
  int numCommands;

  outStream << outputLabel << std::endl;
  inStream >> command;

  numCommands = 0;
  while (command != "Quit") {
    std::cout << command;
    if (command == "Menu") {
      outStream << "Menu options:" << std::endl;
      outStream << "  LinearSearch <key>. "
                   "Searches key within the list using a Linear Algorithm."
                << std::endl;
      outStream << "  BinarySearch <key>. "
                   "Searches key within the list using a Binary Algorithm"
                << std::endl;
      outStream << "  LoadListFromFile <data>. "
                   "Searches key within the list using a Binary Algorithm"
                << std::endl;
      outStream << "  GetLength. "
                   "Returns size of list"
                << std::endl;
      outStream << "  MakeEmpty. "
                   "Clears List"
                << std::endl;
      outStream << "  PrintList. "
                   "Prints out list"
                << std::endl;
      outStream << "  Quit. Quit application." << std::endl;
      outStream << "  Menu. Display menu." << std::endl;
    } else if (command == "LinearSearch") {
      inStream >> number;
      item.Initialize(number);
      LinearSearch::Search(list, item, location, comparisons);
      item.Print(outStream);
      if (location >= 0) {
        outStream << " was found at " << location << " in list." << std::endl;
      } else {
        outStream << " is not in list." << std::endl;
      }
      outStream << "Linear search performed " << comparisons << " comparisons."
                << std::endl;
    } else if (command == "BinarySearch") {
      inStream >> number;
      item.Initialize(number);
      BinarySearch::Search(list, item, location, comparisons);
      item.Print(outStream);
      if (location >= 0) {
        outStream << " was found at " << location << " in list." << std::endl;
      } else {
        outStream << " is not in list." << std::endl;
      }
      outStream << "Binary search performed " << comparisons << " comparisons."
                << std::endl;
    } else if (command == "LoadListFromFile") {
      inStream >> data;
      listInFile.close();
      listInFile.clear();

      //Checks for Type of Input Files (Testing Version / Student Version)
      if (!fileExists(data) && ((data.find("/") != std::string::npos) == 0)) {
        // Change path for local testing.
        data = "../test_input/" + data;
      } 

      listInFile.open(data.c_str());
      if (!listInFile) {
        std::cout << "Data file not found." << std::endl;
        return;
      }
      listInFile >> number;
      while (number > 0) {
        item.Initialize(number);
        list.push_back(item);
        listInFile >> number;
      }
      outStream << data << " has loaded " << list.size() << " items."
                << std::endl;
    } else if (command == "GetLength") {
      outStream << "Length is " << list.size() << std::endl;
    } else if (command == "MakeEmpty") {
      list.clear();
    } else if (command == "PrintList") {
      outStream << list << std::endl;
    } else {
      std::cout << " is not a valid command --";
    }
    numCommands++;
    std::cout << " Command number " << numCommands << " completed."
              << std::endl;
    inStream >> command;
  };

  std::cout << "Quit" << std::endl << "Testing completed." << std::endl;
}
