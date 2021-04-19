/*************************************************************************
 *
 * Assignment: The following definitions go into file ItemType.cpp.
 *
 * File Name:  ItemType.cpp
 * Course:     CPTR 242
 * Source:     C++ Plus Data Structures 6th Edition
 *             by Nell Dale, Chip Weems, Tim Richards
 */
#include "ItemType.h"
#include <fstream>
#include <iostream>

ItemType::ItemType() { value = 0; }

RelationType ItemType::ComparedTo(ItemType otherItem) const {
  if (value < otherItem.value) {
    return LESS;
  } else if (value > otherItem.value) {
    return GREATER;
  } else {
    return EQUAL;
  }
}

void ItemType::Initialize(int number) { value = number; }

void ItemType::Print(std::ostream &out) const {
  // pre:  out has been opened.
  // post: value has been sent to the stream out.
  out << value;
}
