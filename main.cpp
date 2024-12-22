#include <iostream>
#include <filesystem>

using namespace std;
using namespace std::filesystem;

int main(int argc, char** argv) {
  auto directory_it = recursive_directory_iterator(current_path());

  for (const auto& file : directory_it)
    cout << file.path().filename() << endl;
}