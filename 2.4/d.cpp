#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> input;

  std::string str;
  while (std::getline(std::cin, str)) {
    input.push_back(str);
  }

  std::sort(input.rbegin(), input.rend());

  for (std::string elem : input) std::cout << elem << "\n";
}