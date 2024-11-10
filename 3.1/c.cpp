#include <deque>
#include <iostream>
#include <string>

void MakeTrain() {
  std::deque<int> train;
  std::string cmd;
  size_t car;
  while (std::cin >> cmd >> car) {
    if (cmd == "+left") {
      train.push_front(car);
    } else if (cmd == "+right") {
      train.push_back(car);
    } else if (cmd == "-left") {
      car = std::min(car, train.size());
      train.erase(train.begin(), train.begin() + car);
    } else if (cmd == "-right") {
      car = std::min(car, train.size());
      train.erase(train.end() - car, train.end());
    }
    // if (cmd[0] == '+') {
    //   cmd = cmd.substr(1);
    //   if (cmd == "left")
    //     train.push_front(car);
    //   else if (cmd == "right")
    //     train.push_back(car);
    // } else if (cmd[0] == '-') {
    //   cmd = cmd.substr(1);
    //   if (cmd == "left") {
    //     for (int i = 0; i < car && train.size() != 0; ++i) train.pop_front();
    //   } else if (cmd == "right") {
    //     for (int i = 0; i < car && train.size() != 0; ++i) train.pop_back();
    //   }
    // }
  }

  for (auto &elem : train) std::cout << elem << " ";
  std::cout << "\n";
}

int main() { MakeTrain(); }