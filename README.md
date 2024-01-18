# Stacks, Queues - LIFO, FIFO:

# The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

## Tasks:
## Mendatory tasks:
| Task                         | File                                        | Description                                           |
| ---------------------------- | ------------------------------------------- | ----------------------------------------------------- |
| 0. push, pall                | [opcode_functs1.c](./opcode_functs1.c)      | push an element to the stack and print all the values |
| 1. pint                      | [opcode_functs1.c](./opcode_functs1.c)      | prints the value at the top of the stack              |
| 2. pop                       | [opcode_functs1.c](./opcode_functs1.c)      | removes the top element of the stack                  |
| 3. swap                      | [opcode_functs2.c](./opcode_functs2.c)      | swaps the top two elements of the stack               |
| 4. add                       | [operations_functs.c](./operations_functs.c)| adds the top two elements of the stack                |
| 5. nop                       | [opcode_functs2.c](./opcode_functs2.c)      | doesn't do anything                                   |

## Advenced tasks:
| Task                         | File                                               | Description                                                    |
| ---------------------------- | -------------------------------------------------- | -------------------------------------------------------------- |
| 6. sub                       | [operations_functs.c](./operations_functs.c)       | subtracts the top element of the stack                         |
| 7. div                       | [operations_functs.c](./operations_functs.c)       | divides the second top element of the stack                    |
| 8. mul                       | [operations_functs.c](./operations_functs.c)       | multiplies the second top element of the stack                 |
| 9. mod                       | [operations_functs.c](./operations_functs.c)       | computes the rest of the division of the second top element    |
| 10. comments                 | [get_function.c](./get_function.c)                 | treat the line startes with # as a comment (don’t do anything).|
| 11. pchar                    | [print_functs.c](./print_functs.c)                 | prints the char at the top of the stack, followed by a new line|
| 12. pstr                     | [print_functs.c](./print_functs.c)                 | prints the string starting at the top of the stack             |
| 13. rotl                     | [rotations_functs.c](./rotations_functs.c)         | rotates the stack to the top                                   |
| 14. rotr                     | [rotations_functs.c](./rotations_functs.c)         | rotates the stack to the bottom                                |


# Compilation & Output
The code will be compiled this command:
```
$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```
