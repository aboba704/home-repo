#include <iostream>
#include <string>
#include <vector>

template <typename T>
void Print(const T& data, const std::string& delim) {
  bool first = true;
  for (auto& elem : data) {
    if (!first)
      std::cout << delim;
    else
      first = false;
    std::cout << elem;
  }
  std::cout << "\n";
}

int main() {
  std::vector<int> data = {1, 2, 3, 4};
  Print(data, ", ");  // 1, 2, 3, 4
}