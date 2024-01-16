#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DLLNode {
  struct DLLNode *prev;
  struct DLLNode *next;
  char *value;
};
typedef struct DLLNode DLLNode;

typedef struct {
  DLLNode *head;
  DLLNode *tail;
} DLL;

void printNode(DLLNode *dll) {
  printf("NODE - value: %s", dll->value);
}

void printList(DLL *dll) {
  DLLNode *nodeptr = dll->head;
  while (nodeptr != NULL) {
    printNode(nodeptr);
    printf("\n");
    nodeptr = nodeptr->next;
  }
}

void shift(DLL *dll, char* value) {
  DLLNode *cur_head = dll->head;

  DLLNode *new_head = malloc(sizeof(DLLNode));
  new_head->value = value;
  new_head->next = cur_head;

  if (cur_head != NULL)
    cur_head->prev = new_head;
  
  dll->head = new_head;
}

void push(DLL *dll, char* value) {
  DLLNode *cur_tail = dll->tail;

  DLLNode *new_tail = malloc(sizeof(DLLNode));
  new_tail->prev = cur_tail;
  new_tail->value = value;

  if (cur_tail != NULL)
    cur_tail->next = new_tail;

  dll->tail = new_tail;
}

char *unshift(DLL *dll) {
  DLLNode *head = dll->head;
  DLLNode *second = head->next;
  dll->head = second;

  second->prev = NULL;
  char *head_val = head->value;
  free(head);
  return head_val;
}

char *pop(DLL *dll) {
  DLLNode *tail = dll->tail;
  DLLNode *penultimate = tail->prev;
  dll->tail = penultimate;

  penultimate->next = NULL;
  char *tail_val = tail->value;
  free(tail);
  return tail_val;
}

void freeList(DLL *dll) {
  DLLNode *node = dll->head;
  while (node != NULL) {
    DLLNode *tmp = node;
    node = node->next;
    free(tmp->value);
    free(tmp);
  }
}

const char *v0stack = "val 0";
const char *v1stack = "val 1";
const char *v2stack = "val 2";
const char *v3stack = "val 3";
const char *v4stack = "val 4";

int main(int argc, char** argv) {
  char* v0 = malloc(strlen(v0stack) + 1);
  strcpy(v0, v0stack);
  char* v1 = malloc(strlen(v1stack) + 1);
  strcpy(v1, v1stack);
  char* v2 = malloc(strlen(v2stack) + 1);
  strcpy(v2, v2stack);
  char* v3 = malloc(strlen(v3stack) + 1);
  strcpy(v3, v3stack);
  char* v4 = malloc(strlen(v4stack) + 1);
  strcpy(v4, v4stack);

  DLL * list = malloc(sizeof(DLL));
  DLLNode *node1 = malloc(sizeof(DLLNode));
  node1->value = v1;
  DLLNode *node2 = malloc(sizeof(DLLNode));
  node2->value = v2;
  node1->next = node2;
  node2->prev = node1;

  list->head = node1;
  list->tail = node2;

  push(list, v3);
  push(list, v4);
  shift(list, v0);
  printList(list);

  free(pop(list));
  free(unshift(list));
  printList(list);

  freeList(list);
}
