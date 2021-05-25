/* insert
 * inserts data item d into tree; note that this is a BST so it is ordered
 */
void insert(TreeData d, TreeNode **tptr) {
  // create new node for data
  TreeNode *toInsert = newTreeNode(d);
  TreeNode *curr = *tptr;
  if (curr == NULL) {
    *tptr = toInsert; // make this the tree
    return;
  }
  // check value of t to see if new node should be to the right or left of curr
  while (curr != NULL) {
    if (d < curr->value) { // goes to left
      if (curr->left == NULL) {
        curr->left = toInsert;
        return;
      }
      // keep going left
      curr = curr->left;
    } else { // goes to right
      if (curr->right == NULL) {
        curr->right = toInsert;
        return;
      }
      // keep going right
      curr = curr->right;
    }
  }
}
/* newTreeNode
 * helper function, creates a new tree node with value d
 * returns the address of the new node
 */
TreeNode *newTreeNode(TreeData d) {
  TreeNode *toReturn = (TreeNode *)malloc(sizeof(TreeNode));
  toReturn->value = d;
  toReturn->left = NULL;
  toReturn->right = NULL;
  return toReturn;
}

/* insertR
 * inserts data item d into tree; note that this is a BST so it is ordered
 * note: this function is written recursively
 */
void insertR(TreeData d, TreeNode **tptr) {
  if (*tptr == NULL) {
    *tptr = newTreeNode(d);
  } else if (d < (*tptr)->value) {
    insertR(d, &(*tptr)->left);
  } else {
    insertR(d, &(*tptr)->right);
  }
}

/* createTree
 * creates a binary search tree with data stored in array a
 */
TreeNode *createTree(TreeData a[], int size) {
  if (size <= 0) {
    return NULL;
  }
  TreeNode *toReturn = newTreeNode(a[0]); // insert first item from list
  int i;
  for (i = 1; i < size; i++) {
    insert(a[i], &toReturn);
  }
  return toReturn;
}

/* size
 * returns the number of nodes in the tree
 */
int size(TreeNode *t) {
  if (t == NULL) {
    return 0;
  }
  return 1 + size(t->left) + size(t->right);
}