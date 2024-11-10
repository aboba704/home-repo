#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
void Duplicate(std::vector<T>& v) {
  v.reserve(v.size() * 2);
  std::copy(v.begin(), v.end(), std::back_inserter(v));
}

int main() {
  std::vector<int> vec = {1, 2, 3};
  Duplicate(vec);
  for (auto& elem : vec) std::cout << elem << " ";
  std::cout << "\n";
}