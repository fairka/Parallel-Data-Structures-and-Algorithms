/****************************************************************************
 *
 * File Name:  TreeType.h
 * Course:     CPTR 242
 * Source:     Book Provided Code
 *
 */
#ifndef TREE_TYPE_H
#define TREE_TYPE_H

#include "QueType.h"
#include <fstream>
#include <string>

typedef char ItemType;

struct TreeNode {
  ItemType info;
  TreeNode *left;
  TreeNode *right;
};

enum OrderType { PRE_ORDER, IN_ORDER, POST_ORDER };

class TreeType {
public:
  TreeType();  // constructor
  ~TreeType(); // destructor
  TreeType(const TreeType &originalTree);
  void operator=(const TreeType &originalTree);
  // copy constructor
  void MakeEmpty();
  bool IsEmpty() const;
  bool IsFull() const;
  int GetLength() const;
  ItemType GetItem(ItemType item, bool &found);
  void PutItem(ItemType item);
  void DeleteItem(ItemType item);
  void ResetTree(OrderType order);
  ItemType GetNextItem(OrderType order, bool &finished);
  void Print(std::ostream &outFile) const;

  // Post: Number of leaf nodes in the tree is returned.
  int CountLeaves();

  // Post: Number of nodes with only a single child returned.
  int CountSingleChildren();

  // Post: Number of nodes with values greater than input value returned.
  int CountGreaterThan(ItemType value);

private:
  TreeNode *root;
  QueType preQue;
  QueType inQue;
  QueType postQue;
};

#endif // TREE_TYPE_H