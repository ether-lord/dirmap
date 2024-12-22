#include <unistd.h>

#include <filesystem>
#include <iostream>

using namespace std;
using namespace std::filesystem;

int main(int argc, char** argv) {
  bool print_filesize = false;

  int rez = 0;
  while ((rez = getopt(argc, argv, "s")) != -1) {
    switch (rez) {
      case 's':
        print_filesize = true;
        break;
      default:
        break;
    }
  }

  auto directory_it = recursive_directory_iterator(current_path());
  for (const auto& entry : directory_it) {
    auto entry_str = entry.path().filename().string();

    if (print_filesize && entry.is_regular_file())
      entry_str.append("  --  ").append(to_string(entry.file_size())).append(" B");

    cout << entry_str << endl;
  }
}