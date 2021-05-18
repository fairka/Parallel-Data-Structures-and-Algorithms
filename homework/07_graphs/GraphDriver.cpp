/*************************************************************************
 *
 * Assignment: Test driver
 *
 * File Name: GraphDriver.cpp
 * Course:    CPTR 242
 */
#include "GraphMenu.h"
#include <iostream>
#include <string>

int main() {
  std::string outputLabel = "Student Test";

  std::ofstream outStream;
  outStream.open("solutions.txt");

  GraphMenu(std::cin, outStream, outputLabel);
};
