#include <iostream>

int main() {
  int n, k;
  std::cin >> n >> k;

  for (int i = 0; i < n - 1; i++) std::cout << "   ";
  int dayOfWeek = n;

  for (int i = 1; i <= k; i++) {
    if (i < 10) {
      std::cout << " ";
    }
    std::cout << i;

    if (dayOfWeek == 7) {
      std::cout << "\n";
      dayOfWeek = 1;
    } else {
      std::cout << " ";
      dayOfWeek++;
    }
  }
  std::cout << "\n";
}