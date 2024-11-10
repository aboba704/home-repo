#include <iostream>
#include <set>
#include <unordered_map>

int main() {
  int m, n, count = 0;
  std::cin >> m >> n;

  std::unordered_map<std::string, int> freqs;

  for (size_t i = 0; i != m; ++i) {
    std::string word;
    std::cin >> word;
    for (size_t j = n; j != word.size(); ++j) {
      ++freqs[word.substr()]
    }
  }

  while (std::cin >> word) {
    freqs.insert(word);
    if (++count == m) break;
  }

  for (const auto& [word, freq] : freqs) {
    std::cout << word << " " << freq << "\n";
  }
}