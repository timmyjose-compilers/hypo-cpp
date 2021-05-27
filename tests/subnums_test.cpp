#include "vm.hpp"
#include <cassert>
#include <iostream>

int main() {
  vm::VM vm{"../samples/subnums.S"};
  vm.run();

  assert(vm.result() == -1);

  return 0;
}
