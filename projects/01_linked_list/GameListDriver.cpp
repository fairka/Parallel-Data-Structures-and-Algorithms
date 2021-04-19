/*************************************************************************
 *
 * Assignment: Test driver for Game
 *
 * File Name: GameListDriver.cpp
 * Course:    CPTR 242
 */
#include "GameListMenu.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
  std::string outputLabel = "Student Test";

  std::ofstream outStream;
  outStream.open("solutions.txt");

  GameListMenu(std::cin, outStream, outputLabel);
};