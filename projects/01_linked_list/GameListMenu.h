/*************************************************************************
 *
 * Assignment: Test driver
 *
 * File Name: GameListMenu.h
 * Course:    CPTR 242
 */
#include "GameList.h"
#include <iostream>
#include <string>

using namespace bridges;

//  we will use this class to keep track of the game details and ratings;
//  we will use that to color/size the nodes
struct am_obj {
  std::string details;
  double ratings;
};

void PrintList(std::ostream &dataFile, GameList &list);

void GameListMenu(std::istream &inStream, std::ostream &outStream,
                  std::string outputLabel);
