#include "array.hpp"

void CreateArr(vector<int> &vec) {
  for (int i = 65; i <= 90; i++)
    vec.push_back(0);
}

void AddArr(vector<int> &vec, int index) {
  if (index >= 65 && index <= 90)
    vec[index - 65]++;
}

void MaxElement(vector<int> vec, int &MaxEl, int &index) {
  for (size_t i = 0; i < vec.size(); i++) {
    if (MaxEl < vec[i]) {
      MaxEl = vec[i];
      index = i;
    }
  }
}