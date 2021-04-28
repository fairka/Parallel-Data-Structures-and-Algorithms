/*************************************************************************
 *
 * Assignment: Test driver for queue
 *
 * File Name: QueueDriver.cpp
 * Course:    CPTR 242
 */
#include "QueueMenu.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
  std::string outputLabel = "Student Test";

  std::ofstream outStream;
  outStream.open("solutions.txt");

  QueueMenu(std::cin, outStream, outputLabel);
};
