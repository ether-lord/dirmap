#pragma once

#include <memory>
#include <string>
#include <vector>

class Directory {
 public:
  Directory();

  static const std::string& GetCurrent();

 private:
  static std::string m_current_wd;

  std::string m_name;
};