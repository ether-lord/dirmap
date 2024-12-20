#include <iostream>

#include "directory.h"

using namespace std;

int main(int argc, char** argv) {
  cout << Directory::GetCurrent() << endl;
}