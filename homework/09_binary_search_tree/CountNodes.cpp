/****************************************************************************
 *
 * Homework: Implement three functions for counting tree nodes
 *
 * File Name:  CountNodes.cpp
 * Name:       ?
 * Course:     CPTR 242
 * Date:       ?
 * Time Taken: ?
 *
 */
#include "TreeType.h"

// Post: Number of leaf nodes in the tree is returned.
// Calls recursive function to count the number of leaf nodes.
int TreeType::CountLeaves() {
  // TODO Implement function

  if (root == NULL) {
    return 0;
  }
  if (root->left == NULL && root->right == NULL) {
    return 1;
  }
  if(root->left != NULL){
      root = root->left;
      return CountLeaves();
  } else if(root->right != NULL){
      root = root ->right;
      return CountLeaves();
  }
  return CountLeaves();
}

// Calls recursive function SingleCount to count the number of
//   nodes with only one child.
int TreeType::CountSingleChildren() {
  // TODO Implement function
  return 0;
}

// Pre:  tree has been initialized.
// Post: Return value = the number of nodes in tree that
//       contain values that are greater than value.
int TreeType::CountGreaterThan(ItemType value) {
  // TODO Implement function
  return 0;
}
