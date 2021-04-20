/*************************************************************************
 *
 * Assignment: Sorting
 *
 * File Name:   InsertionSort.cpp
 * Name:        ?
 * Course:      CPTR 242
 * Date:        ?
 */
#include "InsertionSort.h"
#include "ItemType.h"

void InsertionSort::sort(std::vector<ItemType> &list, int &comparisons, int &writes){
    int listSize = list.size();
    writes = 0;
    comparisons =0;
     for (int i = 1; i < listSize; i++) {
      int j = i;
      comparisons++;
      while (j > 0 && list.at(j-1).ComparedTo(list.at(j))) {
         // Swap numbers[j] and numbers [j - 1]
         ItemType temp = list.at(j);
         list.at(j) = list.at(j-1);
         list.at(j-1) = temp;
         j--;
         comparisons++;
         writes += 3;
      }
   }
}

// TODO implement search
