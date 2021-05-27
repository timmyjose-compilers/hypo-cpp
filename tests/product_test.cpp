#include "vm.hpp"
#include <cassert>
#include <iostream>

int main() {
  vm::VM vm{"../samples/product.S"};
  vm.run();

  assert(vm.result() == 6);

  return 0;
}
