#ifndef UTILS
#define UTILS

#include <experimental/string_view>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include "fmt/printf.h"

std::size_t core_count() {
  std::string line;
  std::size_t count = 0;
  std::ifstream info("/proc/cpuinfo");

  for(std::string line; std::getline(info, line);){
    auto n = line.find("processor");
    if(n != std::string::npos){
      count++;
    }
  }

  info.close();

  return count;
}

#endif
