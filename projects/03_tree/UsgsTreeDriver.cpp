/*************************************************************************
 *
 * Project: Test driver
 *
 * File Name: UsgsTreeDriver.cpp
 * Course:    CPTR 242
 */
#include "UsgsTreeMenu.h"
#include <iostream>
#include <string>

int main() {
  std::string outputLabel = "Student Test";

  std::ofstream outStream;
  outStream.open("solutions.txt");

  UsgsTreeMenu(std::cin, outStream, outputLabel);
};
