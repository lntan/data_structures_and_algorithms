#include <stdlib.h>
#include <stdio.h>

struct node {
  int data;
  struct node* next;
};

typedef struct node node_t;

void print_list(node_t* node) {
  while(node) {
    printf("%d ", node->data);
    node = node->next;
  }
}

void push(node_t** node_ref, int data) {
  node_t* new_node = malloc(sizeof(node_t));
  new_node->data = data;
  new_node->next = *node_ref;
  *node_ref = new_node;
}


void merge_sort(node_t** head_ref);
void split(node_t*, node_t**, node_t**);
void merge(node_t**, node_t*, node_t*);

int main() {
  node_t *head = NULL;

  push(&head, 10);
  push(&head, 15);
  push(&head, 23);
  push(&head, 2);
  push(&head, 27);
  push(&head, 20);
  push(&head, 15);
  push(&head, 8);

  print_list(head);
  merge_sort(&head);
  printf("\n");
  print_list(head);


  printf("\n");
  return 0;
}

void merge_sort(node_t** head_ref) {
  node_t* head = *head_ref;
  if(!head || !head->next) return;
  node_t* a;
  node_t* b;
  split(head, &a, &b);
  merge_sort(&a);
  merge_sort(&b);
  merge(head_ref, a, b);
}

void split(node_t* source, node_t** first_ref, node_t** second_ref) {
  node_t* head_a = NULL;
  node_t* head_b = NULL;
  node_t* current = source;
  int i = 0;
  while(current) {
    node_t* next = current->next;
    current->next = NULL;
    node_t** head_ref = (i%2 == 0) ? &head_a : &head_b;
    if(*head_ref) current->next = *head_ref;
    *head_ref = current;
    current = next;
    i++;
  }
  *first_ref = head_a;
  *second_ref = head_b;
}

void merge(node_t** head_ref, node_t* head_a, node_t* head_b) {
  node_t* head = NULL;

  while(head_a && head_b) {
    if(head_a->data < head_b->data) {
      node_t* next = head_a->next;
      head_a->next = NULL;
      if (head) head_a->next = head;
      head = head_a;
      head_a = next;
    } else {
      node_t* next = head_b->next;
      head_b->next = NULL;
      if (head) head_b->next = head;
      head = head_b;
      head_b = next;
    }
  }

  while(head_b) {
    node_t* next = head_b->next;
    head_b->next = head;
    head = head_b;
    head_b = next;
  }

  while(head_a) {
    node_t* next = head_a->next;
    head_a->next = head;
    head = head_a;
    head_a = next;
  }

  node_t* previous = NULL;
  node_t* current = head;
  while(current) {
    node_t* next = current->next;
    current->next = previous;
    previous = current;
    current = next;
  }
  head = previous;
  *head_ref = head;
}

