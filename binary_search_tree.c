#include <stdlib.h>
#include <stdio.h>

struct node
{
  int key;
  struct node* parent;
  struct node* left;
  struct node* right;
};

typedef struct node node_t;

void insert(node_t** node_ref, int key);
void traverse(node_t* node);
node_t* find(node_t* current_node, int key);
node_t* subtree_minimum(node_t* x);
node_t* successor(node_t *x);

int main() {
  node_t* root = NULL;
  insert(&root, 10);
  insert(&root, 15);
  insert(&root, 7);
  insert(&root, 12);
  insert(&root, 17);
  insert(&root, 14);
  insert(&root, 13);
  insert(&root, 6);
  insert(&root, 9);
  insert(&root, 11);
  traverse(root);
  /*
                        10
                      /    \
                     7      15
                    / \     / \
                   6   9   12  17
                          /  \
                        11   14
                            /
                          13
  */
  printf("\n");
  node_t* x = find(root, 15);
  node_t* y = subtree_minimum(x);
  printf("subtree_minimum: %d\n", y->key); // 11

  x = find(root, 12);
  y = successor(x);
  printf("successor: %d\n", y->key); // 13

  x = find(root, 11);
  y = successor(x);
  printf("successor: %d\n", y->key); // 12

  x = find(root, 14);
  y = successor(x);
  printf("successor: %d\n", y->key); // 15

  x = find(root, 17);
  y = successor(x); // NULL

  printf("\n");
  return 0;
}

node_t* successor(node_t *x) {
  if (x->right) {
    // if a tree has a right child, its successor is the minimum of the right child tree (in case of 12)
    return subtree_minimum(x->right);
  } else if (x->parent){
    // the tree does not have a right child
    node_t* parent = x->parent;
    if (parent->key > x->key) {
      // if the tree is a left child, its successor is its parent(in case of 11)
      return parent;
    } else {
      // if the tree is a right child
      // 1. If its parent is a left child, its successor is its grandparent (in case of 14)
      // 2. If its parent is a right child, it does not have a successor (in case of 17)
      if (parent->parent) {
        node_t* grand_parent = parent->parent;
        if (grand_parent->key > x->key) {
          return grand_parent;
        }
      }
    }
  }
  return NULL;
}

node_t* subtree_minimum(node_t* x) {
  while(x->left) {
    x = x->left;
  }
  return x;
}

void insert(node_t** node_ref, int key) {
  node_t* current = *node_ref;
  if (!current) {
    node_t* new_node = malloc(sizeof(node_t));
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->parent = NULL;
    *node_ref = new_node;
  } else if (current->key > key) {
    insert(&(current->left), key);
    if (!current->left->parent) {
      current->left->parent = current;
    }
  } else if (current->key < key) {
    insert(&(current->right), key);
    if (!current->right->parent) {
      current->right->parent = current;
    }
  }
}

void traverse(node_t* node) {
  printf("%d ", node->key);
  if (node->left) {
    traverse(node->left);
  }
  if (node->right) {
    traverse(node->right);
  }
}

node_t* find(node_t* current_node, int key) {
  if (!current_node) {
    return NULL;
  }
  if (current_node->key == key) {
    return current_node;
  } else if(key > current_node->key) {
    return find(current_node->right, key);
  } else if (key < current_node->key) {
    return find(current_node->left, key);
  }
  return NULL;
}




