#Introduction

This is a **BARES (Basic ARithmetic Expression Evaluator based on Stacks)** programming project, which includes a **recursive descending parser** for an **EBNF (Extended Backus-Naur Form)** grammar.

#Compile and Run

In order to generate a BARES executable at the "bin" dir, run:
	> $. make

To run this project based on input and output files:
	> $. ./bin/bares <input_file> [output_file]

By using std::cin (input) and std::cout (output):
	> $. ./bin/bares


#The Grammar

The EBNF grammar used in this project represents arithmetic expressions that supports scope definition and the following operations with integers (-32768 to 32767):

	⋅⋅* Addition (+);
	⋅⋅* Subtraction (-);
	⋅⋅* Multiplication (\*);
	⋅⋅* Division (/);
	⋅⋅* Power (^); and
	⋅⋅* Module (%).

The **EBNF** grammar follows these statements: 

    <expression>       :=   <term>, { ( "+" | "-" | "*" | "/" | "%" | "^" ), <term> };
    <term>             :=   "(", <expression>, ")" | <integer>;
    <integer>          :=   0 | [ "-" ], <natural_number>;
    <natural_number>   :=   <digit_excl_zero>, {<digit>};
    <digit_excl_zero>  :=   "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9";
    <digit>            :=   "0" | <digit_excl_zero>;




#Authorship

Developed by Lucas Miguel (lus-cas@outlook.com) and Elyton Victor.