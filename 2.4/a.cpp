#include <cctype>
#include <iostream>
#include <vector>

int main() {
  std::string password;
  int isDig = 0, isLow = 0, isUp = 0, isPun = 0;

  std::cin >> password;
  if (password.size() < 8 || password.size() > 14) {
    std::cout << "NO\n";
    return 0;
  }
  for (char elem : password) {
    if (elem < 33 || elem > 126) {
      std::cout << "NO\n";
      return 0;
    }
    if (islower(elem)) isLow = 1;
    if (isupper(elem)) isUp = 1;
    if (isdigit(elem)) isDig = 1;
    if (ispunct(elem)) isPun = 1;
  }
  if (isLow + isUp + isDig + isPun < 3) {
    std::cout << "NO\n";
    return 0;
  }
  std::cout << "YES\n";
}