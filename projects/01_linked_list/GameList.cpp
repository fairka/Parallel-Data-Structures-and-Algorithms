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
  SLelement<std::string> *head = listData;
  SLelement<std::string> *temp = NULL;

  while (head != NULL) {
    temp = head->getNext();
    free(head);
    head = temp;
  }

  listData = NULL;

  // TODO Add code here.
}

SLelement<string> *GameList::GetHead() { return listData; }

void GameList::PutGame(std::string game, std::string gameDetails,
                       double rating) {
  // TODO Add code here.

  // Create new node
  SLelement<std::string> *newElement =
      new SLelement<std::string>(game, game + "\n" + gameDetails);

  float size = 0;
  const char *col;
  if (rating == 10) {
    size = 50.0f;
    col = "blue";
  } else if (rating >= 9 && rating < 10) {
    size = 40.0f;
    col = "green";
  } else if (rating >= 7 && rating < 9) {
    size = 30.0f;
    col = "yellow";
  } else if (rating >= 4 && rating < 7) {
    size = 20.0f;
    col = "orange";
  } else {
    size = 10.0f;
    col = "red";
  }
  newElement->getVisualizer()->setSize(size);
  newElement->getVisualizer()->setColor(col);

  // Connect to Existing list
  if (listData == NULL) {
    listData = newElement;
  } else {
    newElement->setNext(listData);
    listData = newElement;
  }
  length++;
}

void GameList::GetGame(std::string title, std::string &gameDetails,
                       bool &found) {
  // TODO Add code here.
  SLelement<std::string> *head=listData;
  while (head != NULL) {
    if (head->getValue() == title) {
      found = true;
      gameDetails = head->getLabel();
      head = head->getNext();
    }
    found = false;
  }
}

void GameList::DeleteGame(std::string title) {
  // TODO Add code here.
     SLelement<std::string> *head = listData;
     SLelement<std::string> *tmp = NULL;
      if (tmp != NULL && tmp->getValue() == title)
    {
        *listData = tmp->getNext(); 
        delete tmp;            
        return;
    }
 
    
      else
    {
    while (tmp != NULL && tmp->getValue() != title)
    {
        head = tmp;
        tmp = tmp->getNext();
    }
 
    if (tmp == NULL)
        return;
 
    // Free memory
    delete tmp;
    }
}

// TODO Add code here.

void GameList::ResetList() {
  // TODO Add code here.
}

void GameList::GetNextGame(std::string &title, std::string &gameDetails) {
  // TODO Add code here.
  SLelement<std::string> *temp = currentPos;

  title = temp->getNext()->getValue();
  gameDetails = temp->getNext()->getLabel();
  temp = temp->getNext();
}
