#include <iostream>

int main() {
  int month, year;
  std::cin >> month >> year;

  if (month == 2) {
    if (year % 400 == 0)
      std::cout << "29\n";
    else if (year % 100 == 0)
      std::cout << "28\n";
    else if (year % 4 == 0)
      std::cout << "29\n";
    else
      std::cout << "28\n";
  } else if (((month % 2 == 0) && (month < 8)) ||
             ((month % 2 == 1) && (month >= 8)))
    std::cout << "30\n";
  else
    std::cout << "31\n";
}