/*************************************************************************
 *
 * Assignment: Sorting
 *
 * File Name:   MergeSort.h
 * Name:        ?
 * Course:      CPTR 242
 * Date:        ?
 */
#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "ItemType.h"
#include "vector"

class MergeSort {
public:
  void sort(std::vector<ItemType> &list, int &comparisons, int &writes);
  // Function: Merge Sort a vector for key and count the number of
  // comparisons and writes.
  // Pre:     List has been initialized.
  // Post:    The list is modified to be in sorted order,
  // comparisons has the number comparisons and swaps made during the writes.

private:
  void Merge(std::vector<ItemType> &list, int &comparisons, int &writes,
             int leftFirst, int leftLast, int rightLast);
  void MergeSort1(std::vector<ItemType> &list, int &comparisons, int &writes,
                  int startIndex, int endIndex);

  // TODO Add any necessary private functions
};
#endif // MERGE_SORT_H