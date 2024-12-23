#include <unistd.h>

#include <cmath>
#include <filesystem>
#include <iostream>

using namespace std;
using namespace std::filesystem;

struct HumanReadable {
  std::uintmax_t size{};

 private:
  friend std::ostream& operator<<(std::ostream& os, HumanReadable hr) {
    int o{};
    double mantissa = hr.size;
    for (; mantissa >= 1024.; mantissa /= 1024., ++o);
    os << std::ceil(mantissa * 10.) / 10. << "BKMGTPE"[o];
    return o ? os << "B (" << hr.size << ") bytes" : os;
  }
};

int main(int argc, char** argv) {
  bool print_filesize = false;
  bool print_total_size = false;
  bool print_filename = false;

  int rez = 0;
  while ((rez = getopt(argc, argv, "sSf")) != -1) {
    switch (rez) {
      case 's':
        print_filesize = true;
        break;
      case 'S':
        print_total_size = true;
        break;
      case 'f':
        print_filename = true;
        break;
      default:
        break;
    }
  }

  size_t total_files_size = 0;
  auto directory_it = recursive_directory_iterator(current_path());
  for (const auto& entry : directory_it) {
    if (print_filename) {
      auto entry_str = entry.path().filename().string();
      cout << entry_str;
      if (print_filesize && entry.is_regular_file())
        cout << ' ' << HumanReadable{entry.file_size()};
      cout << endl;
    }

    if (print_total_size && entry.is_regular_file())
      total_files_size += entry.file_size();
  }

  if (print_total_size)
    cout << "Total size: " << HumanReadable{total_files_size} << endl;
}