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

  std::string cmd;
  std::list<std::string> buf, x_buf;
  bool shift = false;
  auto iter = text.begin(), shift_iter = text.begin();
  while (std::cin >> cmd) {
    if (cmd == "Down" && iter != text.end()) {
      if (shift) buf.push_back(*iter);
      iter++;
    } else if (cmd == "Up" && iter != text.begin()) {
      if (shift) buf.pop_back();
      iter--;
    } else if (cmd == "Ctrl+X") {
      if (iter == text.end()) continue;
      if (!shift) {
        buf.clear();
        buf.push_back(*iter);
        iter = text.erase(iter);
      } else {
        for (auto &elem : buf) x_buf.push_back(elem);
        buf.clear();
        text.erase(shift_iter, iter);
        shift = false;
      }
    } else if (cmd == "Ctrl+V") {
      if (!buf.empty()) {
        if (!shift)
          for (auto &elem : buf) text.insert(iter, elem);
        else {
          text.erase(shift_iter, iter);
          for (auto &elem : x_buf) text.insert(iter, elem);
          shift = false;
        }
      }
    } else if (cmd == "Shift") {
      shift_iter = iter;
      shift = true;
    }
  }

  for (const auto &elem : text) {
    std::cout << elem << "\n";
  }
}