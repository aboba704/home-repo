#include <algorithm>
#include <iostream>
#include <string>

// int main() {
//   std::string input;
//   std::getline(std::cin, input);

//   for (size_t i = 0; i < input.size(); i++) {
//     while (input[i] == ' ') {
//       input.erase(i, 1);
//     }
//   }

//   int pal = 1;
//   for (size_t i = 0; i < input.size() / 2; i++) {
//     if (input[i] != input[input.size() - i - 1]) pal = 0;
//   }

//   if (pal == 1)
//     std::cout << "YES\n";
//   else
//     std::cout << "NO\n";
// }

int main() {
  std::string s;
  std::getline(std::cin, s);

  std::erase(s, ' ');

  if (std::equal(s.begin(), s.begin() + s.size() / 2, s.rbegin()))
    std::cout << "YES\n";
  else
    std::cout << "NO\n";
}