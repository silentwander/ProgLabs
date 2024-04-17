#include "../lib/Dlist.hpp"
#include "../lib/array.hpp"

int main() {
  ifstream file;
  file.open("main.txt");
  if (!file.is_open()) {
    cout << "Failed to open file."
         << "\n";
    return 1;
  }

  string line;
  list *head = NULL, *tail = NULL;
  while (file >> line) {
    tail = push_back(tail, line);
    if (head == NULL) {
      head = tail;
    }
  }

  vector<int> vec, vec2;
  CreateArr(vec);
  CreateArr(vec2);
  list *current = head;
  while (current != NULL) {
    string word = current->line;
    char symbolFirst = toupper(word[0]);
    char symbolLast = toupper(word[word.length() - 1]);
    //    cout << symbolFirst << " " << static_cast<int>(symbolFirst) - 65 <<
    //    "\n";
    AddArr(vec, static_cast<int>(symbolFirst));
    //    cout << symbolLast << " " << static_cast<int>(symbolLast) - 65 <<
    //    "\n";
    AddArr(vec2, static_cast<int>(symbolLast));
    current = current->next;
  }
  int MaxEl = 0, index;
  MaxElement(vec, MaxEl, index);
  cout << "First letter:"
       << " " << static_cast<char>(index + 65) << " - " << MaxEl << "\n";

  MaxEl = 0;
  MaxElement(vec2, MaxEl, index);
  cout << "Last letter:"
       << " " << static_cast<char>(index + 65) << " - " << MaxEl << "\n";
  freeList(head);

  return 0;
}