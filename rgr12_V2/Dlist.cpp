#include "Dlist.hpp"

list *createNode(string line) {
  list *new_node = new list;
  if (new_node != NULL) {
    new_node->line = line;
    new_node->next = new_node->prev = NULL;
  }
  return new_node;
}

list *push_back(list *tail, string line) {
  list *new_node = createNode(line);
  if (tail == NULL) {
    tail = new_node;
  } else {
    new_node->prev = tail;
    tail->next = new_node;
    tail = new_node;
  }
  return tail;
}

void freeList(list *head) {
  while (head != NULL) {
    list *temp = head;
    head = head->next;
    delete temp;
  }
}
