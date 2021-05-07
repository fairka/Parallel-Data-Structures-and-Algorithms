/*************************************************************************
 *
 * Assignment: Test driver
 *
 * File Name: PriorityQueueDriver.cpp
 * Course:    CPTR 242
 */
#include "PriorityQueueMenu.h"
#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::string outputLabel = "Student Test";

  std::ofstream outStream;
  outStream.open("solutions.txt");

  PriorityQueueMenu(std::cin, outStream, outputLabel);
};
