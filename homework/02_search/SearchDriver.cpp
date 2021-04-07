/*************************************************************************
 *
 * Assignment: Test driver for Search
 *
 * File Name: SearchDriver.cpp
 * Course:    CPTR 242
 */
#include "searchMenu.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
  std::string outputLabel;

  // Prompt for test name
  std::cout << "Enter name of test run; press return." << std::endl;
  std::cin >> outputLabel;

  std::ofstream outStream;
  outStream.open("solutions.txt");

  searchDriver(std::cin, outStream, outputLabel);
};
