#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  size_t n;
  std::cin >> n;

  std::vector<std::pair<int, int>> points(n);
  for (size_t i = 0; i != n; ++i)
    std::cin >> points[i].first >> points[i].second;

  std::sort(points.begin(), points.end(), [](auto &a, auto &b) {
    return a.first * a.first + a.second * a.second <
           b.first * b.first + b.second * b.second;
  });

  for (auto &elem : points)
    std::cout << elem.first << " " << elem.second << "\n";
}