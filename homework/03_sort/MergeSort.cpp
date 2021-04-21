/*************************************************************************
 *
 * Assignment: Sorting
 *
 * File Name:   MergeSort.cpp
 * Name:        ?
 * Course:      CPTR 242
 * Date:        ?
 */
#include "MergeSort.h"
#include "ItemType.h"

void MergeSort::Merge(std::vector<ItemType> &list, int &comparisons,
                      int &writes, int leftFirst, int leftLast, int rightLast) {
  int mergedSize = rightLast - leftFirst + 1;
  std::vector<ItemType> mergedNumbers(mergedSize);
  int mergePos = 0;
  int leftPos = leftFirst;
  int rightPos = leftLast + 1;
  comparisons = 0;
  writes = 2;

  // Add smallest element from left or right partition to merged numbers
  while (leftPos <= leftLast && rightPos <= rightLast) {
      comparisons++;
    if (list.at(rightPos).ComparedTo(list.at(leftPos))) {
      mergedNumbers.at(mergePos) = list.at(leftPos);
      leftPos++;
      writes+=2;
    } else {
      mergedNumbers.at(mergePos) = list.at(rightPos);
      rightPos++;
      writes+=2;
    }
    mergePos++;
    writes+=2;
    comparisons++;
  }

  // If left partition is not empty, add remaining elements to merged numbers
  while (leftPos <= leftLast) {
    mergedNumbers.at(mergePos) = list.at(leftPos);
    leftPos++;
    mergePos++;
    writes += 4;
    comparisons++;
  }

  // If right partition is not empty, add remaining elements to merged numbers
  while (rightPos <= rightLast) {
    mergedNumbers.at(mergePos) = list.at(rightPos);
    rightPos++;
    mergePos++;
    comparisons++;
    writes += 4;
  }

  // Copy merged numbers back to numbers
  for (mergePos = 0; mergePos < mergedSize; mergePos++) {
    list.at(leftFirst + mergePos) = mergedNumbers.at(mergePos);
    writes ++;
  }
}

void MergeSort::MergeSort1(std::vector<ItemType> &list, int &comparisons,
                           int &writes, int startIndex, int endIndex) {
  
  if (startIndex < endIndex) {
    // Find the midpoint in the partition
    int mid = (startIndex + endIndex) / 2;
    
    // Recursively sort left and right partitions
    MergeSort1(list, comparisons, writes, startIndex, mid);
    MergeSort1(list, comparisons, writes, mid + 1, endIndex);

    // Merge left and right partition in sorted order
    Merge(list, comparisons, writes, startIndex, mid, endIndex);
  }
}

void MergeSort::sort(std::vector<ItemType> &list, int &comparisons,
                     int &writes) {
  comparisons = 0;
  writes = 0;

  MergeSort1(list, comparisons, writes, 0, list.size() - 1);
}
