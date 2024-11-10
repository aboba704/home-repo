#include <iostream>
#include <iterator>
#include <string>
#include <vector>

std::string Soundex(std::string);

int main() {
  std::string input;
  std::cin >> input;

  std::string output = Soundex(input);
  std::cout << output << "\n";
}

std::string Soundex(std::string in) {
  std::string out;
  out.push_back(in[0]);
  for (size_t i = 1; i != in.size(); ++i) {
    if (in[i] != 'a' && in[i] != 'e' && in[i] != 'h' && in[i] != 'i' &&
        in[i] != 'o' && in[i] != 'u' && in[i] != 'w' && in[i] != 'y') {
      switch (in[i]) {
        case 'b':
        case 'f':
        case 'p':
        case 'v':
          out.push_back('1');
          break;
        case 'c':
        case 'g':
        case 'j':
        case 'k':
        case 'q':
        case 's':
        case 'x':
        case 'z':
          out.push_back('2');
          break;
        case 'd':
        case 't':
          out.push_back('3');
          break;
        case 'l':
          out.push_back('4');
          break;
        case 'm':
        case 'n':
          out.push_back('5');
          break;
        case 'r':
          out.push_back('6');
          break;
        default:
          break;
      }
    }
  }
  for (std::string::iterator it = out.begin(); it != out.end();) {
    if (*it == *(it + 1))
      it = out.erase(it);
    else
      ++it;
  }
  out.resize(4, '0');
  return out;
}