#include <iostream>
#include <vector>

int main() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> nums(n);
  for (int i = 0; i < n; ++i) std::cin >> nums[i];

  int l = 0, zeros = 0;
  long long sum = 0, res = 0;
  for (int r = 0; r < n; ++r) {
    sum += nums[r];
    zeros += nums[r] == 0;
    while (sum > k || zeros > 1) {
      zeros -= nums[l] == 0;
      sum -= nums[l++];
    }
    if (sum <= k && zeros < 2) res += r - l + 1;
  }

  // for (size_t i = 0; i < nums.size(); ++i) {
  //   auto iter = nums.begin() + i;
  //   int sum = 0;
  //   while (iter != nums.end() && sum + *iter <= k) {
  //     sum += *iter;
  //     ++iter;
  //     ++res;
  //   }
  // }

  std::cout << res << "\n";
}