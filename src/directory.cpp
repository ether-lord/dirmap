#include "directory.h"

#include <unistd.h>
#include <memory>

using std::unique_ptr;

std::string Directory::current_wd_ = "";

Directory::Directory() {
}

const std::string& Directory::GetCurrent() {
  if (current_wd_.empty()) {
    size_t buff_size = 1024;

    auto buffer = unique_ptr<char>(new char[buff_size]);
    getcwd(buffer.get(), buff_size);

    if (buffer != NULL)
      current_wd_ = buffer.get();
  }

  return current_wd_;
}
