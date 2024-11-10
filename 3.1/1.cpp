#include <iostream>
#include <list>

int main() {
  std::list<int> l = {0, 10, 15, 20};

  auto iter = l.begin();
  ++iter;
  l.insert(iter, 5);  // вставляем на эту позицию элемент

  // Удаляем из списка чётные числа
  for (auto iter = l.begin(); iter != l.end();) {
    if (*iter % 2 == 0) {
      iter = l.erase(
          iter);  // возвращается итератор на элемент, следующий за удалённым
    } else {
      ++iter;
    }
  }

  for (auto &elem : l) std::cout << elem << " ";
  std::cout << "\n";
}