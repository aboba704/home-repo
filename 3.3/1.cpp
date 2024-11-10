#include <iostream>
#include <vector>

template <typename Iter, typename Value>
int countl(Iter first, Iter last, const Value& value) {
  int counter = 0;
  while (first != last) {
    if (*first == value) counter++;
    first++;
  }

  return counter;
}

template <typename Iter, typename Value>
Iter findl(Iter first, Iter last, const Value& value) {
  while (first != last) {
    if (*first == value) return first;
    first++;
  }
  return last;
}

int main() {
  std::vector v = {1, 2, 1, 1, 5, 2};
  std::cout << countl(v.begin(), v.end(), 2) << "\n";
  if (auto iter = findl(v.begin(), v.end(), 4); iter != v.end())
    std::cout << *iter << "\n";
  else
    std::cout << "No such elem\n";
}