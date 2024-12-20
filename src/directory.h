#pragma once

#include <string>

class Directory {
 public:
  Directory();

  static const std::string& GetCurrent();

 private:
  static std::string current_wd_;

  std::string name_;
};