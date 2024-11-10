#include <iostream>
#include <vector>

std::pair<size_t, size_t> MatrixArgMax(
    const std::vector<std::vector<int>>& matrix);

int main() {
  int n, k;
  std::cin >> n >> k;

  std::vector<std::vector<int>> matrix(n, std::vector<int>(k));
  for (int i = 0; i != n; ++i) {
    for (int j = 0; j != k; ++j) {
      int val;
      std::cin >> val;
      matrix[i][j] = val;
    }
  }

  std::cout << MatrixArgMax(matrix).first << " " << MatrixArgMax(matrix).second
            << "\n";

  // for (auto& row : matrix) {
  //   for (auto& val : row) {
  //     std::cout << val << ' ';
  //   }
  //   std::cout << '\n';
  // }
}

std::pair<size_t, size_t> MatrixArgMax(
    const std::vector<std::vector<int>>& matrix) {
  std::pair<size_t, size_t> nm = {0, 0};
  int maxVal = matrix[0][0];

  for (size_t i = 0; i != matrix.size(); ++i) {
    for (size_t j = 0; j != matrix[i].size(); ++j) {
      if (matrix[i][j] > maxVal) {
        maxVal = matrix[i][j];
        nm = {i, j};
      }
    }
  }

  return nm;
}