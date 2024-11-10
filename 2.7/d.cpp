#include <iostream>
#include <string>
#include <vector>

std::string Join(const std::vector<std::string>& tokens, char delimiter);

int main() {
  std::string str = Join({"What", "is", "your", "name?"}, '_');
  std::cout << str << "\n";
}

std::string Join(const std::vector<std::string>& tokens, char delimiter) {
  if (tokens.size() == 0) return {};
  if (tokens.size() == 1) return tokens[0];

  std::string str;
  for (size_t i = 0; i != tokens.size(); ++i) {
    if (i > 0) str += delimiter;
    str += tokens[i];
  }
  return str;
}