#include "directory.h"

#include <unistd.h>
#include <memory>

#include <filesystem>
namespace fs = std::filesystem;

using std::unique_ptr;

std::string Directory::m_current_wd = "";

Directory::Directory() {
}

const std::string& Directory::GetCurrent() {
  if (m_current_wd.empty())
    m_current_wd = fs::current_path();

  return m_current_wd;
}
