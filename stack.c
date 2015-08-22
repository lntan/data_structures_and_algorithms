#include <stdlib.h>
#include <stdio.h>

typedef struct node {
  int val;
  struct node *next;
} NODE;

NODE* create_node(int val) {
  NODE* pNode = malloc(sizeof(NODE));
  pNode->val = val;
  pNode->next = NULL;
  return pNode;
}

void destroy_node(NODE* pNode) {
  free(pNode);
}

typedef struct stack {
  NODE *head;
} STACK;

STACK create_stack(){
  STACK stack;
  stack.head = NULL;
  return stack;
}

// Test whether the stack is empty
int is_empty(STACK *pStack){
  return !pStack->head;
}

// Insert element on the top of the stack
void push(STACK *pStack, int val) {
  NODE* pNode = create_node(val);
  if (pStack->head) {
    pNode->next = pStack->head;
  }
  pStack->head = pNode;
}

// return the top element and remove it from the stack
int pop(STACK *pStack) {
  NODE* pNode = pStack->head;
  pStack->head = pStack->head->next;
  int val = pNode->val;
  destroy_node(pNode);
  return val;
}

// return the top element. The element is still in the stack
int top(STACK *pStack) {
  return pStack->head->val;
}

int main() {
  STACK stack = create_stack();
  push(&stack, 1);
  push(&stack, 2);
  push(&stack, 3);

  printf("%d\n", top(&stack)); // 3

  while(!is_empty(&stack)) { // 3 2 1
    int val = pop(&stack);
    printf("%d ", val);
  }

  printf("\n");
  return 0;
}
