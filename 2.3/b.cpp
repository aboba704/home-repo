#include <iostream>

int main() {
  int a, b, c;
  std::cin >> a >> b >> c;

  if ((c * c == a * a + b * b) || (b * b == a * a + c * c) ||
      (a * a == b * b + c * c))
    std::cout << "YES\n";
  else if ((a > b + c) || (b > a + c) || (c > a + b))
    std::cout << "UNDEFINED\n";
  else
    std::cout << "NO\n";
}