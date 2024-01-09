#include <stdio.h>
#include <stdlib.h>

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
  DLLNode *nodeptr = &dll->head;
  int i = 0;
  while (nodeptr != NULL) {
    printNode(nodeptr);
    printf("\n");
    nodeptr = nodeptr->next;
    i++;
  }
}

// TODO
DLL *prependToList(DLL *dll, char* value) {
  DLLNode *head = dll->head;
  DLLNode *newHead = malloc(sizeof(DLLNode));
  newHead->value = value;
  newHead->next = head;
  if (head != NULL)
    head->prev = newHead;
  return newHead;
}

int appendToList(DLL *dll, char* value) {
  if (dll == NULL)
    return 1;

  DLLNode *lastptr = dll->tail;

  DLLNode *app_node = malloc(sizeof(DLLNode));
  app_node->next = NULL;
  app_node->prev = lastptr;
  app_node->value = value;

  lastptr->next = app_node;

  return 0;
}

void freeList(DLL *dll) {
  DLLNode *node = dll->head;
  while (node != NULL) {
    DLLNode *tmp = node;
    node = node->next;
    free(tmp);
  }
}

int main(int argc, char** argv) {
  DLLNode *node1 = malloc(sizeof(DLLNode));
  node1->value = "first value";
  DLLNode *node2 = malloc(sizeof(DLLNode));
  node2->value = "second value";
  node1->next = node2;
  node2->prev = node1;
  printList(node1);
  printf("appending\n");
  appendToList(node1, "third value");
  appendToList(node1, "fourth value");
  node1 = prependToList(node1, "zeroith value");
  printList(node1);
  freeList(node1);
}
