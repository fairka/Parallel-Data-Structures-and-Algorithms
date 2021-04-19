/*************************************************************************
 *
 * Project: GameList implemented using linked list
 *
 * File Name: GameList.cpp
 * Name:      ??
 * Course:    CPTR 242
 * Date:      ??
 *
 */
#include "GameList.h"
#include "Array.h"
#include "Bridges.h"
#include "DataSource.h"
#include "SLelement.h"

using namespace bridges;

GameList::GameList() {
  // Class constructor
  length = 0;
  listData = NULL;
}

GameList::~GameList() {
  // Post: List is empty; all items have been deallocated.
  MakeEmpty();
}

bool GameList::IsFull() const {
  // Returns true if there is no room for another actor
  //  on the free store; false otherwise.
  SLelement<string> *location;
  try {
    location = new SLelement<string>;
    delete location;
    return false;
  } catch (std::bad_alloc exception) {
    return true;
  }
}

int GameList::GetLength() const {
  // Post: Number of items in the list is returned.
  return length;
}

void GameList::MakeEmpty() {
  // TODO Add code here.
}

SLelement<string> *GameList::GetHead() { return listData; }

void GameList::PutActor(string actor, string movies, int count) {
  // TODO Add code here.
}

void GameList::GetActor(string actor, string &movies, bool &found) {
  // TODO Add code here.
}

void GameList::DeleteActor(string actor) {
  // TODO Add code here.
}

void GameList::ResetList() {
  // TODO Add code here.
}

void GameList::GetNextActor(string &actor, string &movies) {
  // TODO Add code here.
}
