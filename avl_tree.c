#include <stdlib.h>
#include <stdio.h>

typedef struct node {
  int key;
  int balance;
  struct node *left;
  struct node *right;
} NODE ;

NODE* create_node(int key) {
  NODE* pNode = malloc(sizeof(NODE));
  pNode->key = key;
  pNode->left = NULL;
  pNode->right = NULL;
  pNode->balance = 0;
  return pNode;
}

int insert(NODE** current_node_address, int key) {
  if(!*current_node_address) {
    *current_node_address = create_node(key);
    return 1;
  } else {
    NODE* current_node = *current_node_address;
    if (current_node->key > key) {
      if (insert(&(current_node->left), key)) {
        current_node->balance = current_node->balance - 1;
        if (current_node->balance == 0) {
          return 0;
        } else if (current_node->balance == -1) {
          return 1;
        } else if (current_node->balance < -1 ) {
          printf("LEFT %d\n", current_node->key);
          NODE* left_child = current_node->left;
          if (left_child->balance == - 1) {
            printf("LEFT LEFT %d\n", left_child->key);
            current_node->left = left_child->right;
            left_child->right = current_node;
            current_node->balance = 0;
            left_child->balance = 0;
            *current_node_address = left_child;
            return 0;

          } else if(left_child->balance == 1) {
            printf("LEFT RIGHT %d\n", left_child->key);
            NODE* right_child_child = left_child->right;

            left_child->right = right_child_child->left;
            right_child_child->left = left_child;
            current_node->left = right_child_child->right;
            right_child_child->right = current_node;

            if (right_child_child->balance == 1) {
              left_child->balance = -1;
              current_node->balance = 0;
            } else {
              left_child->balance = 0;
              current_node->balance = 1;
            }
            right_child_child->balance = 0;
            *current_node_address = right_child_child;
            return 0;
          }
        }
      }
    } else {
      if (insert(&(current_node->right), key)) {
        current_node->balance = current_node->balance + 1;
        if (current_node->balance == 0) {
          return 0;
        } else if (current_node->balance == 1) {
          return 1;
        } else if (current_node->balance > 1) {
          printf("RIGHT %d\n", current_node->key);
          NODE* right_child = current_node->right;
          if (right_child->balance == 1) {
            printf("RIGHT RIGHT %d\n", right_child->key);
            current_node->right = right_child->left;
            right_child->left = current_node;
            current_node->balance = 0;
            right_child->balance = 0;
            *current_node_address = right_child;
            return 0;

          } else {
            printf("RIGHT LEFT %d\n", right_child->key);
            NODE* left_child_child = right_child->left;
            right_child->left = left_child_child->right;
            current_node->right = left_child_child->left;
            left_child_child->right = right_child;
            left_child_child->left = current_node;

            if (left_child_child->balance == -1) {
              current_node->balance = 0;
              right_child->balance = 1;
            } else {
              right_child->balance = 0;
              current_node->balance = -1;
            }
            left_child_child->balance = 0;
            *current_node_address = left_child_child;
            return 0;
          }

          return 1;
        }
      }
    }
  }
  return 0;
}

NODE* find(NODE* current_node, int key) {
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

void traverse(NODE* current_node) {
  printf("key: %d,  balance: %d\n", current_node->key, current_node->balance);
  if (current_node->left) {
    traverse(current_node->left);
  }
  if (current_node->right) {
    traverse(current_node->right);
  }
}

int main() {

  NODE* root = NULL;
  int height;
  insert(&root, 9);
  insert(&root, 15);
  insert(&root, 4);
  insert(&root, 2);
  insert(&root, 6);
  insert(&root, 5);
  insert(&root, 20);
  insert(&root, 7);
  insert(&root, 10);
  insert(&root, 25);
  insert(&root, 11);
  traverse(root);
  NODE* found = find(root, 20);
  if(found) {
    printf("found: %d\n", found->key);
  } else {
    printf("Not found\n");
  }

  found = find(root, 100);
  if(found) {
    printf("found: %d\n", found->key);
  } else {
    printf("Not found\n");
  }
  printf("\n");
}
