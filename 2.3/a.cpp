#include <iostream>

int main() {
  int x1, y1, x2, y2;
  std::cin >> x1 >> y1 >> x2 >> y2;

  if (x1 == x2 || y1 == y2 || abs(x2 - x1) == abs(y2 - y1))
    std::cout << "YES\n";
  else
    std::cout << "NO\n";
}