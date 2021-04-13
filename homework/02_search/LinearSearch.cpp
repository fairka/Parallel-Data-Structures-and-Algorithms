/*************************************************************************
 *
 * Assignment: Searching
 *
 * File Name:   LinearSearch.cpp
 * Name:        ?
 * Course:      CPTR 242
 * Date:        ?
 */
#include "LinearSearch.h"
#include "ItemType.h"

// TODO implement search

void LinearSearch::Search(std::vector<ItemType> list, ItemType key,
                          int &location, int &comparisons) {
  int n = list.size();
  location = -1;
  comparisons = 0;
  for (int i = 0; i < n; i++) {
    comparisons++;
    switch (list.at(i).ComparedTo(key)) {
    case LESS:
      break;
    case GREATER:
      return;
      break;
    case EQUAL:
      location = i;
      return;
      break;
    }
  }
}
