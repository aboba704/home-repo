#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> Split(const std::string& str, char delimiter) {
  std::vector<std::string> res;

  size_t i = 0;
  for (size_t j = 0; j != str.size(); ++j) {
    if (str[j] == delimiter) {
      res.push_back(str.substr(i, j - i));
      i = j + 1;
    }
  }
  res.push_back(str.substr(i));

  return res;
}

int main() {
  std::string input = "What_is_your_name?";
  char del = '_';

  std::vector<std::string> res = Split(input, del);
  for (auto& sub : res) {
    std::cout << sub << "\n";
  }
}