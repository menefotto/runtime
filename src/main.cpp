#include <exception>
#include <functional>
#include <iostream>
#include "fmt/printf.h"
#include "../include/utils.hpp"
#include "../include/task_pool.hpp"

int main() {
  task_pool<2> t;
  for (auto i = 0; i < 10; i++) {
    try {
      t.push([&, i] { fmt::print("hello  {}\n", i);});
    } catch (const std::exception &e) {
      fmt::print("caught: {}\n", e.what());
    }
  }

  fmt::print("Cpu num is: {}\n", core_count());
}
