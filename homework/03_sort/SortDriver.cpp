/*************************************************************************
 *
 * Assignment: Test driver for Sort
 *
 * File Name: SortDriver.cpp
 * Course:    CPTR 242
 */
#include "sortMenu.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
  std::string outputLabel = "Student Test";

  std::ofstream outStream;
  outStream.open("solutions.txt");

  sortMenu(std::cin, outStream, outputLabel);
};
