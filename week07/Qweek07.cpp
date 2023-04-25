#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root == NULL)
    return;
  traverseInOrder(root->left);
  cout << root->key << " ";
  traverseInOrder(root->right);
}

// Insert a node
struct node *insertNode(struct node *root, int key) {
  if (root == NULL) {
    struct node *newNode = new node;
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
  }

  if (key < root->key) {
    root->left = insertNode(root->left, key);
  } else if (key > root->key) {
    root->right = insertNode(root->right, key);
  }

  return root;
}
// Finding the node with the minimum value in a given BST
struct node *minValueNode(struct node *node) {
  struct node *current = node;

  // Loop down to find the leftmost leaf
  while (current->left != NULL)
    current = current->left;

  return current;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  //  Return NULL if the tree is empty
  if (root == NULL)
    return root;

  // Perform recursion for the left subtree if the key is smaller than the root's key
  if (key < root->key)
    root->left = deleteNode(root->left, key);

  // Perform recursion for the right subtree if the key is greater than the root's key
  else if (key > root->key)
    root->right = deleteNode(root->right, key);

  // Here is the node to be deleted if the key is same as root's key
  else {
    // Single child node or no child node
    if (root->left == NULL) {
      struct node *temp = root->right;
      delete root;
      return temp;
    }
    else if (root->right == NULL) {
      struct node *temp = root->left;
      delete root;
      return temp;
    }

    // Two children node
    struct node *temp = minValueNode(root->right);

    // Copy the data in inorder successor to this node
    root->key = temp->key;

    // Deleting the inorder successor
    root->right = deleteNode(root->right, temp->key);
  }

  // Unchanged node pointer is returned
  return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
  return 0;
} 
