# The Calc Virtual Machine

This is the full specification of a simple virtual Machine, the Calc VM. The Hypo is a simple VM meant for edificational purposes - how simple iterative
interpreters work. 

The only operations supported are the four basic arithmetic operations - addition, subtraction, multiplication, and division along with the modulus operation.

Note that a word is 16-bits wide.

Hypo has two stores - the Data Store and the Code Store holding the actual data and the code respectively.


## Word Store

Hypo has a 4096-word data store. For processing results (intermediate and final), Hypo has a 1-word accumulator, ACC.


## Code Store

Hypo also has a 4096-word code store.

Each instruction is also 1-word long, of which the first 4 bits are the opcode, and the last 12 bits are the operand.

The PC (Program Counter) stores the address of the next instruction to be executed. Instruction addressing starts at 0.


## Instruction Set

```
Op-code  Instruction    Meaning

 0        STORE d     data[d] <- ACC
 1        LOAD  d     ACC <- data[d]
 2        LOADL d     ACC <- d
 3        ADD   d     ACC += data[d]
 4        JUMP  d     PC = d
 5        JUMPZ d     PC = d, iff ACC = 0
 6        HALT        stop program execution
```

where `data` refers to the Data Store.

