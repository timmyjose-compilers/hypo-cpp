#pragma once

#ifndef VM_HPP
#define VM_HPP

#include "instruction.hpp"
#include <string>
#include <array>

namespace vm {
  const unsigned int SIZE = 4096;

  enum Opcodes {
    Store,
    Load,
    Loadl,
    Add,
    Jump,
    Jumpz,
    Halt,
    Invalid
  };

  enum Statuses {
    NotRunning,
    Running,
    Error,
    Halted
  };

  class VM {
    private:
      std::array<Word, SIZE> data {0};
      std::array<Instruction, SIZE> code;
      int pc;
      int acc;
      int status;

      void load_source_file(std::string &);

    public:
      VM(std::string filename): pc(0), acc(0), status(Statuses::NotRunning) { load_source_file(filename); }
      
      void run();
      int result();
  };
}

#endif
