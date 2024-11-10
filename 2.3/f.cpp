#include <iostream>

int main() {
  int num, res = 0;

  std::cin >> num;
  while (num != 0) {
    res += num % 10;
    num /= 10;
  }
  std::cout << res << "\n";
}