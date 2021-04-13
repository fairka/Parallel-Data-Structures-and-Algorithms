/*************************************************************************
 *
 * Assignment: Searching
 *
 * File Name:   BinarySearch.cpp
 * Name:        ?
 * Course:      CPTR 242
 * Date:        ?
 */
#include "BinarySearch.h"
#include "ItemType.h"

void BinarySearch::Search(std::vector<ItemType> list, ItemType key,
                          int &location, int &comparisons) {
  // Variables to hold the low and high indices of the area being searched.
  // Starts with entire range.
  comparisons = 0;
  location = -1;

  int low = 0;
  int high = list.size() - 1;

  while (high >= low) {
    comparisons++;
    int mid = (high + low) / 2;

    switch (list.at(mid).ComparedTo(key)) {
    case LESS:
      low = mid + 1;
      break;
    case GREATER:
      high = mid - 1;
      break;
    case EQUAL:
      location = mid;
      return;
      break;
    }
  }
}