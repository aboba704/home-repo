#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::string CommonPrefix(const std::vector<std::string> &words) {
  if (words.empty()) {
    return {};
  }

  size_t minLen = words[0].size();
  for (auto &word : words) {
    minLen = std::min(minLen, word.size());
  }

  for (size_t i = 0; i < minLen; ++i) {
    const char c = words[0][i];
    for (auto &word : words) {
      if (word[i] != c) {
        return word.substr(0, i);
      }
    }
  }
  return words[0].substr(0, minLen);
}