/*************************************************************************
 *
 * Assignment: Test driver
 *
 * File Name: TreeDriver.cpp
 * Course:    CPTR 242
 */
#include "TreeMenu.h"
#include <iostream>
#include <string>

int main() {
  std::string outputLabel = "Student Test";

  std::ofstream outStream;
  outStream.open("solutions.txt");

  TreeMenu(std::cin, outStream, outputLabel);
};