# Monty

The goal of this project is to create an interpreter for Monty ByteCodes files using the C language.  
The data structures in play are stacks and queues.

## The Monty language

Monty 0.98 is a scripting language that is first compiled into Monty byte code(Just like Python).  
It relies on a unique stack, with specific instructions to manipulate it.

### Monty byte code files

Files containing Monty byte codes usually have the `.m` extension.  
Most of the industry uses this standard but it is not required by the specification of the language:  
There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument.  
Monty byte code files can contain blank lines (empty or made of spaces only) and any additional text after the opcode or its required argument is not taken into account.  

## Getting started

The code is compiled using [GCC](https://gcc.gnu.org/) compiler, therefore you should have GCC installed in your system.  

To install GCC in your system:

```sh

$ sudo apt update && sudo apt upgrade -y
$ sudo apt install build-essential
$ sudo apt install manpages-dev

```

To validate that GCC compiler is successfully installed:

```sh

$ gcc --version

```

* Clone this repository on your local machine

```sh

$ git clone https://github.com/beingnile/monty

```

* Compile the code

```sh

$ gcc -Wall -Werror -Wextra -pedantic -std=c90 *.c -o monty

```

> Any output is printed on `stdout`
> Any error message is printed on `stderr`

### Usage

```sh

$ ./monty file

```

Where `file` is the path to the file containing Monty byte code.  

### Errors

* If the user does not give any file or more than one argument, the program prints:

```sh

$ USAGE: monty file

```

* If, for any reason, it's not possible to open the file, the program prints:

```sh

$ Error: Can't open file <file>

```

Where <file> is the name of the file

* If the file contains an invalid instruction, the program prints:

```sh

$ L<line_number>: unknown instruction <opcode>

```

Where is the line number where the instruction appears.
Line number always start at 1

* If memory allocation fails, the program prints:

```sh

$ Error: malloc failed

```

> All the errors forces the program to exit with status `EXIT_FAILURE`
