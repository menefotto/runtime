#include <exception>
#include <functional>
#include <iostream>
#include "../include/task_pool.hpp"

int main() {
  task_pool<2> t;
  for (auto i = 0; i < 10; i++) {
    try {
      t.push([&, i] { std::cout << "hello " << i << std::endl; });
    } catch (const std::exception &e) {
      std::cout << "caught: " << e.what() << "\n";
    }
  }
}
