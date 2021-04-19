/*************************************************************************
 *
 * Assignment: Sorting
 *
 * File Name:   QuickSort.h
 * Name:        ?
 * Course:      CPTR 242
 * Date:        ?
 */
#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "ItemType.h"
#include "vector"

class QuickSort {
public:
  void sort(std::vector<ItemType> &list, int &comparisons, int &writes);
  // Function: Quick Sort a vector for key and count the number of
  // comparisons and writes.
  // Pre:     List has been initialized.
  // Post:    The list is modified to be in sorted order,
  // comparisons has the number comparisons and writes made during the sort.
private:
  // TODO Add any necessary private functions
};
#endif // QUICK_SORT_H