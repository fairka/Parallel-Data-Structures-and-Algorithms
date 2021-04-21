/*************************************************************************
 *
 * Assignment: Sorting
 *
 * File Name:   QuickSort.cpp
 * Name:        ?
 * Course:      CPTR 242
 * Date:        ?
 */
#include "QuickSort.h"
#include "ItemType.h"

int QuickSort::Partition(std::vector<ItemType> &list, int &comparisons,
                         int &writes, int startIndex, int endIndex) {
  int midpoint = startIndex + (endIndex - startIndex) / 2;
  ItemType pivot = list.at(midpoint);

  int low = startIndex;
  int high = endIndex;
  comparisons = 0;
  writes = 0;

  bool done = false;

  while (!done) {

    while (pivot.ComparedTo(list.at(low))) {
      comparisons++;
      low = low + 1;
    }

    while (pivot.ComparedTo(list.at(high))) {
      comparisons++;
      high = high - 1;
    }

    if (low >= high) {
      writes++;
      done = true;
    } else {
      ItemType temp = list.at(low);
      list.at(low) = list.at(high);
      list.at(high) = temp;
      low = low + 1;
      high = high - 1;
      writes += 5;
    }
  }
  return high;
}
void QuickSort::QuickSort1(std::vector<ItemType> &list, int &comparisons,
                           int &writes, int startIndex, int endIndex) {
  if (endIndex <= startIndex) {
    return;
  }

  int high = Partition(list, comparisons, writes, startIndex, endIndex);

  QuickSort1(list, comparisons, writes, startIndex, high);

  QuickSort1(list, comparisons, writes, high + 1, endIndex);
}

void QuickSort::sort(std::vector<ItemType> &list, int &comparisons,
                     int &writes) {
  writes = 0;
  comparisons = 0;

      QuickSort1(list, comparisons, writes, 0, (list.size() - 1));
}
// TODO implement search
