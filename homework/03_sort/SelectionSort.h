/*************************************************************************
 *
 * Assignment: Sorting
 *
 * File Name:   SelectionSort.h
 * Name:        ?
 * Course:      CPTR 242
 * Date:        ?
 */
#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include "ItemType.h"
#include "vector"

class SelectionSort {
public:
  static void sort(std::vector<ItemType> &list, int &comparisons, int &writes);
  // Function: Selection Sort a vector for key and count the number of
  // comparisons and writes.
  // Pre:     List has been initialized.
  // Post:    The list is modified to be in sorted order,
  // comparisons has the number comparisons and writes made during the sort.

private:
  // TODO Add any necessary private functions
};
#endif // SELECTION_SORT_H