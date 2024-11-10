#include <algorithm>
#include <iostream>
#include <vector>

template <typename InIter1, typename InIter2, typename OutIter>
OutIter SetDifference(InIter1 first1, InIter1 last1, InIter2 first2,
                      InIter2 last2, OutIter out) {
  while (first1 != last1) {
    while (first2 != last2) {
      if (*first1 != *first2) {
        std::copy(first1, last1, out);
      }
      first2++;
    }
    first1++;
  }
  return out;
}

int main() {
  const std::vector<int> v1 = {1, 1, 1, 2, 1, 3, 3, 4, 1};
  const std::vector<int> v2 = {1, 4};
  std::vector<int> diff;  // 2, 3, 3
  SetDifference(v1.begin(), v1.end(), v2.begin(), v2.end(),
                std::back_inserter(diff));
  for (auto &elem : diff) std::cout << elem << " ";
  std::cout << "\n";
}