#include "directory.h"

#include <unistd.h>
#include <memory>

using std::unique_ptr;

std::string Directory::m_current_wd = "";

Directory::Directory() {
}

const std::string& Directory::GetCurrent() {
  if (m_current_wd.empty()) {
    size_t buff_size = 1024;

    auto buffer = unique_ptr<char[]>(new char[buff_size]);
    getcwd(buffer.get(), buff_size);

    if (buffer != NULL)
      m_current_wd = buffer.get();
  }

  return m_current_wd;
}
