#include <iostream>
#include <set>
#include <vector>

int main() {
  int n, ans = 0;
  std::cin >> n;
  std::vector<std::vector<int>> dice(n, std::vector<int>(6));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 6; ++j) {
      std::cin >> dice[i][j];
    }
  }

  std::set<int> unique_sums;
  unique_sums.insert(0);
  for (int i = 0; i < n; ++i) {
    std::set<int> new_sums;
    for (int sum : unique_sums) {
      for (int face : dice[i]) new_sums.insert(sum + face);
    }
    unique_sums = std::move(new_sums);
  }

  std::cout << unique_sums.size() << "\n";
}