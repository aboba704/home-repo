#include <math.h>

#include <iostream>

int main() {
  int n;
  double res = 0;
  std::cin >> n;

  for (int i = 1; i < n + 1; i++) {
    res += (pow(-1.0, i + 1) / i);
  }
  std::cout << res << "\n";
}