#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<int> data = {1, 2, 3, 4, 5};
  for (int elem : data) std::cout << elem << " ";
  std::cout << "front: " << data.front() << " back: " << data.back() << "\n";

  std::vector<std::string> v3(3, "hello");
  for (std::string elem : v3) std::cout << elem << " ";
  std::cout << v3.size() << "\n";
}