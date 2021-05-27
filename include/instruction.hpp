#pragma once

#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

#include <cstdint>

namespace vm {
  using Word = int16_t;

  struct Instruction {
    Word opcode;
    Word operand;

    Instruction() {}
    Instruction(const Word opcode, const Word operand): opcode(opcode), operand(operand) {}
  };
}

#endif
