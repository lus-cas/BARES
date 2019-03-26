# Introduction

This is a **BARES (Basic ARithmetic Expression Evaluator based on Stacks)** programming project, that includes a recursive descending parser for **EBNF (Extended Backus-Naur Form)** grammar.

# Compile and Run

In order to generate a BARES executable at the "bin" dir, run:
> $ make

To run this project using input and output files:
> $ ./bin/bares <input_file> [output_file]

By using std::cin (input) and std::cout (output):
> $ ./bin/bares


# The Grammar

The EBNF grammar used in this project represents arithmetic expressions that supports scope definition and operations with integers (-32768 to 32767):

<ul>
	<li>Addition (+)</li>
	<li>Subtraction (-)</li>
	<li>Multiplication (*)</li>
	<li>Division (/)</li>
	<li>Power (^)</li>
	<li>Module (%)</li>
</ul>


This **EBNF** grammar is defined by the statements: 

    <expression>       :=   <term>, { ( "+" | "-" | "*" | "/" | "%" | "^" ), <term> };
    <term>             :=   "(", <expression>, ")" | <integer>;
    <integer>          :=   0 | [ "-" ], <natural_number>;
    <natural_number>   :=   <digit_excl_zero>, {<digit>};
    <digit_excl_zero>  :=   "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9";
    <digit>            :=   "0" | <digit_excl_zero>;


# Error Handling

Syntax and run-time errors are both supported by the program.

1. **Integer constant out of range beginning at column (n)!**
2. **Missing term at column (n)!**
3. **Extraneous symbol after valid expression found at column (n)!**
4. **Ill formed integer at column (n)!**
5. **Missing closing ”)” at column (n)!**
6. **Unexpected end of expression at column (n)!**
7. **Division by zero!**
8. **Numeric overflow error!**

# Testing and Issues

To test the BARES program, try to run the executable setting  "data/expressions" file as input and "data/solve" file as output.
> $ ./bin/bares data/expressions data/solve

It is known that this program treats the  ill formed integers that appears after a valid operator as a missing term.

# Authorship

Developed by [Lucas Miguel](https://github.com/luscasmm).
