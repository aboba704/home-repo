#include <iostream>
#include <vector>

std::vector<std::vector<int>> Transpose(
    const std::vector<std::vector<int>>& matrix);

int main() {
  std::vector<std::vector<int>> matrix = {
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

  matrix = Transpose(matrix);

  for (auto& rows : matrix) {
    for (auto& elem : rows) std::cout << elem << " ";
    std::cout << "\n";
  }
}

std::vector<std::vector<int>> Transpose(
    const std::vector<std::vector<int>>& matrix) {
  const size_t m = matrix.size();
  const size_t n = matrix[0].size();

  std::vector<std::vector<int>> res(n, std::vector<int>(m));
  for (size_t i = 0; i != m; ++i) {
    for (size_t j = 0; j != n; ++j) res[j][i] = matrix[i][j];
  }
  return res;
}