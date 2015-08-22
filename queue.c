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

typedef struct queue {
  NODE *head;
  NODE *tail;
} QUEUE;

QUEUE create_queue(){
  QUEUE queue;
  queue.head = NULL;
  queue.tail = NULL;
  return queue;
}

// Test whether the queue is empty
int is_empty(QUEUE *pQueue){
  return !pQueue->head;
}

// Insert element
void push(QUEUE *pQueue, int val) {
  NODE* pNode = create_node(val);
  if (pQueue->tail) {
    pQueue->tail->next = pNode;
  }
  pQueue->tail = pNode;
  if (!pQueue->head) {
    pQueue->head = pQueue->tail;
  }
}

// read the next element and remove it from the queue
int pop(QUEUE *pQueue) {
  NODE* pNode = pQueue->head;
  pQueue->head = pQueue->head->next;
  int val = pNode->val;
  destroy_node(pNode);
  if (!pQueue->head) {
    pQueue->tail = NULL;
  }
  return val;
}

// read the next element but don't remove it from the queue
int front(QUEUE *pQueue) {
  return pQueue->head->val;
}

int main() {
  QUEUE queue = create_queue();
  push(&queue, 5);
  push(&queue, 10);
  push(&queue, 15);
  push(&queue, 20);
  printf("%d\n", pop(&queue)); // 5
  printf("%d\n", pop(&queue)); // 10
  printf("%d\n", front(&queue)); // 15; queue = [15, 20]
  push(&queue, 25);
  while(!is_empty(&queue)) {
    printf("%d ", pop(&queue)); // 15, 20, 25
  }

  printf("\n");
  push(&queue, 55);
  push(&queue, 70);

  while(!is_empty(&queue)) {
    printf("%d ", pop(&queue)); // 55, 70
  }

  printf("\n");
  return 0;
}
