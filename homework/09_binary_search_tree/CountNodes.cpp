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

int recursiveLeafCount(TreeNode *node);
int recursiveSingleCount(TreeNode *node);
int recursiveGreaterCount(TreeNode *node, ItemType value);

// Post: Number of leaf nodes in the tree is returned.
// Calls recursive function to count the number of leaf nodes
int recursiveLeafCount(TreeNode *node) {
  if (node == NULL) {
    return 0;
  }
  if (node->left == NULL && node->right == NULL) {
    return 1;
  } else {
    return recursiveLeafCount(node->left) + recursiveLeafCount(node->right);
  }
}

int TreeType::CountLeaves() { return recursiveLeafCount(root); }

int recursiveSingleCount(TreeNode *node) {
  if (node == NULL) {
    return 0;
  }

  int res = 0;
  if (node->left != NULL && node->right == NULL ||
      node->left == NULL && node->right != NULL) {
    res++;
  }
  res += recursiveSingleCount(node->left) + recursiveSingleCount(node->right);
  return res;
}

int TreeType::CountSingleChildren() { return recursiveSingleCount(root); }

int recursiveGreaterCount(TreeNode *node, ItemType value) {
  if (node == NULL) {
    return 0;
  }

  int count = 0;
  if (node->left->info > value && node->right->info < value ||
      node->left->info < value && node->right->info > value) {
    count++;
  }
  count += recursiveGreaterCount(node->left, value) +
           recursiveGreaterCount(node->right, value);
  return count;
}
// Pre:  tree has been initialized.
// Post: Return value = the number of nodes in tree that
//       contain values that are greater than value.
int TreeType::CountGreaterThan(ItemType value) {
  // TODO Implement function

  return recursiveGreaterCount(root, value);
}

int CountNodes(TreeNode *node) {
  if (node == NULL)
    return 0;
  else
    return CountNodes(node->left) + CountNodes(node->right) + 1;
}
