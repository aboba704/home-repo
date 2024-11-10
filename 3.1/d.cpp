#include <iostream>
#include <list>
#include <utility>

int main() {
  std::list<std::string> text;
  while (1) {
    std::string str;
    std::getline(std::cin, str);
    if (str.empty()) break;
    text.push_back(str);
  };

  std::string cmd, buf;
  auto iter = text.begin();
  while (std::cin >> cmd) {
    if (cmd == "Down" && iter != text.end()) {
      iter++;
    } else if (cmd == "Up" && iter != text.begin()) {
      iter--;
    } else if (cmd == "Ctrl+X") {
      if (iter == text.end()) continue;
      buf = *iter;
      iter = text.erase(iter);
    } else if (cmd == "Ctrl+V") {
      if (!buf.empty()) text.insert(iter, buf);
    }
  }

  for (const auto &elem : text) {
    std::cout << elem << "\n";
  }
}