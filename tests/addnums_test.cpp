#include "vm.hpp"
#include <cassert>
#include <iostream>

using vm::VM;

int main() {
  VM vm{"../samples/addnums.S"};
  vm.run();

  assert(vm.result() == 5);

  return 0;
}
