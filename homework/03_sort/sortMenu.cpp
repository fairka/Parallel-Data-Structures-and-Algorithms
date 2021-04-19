/*************************************************************************
 *
 * Assignment: Test driver for Sort
 *
 * File Name: SortMenu.cpp
 * Course:    CPTR 242
 */
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "SelectionSort.h"
#include "ItemType.h"
#include <cctype>
#include <fstream>
#include <iostream>
#include <ostream>
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

void sortMenu(std::istream &inStream, std::ostream &outStream,
                  std::string outputLabel) {

  std::string command;      // operation to be executed
  std::ifstream listInFile; // file list data
  std::string data;         // data to be loaded

  InsertionSort sortInsertion;
  MergeSort sortMerge;
  QuickSort sortQuick;
  SelectionSort sortSelection;

  int number;
  ItemType item;
  std::vector<ItemType> list;
  int location;
  int comparisons;
  int writes;
  int numCommands;

  outStream << outputLabel << std::endl;
  inStream >> command;

  numCommands = 0;
  while (command != "Quit") {
    std::cout << command;
    if (command == "Menu") {
      outStream << "Menu options:" << std::endl;
      outStream << "  InsertionSort. "
                   "Sorts list using a InsertionSort Algorithm."
                << std::endl;
      outStream << "  MergeSort. "
                   "Sorts list using a MergeSort Algorithm."
                << std::endl;
      outStream << "  QuickSort. "
                   "Sorts list using a QuickSort Algorithm."
                << std::endl;
      outStream << "  SelectionSort. "
                   "Sorts list using a SelectionSort Algorithm."
                << std::endl;
      outStream << "  LoadListFromFile <data>. "
                   "Loads a vector list from data file"
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
    } else if (command == "InsertionSort") {
      sortInsertion.sort(list, comparisons, writes);
      outStream << "Insertion Sort performed " << comparisons
                << " comparisons, " << writes << " writes." << std::endl;
    } else if (command == "MergeSort") {
      sortMerge.sort(list, comparisons, writes);
      outStream << "Merge Sort performed " << comparisons << " comparisons, "
                << writes << " writes." << std::endl;
    } else if (command == "QuickSort") {
      sortQuick.sort(list, comparisons, writes);
      outStream << "Quick Sort performed " << comparisons << " comparisons, "
                << writes << " writes." << std::endl;
    } else if (command == "SelectionSort") {
      sortSelection.sort(list, comparisons, writes);
      outStream << "Selection Sort performed " << comparisons
                << " comparisons, " << writes << " writes." << std::endl;
    } else if (command == "LoadListFromFile") {
      inStream >> data;
      listInFile.close();
      listInFile.clear();

      // Checks for Type of Input Files (Testing Version / Student Version)
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
      outStream << "List Length is " << list.size() << std::endl;
    } else if (command == "MakeEmpty") {
      list.clear();
      outStream << "List has been cleared " << std::endl;
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
  outStream << "Testing completed." << std::endl;
  std::cout << "Quit" << std::endl << "Testing completed." << std::endl;
}
