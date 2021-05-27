#include "vm.hpp"
#include <cstdlib>
#include <iostream>

void usage() {
  std::cout << "Usage: hypo ASSEMBLY-FILE" << std::endl;
  std::exit(1);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    usage();
  }

  vm::VM vm{argv[1]};
  vm.run();
  std::cout << vm.result() << std::endl;

  return 0;
}
