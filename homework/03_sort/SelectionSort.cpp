/*************************************************************************
 *
 * Assignment: Sorting
 *
 * File Name:   SelectionSort.cpp
 * Name:        ?
 * Course:      CPTR 242
 * Date:        ?
 */
#include "SelectionSort.h"
#include "ItemType.h"
#include <vector>

// TODO implement search

void SelectionSort::sort(std::vector<ItemType> &list, int &comparisons,
                         int &writes) {
  comparisons = 0;  
  writes = 0;                         
  int listSize = list.size();
  for (int i = 0; i < listSize - 1; i++) {
    
    int min = i;
    for(int j = i +1; j < listSize; j++){
        comparisons++;
    switch (list.at(min).ComparedTo(list.at(j))) {
    case LESS:
      break;
    case GREATER:
       min=j;
      break;
    case EQUAL:
      break;
    }
    }
        ItemType temp = list.at(i);
        list.at(i) = list.at(min);
        list.at(min) = temp;
        writes = writes + 3;
        
      
    }
}
