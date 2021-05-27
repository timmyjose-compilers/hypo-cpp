#include "vm.hpp"
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>

namespace vm {

void VM::load_source_file(std::string &filename) {
  int start_addr = 0;
  std::ifstream input(filename, std::ios::binary);

  if (input.is_open()) {
    std::string line;
    while (std::getline(input, line)) {
      if (line[0] == ';' || line.size() == 0) {
        continue;
      }

      size_t start{};
      size_t end = 0;

      Word opcode = Opcodes::Invalid;
      Word operand;
      const char delim = ' ';
      while ((start = line.find_first_not_of(delim, end)) !=
             std::string::npos) {
        end = line.find(delim, start);
        std::string token = line.substr(start, end - start);

        if (token == "STORE") {
          opcode = Opcodes::Store;
        } else if (token == "LOAD") {
          opcode = Opcodes::Load;
        } else if (token == "LOADL") {
          opcode = Opcodes::Loadl;
        } else if (token == "ADD") {
          opcode = Opcodes::Add;
        } else if (token == "JUMP") {
          opcode = Opcodes::Jump;
        } else if (token == "JUMPZ") {
          opcode = Opcodes::Jumpz;
        } else if (token == "HALT") {
          opcode = Opcodes::Halt;
        } else {
          operand = std::stoi(token);
        }
      }

      if (opcode != Opcodes::Invalid) {
        if (opcode == Opcodes::Halt) {
          code[start_addr] = Instruction{opcode, 0};
        } else {
          code[start_addr] = Instruction{opcode, operand};
        }
        start_addr++;
      }
    }
    input.close();
  } else {
    std::cerr << "Could not open file" << std::endl;
  }
}

void VM::run() {
  status = Statuses::Running;
  pc = 0;

  while (status == Statuses::Running) {
    Instruction instruction = code[pc];

    switch (instruction.opcode) {
    case Opcodes::Store:
      data[instruction.operand] = acc;
      pc++;
      break;

    case Opcodes::Load:
      acc = data[instruction.operand];
      pc++;
      break;

    case Opcodes::Loadl:
      acc = instruction.operand;
      pc++;
      break;

    case Opcodes::Add:
      acc += data[instruction.operand];
      pc++;
      break;

    case Opcodes::Jump:
      pc = instruction.operand;
      break;

    case Opcodes::Jumpz:
      if (acc == 0) {
        pc = instruction.operand;
      } else {
        pc++;
      }
      break;

    case Opcodes::Halt:
      status = Statuses::Halted;
      break;

    default:
      status = Statuses::Error;
    }
  }
}

int VM::result() { return acc; }
} // namespace vm
