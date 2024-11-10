#include <iostream>
#include <iterator>
#include <list>
#include <string>

int main() {
  int n;
  std::cin >> n;

  std::list<std::string> students;
  for (int i = 0; i < n; ++i) {
    std::string student, priority;
    std::cin >> student >> priority;
    if (priority == "top")
      students.push_front(student);
    else
      students.push_back(student);
  }

  int m;
  std::cin >> m;
  std::list<int> priorities;

  for (int i = 0; i < m; ++i) {
    int num;
    std::cin >> num;
    priorities.push_back(num);
  }

  for (int i = 0; i < m; ++i) {
    auto iter = students.begin();
    std::advance(iter, priorities.front() - 1);
    std::cout << *iter << "\n";
    priorities.pop_front();
  }
}