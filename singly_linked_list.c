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

typedef struct list {
  NODE *head;
  NODE *tail;
} LIST;

LIST create_list(){
  LIST list;
  list.head = NULL;
  list.tail = NULL;
  return list;
}

void print_list(LIST *pList) {
  NODE* current = pList->head;
  while(current) {
    printf("%d ", current->val);
    current = current->next;
  }
}

void destroy_list(LIST *pList) {
  NODE* current = pList->head;
  while(current) {
    NODE* pRemoved = current;
    current = current->next;
    destroy_node(pRemoved);
  }
}

void push(LIST *pList, int val) {
  NODE* pNode = create_node(val);
  if (pList->tail) {
    pList->tail->next = pNode;
  }
  pList->tail = pNode;
  if (!pList->head) {
    pList->head = pList->tail;
  }
}

void unshift(LIST *pList, int val) {
  NODE* pNode = create_node(val);
  if (pList->head) {
    pNode->next = pList->head;
  }
  pList->head = pNode;
  if (!pList->tail) {
    pList->tail = pList->head;
  }
}

NODE* shift(LIST *pList) {
  if(!pList->head) {
    return NULL;
  }
  NODE* pNode = pList->head;
  pList->head = pList->head->next;
  return pNode;
}

NODE* pop(LIST *pList) {
  if(!pList->head) {
    return NULL;
  }

  NODE* pNode;
  if (pList->head == pList->tail) {
    pNode = pList->head;
    pList->head = NULL;
    pList->tail = NULL;
    return pNode;
  }

  NODE* pPrevious = pList->head;
  pNode = pPrevious->next;
  while(pNode != pList->tail) {
    pPrevious = pNode;
    pNode = pNode->next;
  }

  pList->tail = pPrevious;
  pList->tail->next = NULL;
  return pNode;
}

int delete_at(LIST *pList, int val) {
  NODE* pRemoved;
  while(pList->head && pList->head->val == val) {
    pRemoved = shift(pList);
    destroy_node(pRemoved);
  }

  if(!pList->head) {
    return 0;
  }

  NODE* pPrevious = pList->head;
  NODE* pNode = pPrevious->next;
  while(pNode) {
    if(pNode->val == val) {
      pRemoved = pNode;
      pPrevious->next = pNode->next;
      pNode = pPrevious->next;
      destroy_node(pRemoved);
    } else {
      pPrevious = pNode;
      pNode = pNode->next;
    }
  }
  return 0;
}

LIST select(LIST *pList, int val) {
  LIST list = create_list();
  NODE* pNode = pList->head;
  while(pNode) {
    if (pNode->val == val) {
      push(&list, pNode->val);
    }
    pNode = pNode->next;
  }

  return list;
}

int length(LIST *pList) {
  int count = 0;
  NODE* current = pList->head;
  while(current) {
    count++;
    current = current->next;
  }
  return count;
}


int max(LIST *pList) {
  if (pList->head == pList->tail) {
    return pList->head->val;
  }
  int max = pList->head->val;
  NODE* pNode = pList->head->next;
  while(pNode) {
    if (pNode->val > max) {
      max = pNode->val;
    }
    pNode = pNode->next;
  }
  return max;
}


int main() {
  LIST list = create_list();
  //push(&list, 7);
  //push(&list, 7);
  //push(&list, 8);
  push(&list, 7);

  print_list(&list);
  printf("length: %d", max(&list));
  printf("\n");


  LIST list_1 = select(&list, 8);

  //delete_at(&list, 7);

  // // unshift(&list, 1);
  // // unshift(&list, 2);
  // // unshift(&list, 3);

  // while(1) {
  //   NODE *pNode = shift(&list);
  //   if(!pNode) {
  //     break;
  //   }
  //   printf("%d ", pNode->val);
  // }

  // while(1) {
  //   NODE *pNode = pop(&list);
  //   if(!pNode) {
  //     break;
  //   }
  //   printf("%d ", pNode->val);
  // }

  print_list(&list_1);
  printf("\n");
  // shift(&list);
  // print_list(&list);
  // printf("\n");
  destroy_list(&list);
  destroy_list(&list_1);
  return 0;
}
