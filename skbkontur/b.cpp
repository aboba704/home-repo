#include <iostream>
#include <set>
#include <vector>

int main() {
  int n = 0;

  std::cin >> n;
  // std::vector<std::pair<int, int>> nails;
  std::set<std::pair<int, int>> nails;

  for (int i = 0; i < n; ++i) {
    int x, y;
    std::cin >> x >> y;
    nails.insert({x, y});
  }

  long long ans = 0;
  for (auto &[x1, y1] : nails) {
    for (auto &[x2, y2] : nails) {
      if (x1 != x2 && y1 != y2) {
        if (nails.count({x1, y2}) && nails.count({x2, y1})) {
          long long area = abs(x2 - x1) * abs(y2 - y1);
          ans = std::max(area, ans);
        }
      }
    }
  }
  std::cout << ans << "\n";
}