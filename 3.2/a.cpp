#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>

int main() {
  std::string input;
  std::getline(std::cin, input);
  std::istringstream iss(input);

  std::unordered_set<int> numbers;
  /* Преимущества использования std::unordered_set:
  В большинстве случаев операции вставки и
  поиска будут быстрее, чем в std::set, особенно при больших объемах данных */
  int num;
  while (iss >> num) {
    if (numbers.contains(num)) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
      numbers.insert(num);
    }
  }
}