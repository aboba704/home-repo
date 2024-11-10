#include <iostream>
#include <vector>

template <typename Iter>
Iter Unique(Iter first, Iter last) {
  if (first == last) return last;
  Iter res = first;
  while (++first != last) {
    if (!(*res == *first) && ++res != first) {
      *res = std::move(*first);
    }
  }
  return ++res;
}

int main() {
  std::vector v = {1, 1, 1, 2, 1, 3, 3, 4, 1};  // 1, 2, 1, 3, 4, 1
  auto last = Unique(v.begin(), v.end());
  v.erase(last, v.end());
  for (auto &elem : v) std::cout << elem << " ";
  std::cout << "\n";
}