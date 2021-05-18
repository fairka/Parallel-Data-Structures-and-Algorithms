/*************************************************************************
 *
 * Project 1: Game Titles and Game Details Linked List
 *
 * File Name: GameListMenu.cpp
 * Course:    CPTR 242
 */
#include "GameListMenu.h"
#include "Array.h"
#include "Bridges.h"
#include "BridgesUser.h"
#include "DataSource.h"
#include "GameList.h"
#include "SLelement.h"
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace bridges;

void PrintList(std::ostream &dataFile, GameList &list) {
  // Pre:  list has been initialized.
  //       dataFile is open for writing.
  // Post: Each component in list has been written to dataFile.
  //       dataFile is still open.
  dataFile << "PrintList: " << std::endl;
  list.ResetList();
  int length = list.GetLength();
  if (length == 0) {
    dataFile << "  ** List is empty." << std::endl;
  } else {
    for (int counter = 1; counter <= length; counter++) {
      std::string gameTitle, gameDetails;
      list.GetNextGame(gameTitle, gameDetails);
      dataFile << "  " << counter << ". " << gameTitle << std::endl;
    }
  }
}

void GameListMenu(std::istream &inStream, std::ostream &outStream,
                  std::string outputLabel) {
  // Used for test driver functionality.
  std::string option;

  // Used to interact with Title/GameDetail List.
  std::string gameTitle;
  std::string gameDetails;
  int count;

  GameList list;
  bool found; // For use with GetActor
  int numOptions;

  outStream << outputLabel << std::endl;
  inStream >> option;

  // create the Bridges object, set credentials
  BridgesUser bUser;
  Bridges bridges(bUser.getBridgesNumber(), bUser.getBridgesUserID(),
                  bUser.getBridgesAPIKey());

  bridges.setTitle("Game titles with details");
  bridges.setDescription(
      "Here the data is processed to be a list of Game Titles "
      "with all Game Details.");

  // get the Game IGN Game Collection (Meta Data)
  DataSource ds(&bridges);
  vector<Game> am_game;
  try {
    am_game = ds.getGameData();
  } catch (string ex) {
    std::cout << ex << std::endl;
  }

  //  Game Titles can repeat in the GameTitle-GameDetails pairs; so we will
  //  process the list of GameTitle-GameDetails pairs so that we get a list of
  //  GameTitles with all the GameDetails (Title, Platform, Genre, Rating). We
  //  will use a map for this
  unordered_map<std::string, am_obj> am_map;
  int max_gameDetails = 0;
  for (auto im : am_game) {
    std::string gameDetail = im.getTitle() + "\n" + im.getPlatformType() + "\n";
    for (std::string genre : im.getGameGenre()) {
      gameDetail += genre + ", ";
    }
    gameDetail += "\n";
    gameDetail += std::to_string(im.getRating());

    am_obj amo = {gameDetail, im.getRating()};
    am_map[im.getTitle()] = amo;
  }

  // Test driver menu and options
  numOptions = 0;
  while (option != "Quit") {
    std::cout << option;
    if (option == "Menu") {
      outStream << "Select options" << std::endl;
      outStream << "PrintList. Prints list." << std::endl;
      outStream << "MakeEmpty. Returns the list to the empty state."
                << std::endl;
      outStream << "IsFull. Returns whether list is full." << std::endl;
      outStream << "GetLength. Returns length of list." << std::endl;
      outStream << "GetGame <string>. Retrieves list element whose key matches "
                   "item's key."
                << std::endl;
      outStream << "PutGame <string>. Add item to list." << std::endl;
      outStream << "DeleteGame <string>. Deletes the element whose key matches "
                   "item's key."
                << std::endl;
      outStream << "ResetList. Reinitializes current position of iteration "
                   "through list."
                << endl;
      outStream << "GetNextGame. Gets next element in list." << std::endl;
      outStream
          << "Visualize. Builds the bridges visualization and prints the URL."
          << endl;
      outStream << "AddAll. Adds all Games to the list." << std::endl;
      outStream << "AddX <count>. Adds X number of Games to the list."
                << std::endl;
      outStream << "Quit. Quit application." << std::endl;
      outStream << "Menu. Display menu." << std::endl;
    } else if (option == "PrintList") {
      PrintList(outStream, list);
    } else if (option == "MakeEmpty") {
      list.MakeEmpty();
      outStream << "List has been emptied." << std::endl;
    } else if (option == "IsFull") {
      if (list.IsFull()) {
        outStream << "List is full." << std::endl;
      } else {
        outStream << "List is not full." << std::endl;
      }
    } else if (option == "GetLength") {
      outStream << "List has " << list.GetLength() << " items." << std::endl;
    } else if (option == "GetGame") {
      inStream >> gameTitle;
      list.GetGame(gameTitle, gameDetails, found);
      if (found) {
        outStream << "Game " << gameTitle << " was found." << std::endl;
        outStream << gameDetails << std::endl;
      } else {
        outStream << "Game " << gameTitle << " was not found." << std::endl;
      }
    } else if (option == "PutGame") {
      std::getline(inStream >> std::ws, gameTitle);
      if (list.IsFull()) {
        outStream << "The array is full. Item not inserted" << std::endl;
      } else {
        auto got = am_map.find(gameTitle);
        if (got != am_map.end()) {
          list.PutGame(got->first, got->second.details, got->second.ratings);
          outStream << "Game " << gameTitle << " was inserted into the list."
                    << std::endl;
        } else {
          outStream << "Game " << gameTitle << " was not found in dataset."
                    << std::endl;
        }
      }
    } else if (option == "DeleteGame") {
      std::getline(inStream >> std::ws, gameTitle);
      list.DeleteGame(gameTitle);
      outStream << gameTitle << " is deleted." << std::endl;

    } else if (option == "ResetList") {
      list.ResetList();
      outStream << "List was reset." << std::endl;
    } else if (option == "GetNextGame") {
      string gameTitle, gameDetails;
      list.GetNextGame(gameTitle, gameDetails);
      outStream << "The next item in the list is " << gameTitle << "."
                << std::endl;
    } else if (option == "Visualize") {
      // TODO remove after server has been fixed.
      bridges.setServer("clone");

      bridges.setDataStructure(list.GetHead());
      bridges.visualize();
      outStream << "List was visualized." << std::endl;
    } else if (option == "AddAll") {
      for (auto im : am_map) {
        list.PutGame(im.first, im.second.details, im.second.ratings);
      }
      outStream << "All games have been added." << std::endl;
    } else if (option == "AddX") {
      inStream >> count;
      int currentCount = 0;
      for (auto im : am_map) {
        if (count < ++currentCount) {
          break;
        }
        list.PutGame(im.first, im.second.details, im.second.ratings);
      }
      outStream << "Added " << count << " games." << std::endl;
    } else {
      std::cout << option << " is not a valid command." << std::endl;
    }
    numOptions++;
    std::cout << " Command number " << numOptions << " completed." << std::endl;
    inStream >> option;
  };

  outStream << "Test Complete." << std::endl;
  std::cout << "Quit" << endl << "Testing completed." << std::endl;
}
