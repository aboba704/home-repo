#include <iostream>
#include <vector>

int main() {
  int n, i = 0, j = 0;
  std::cin >> n;
  std::vector<int> colors;
  colors.reserve(n);

  for (int k = 0; k < n; ++k) {
    std::cin >> colors[k];
    if (colors[k] >= colors[i])
      i = k;
    else if (colors[k] < colors[j])
      j = k;
  }

  std::cout << i + 1 << " " << j + 1 << "\n";
}