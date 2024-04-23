#include <fstream>
#include <iostream>
#include <string>

using namespace std;

typedef struct node {
  string line;
  struct node *next, *prev;
} list;

list *createNode(string line);
list *push_back(list *tail, string line);
void freeList(list *head);
