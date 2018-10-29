#ifndef PARSER_H
#define PARSER_H

#include <iostream> // cout, cin
#include <iterator> // std::distance()
#include <vector>   // std::vector
#include <sstream>  // std::istringstream
#include <cstddef>  // std::ptrdiff_t
#include <limits>   // std::numeric_limits
#include <algorithm>// std::copy
#include <cctype>   // std::isspace()
#include "token.h"  // Token struct
#include "result.h" // Result struct

/*
used EBNF grammar:
    <expression>       :=   <term>, { ( "+" | "-" | "*" | "/" | "%" | "^" ), <term> };
    <term>             :=   "(", <expression>, ")" | <integer>;
    <integer>          :=   0 | [ "-" ], <natural_number>;
    <natural_number>   :=   <digit_excl_zero>, {<digit>};
    <digit_excl_zero>  :=   "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9";
    <digit>            :=   "0" | <digit_excl_zero>;
*/

class Parser{
    public:
        //constructors and destructor
        Parser(void) = default;
        Parser(const Parser &) = delete;
        ~Parser(void) = default;

        Parser &operator=(const Parser &) = delete; //turn off assignment operator.

        typedef short int required_t; //it's required to use the short int type
        typedef long long int input_t; //in order to read any number input, the integer input type must be larger than the requided one
        
        Result parse(std::string);

        //getter
        std::vector<Token> const get_tokens(void);

    private:
        // terminal symbols table
        enum class terminal_symbol_t{
            TS_ADD,             //"+"
            TS_SUB,             //"-"
            TS_MULT,            //"*"
            TS_DIV,             //"/"
            TS_POW,             //"^"
            TS_MOD,             //"%"
            TS_OS,              //"("
            TS_CS,              //")"
            TS_ZERO,            //"0"
            TS_NON_ZERO_DIGIT,  //digits from "1" to "9"
            TS_WS,              //white space
            TS_TAB,             //tab
            TS_EOS,             //"End Of String"
            TS_INVALID          //invalid token
        };

        std::string expr;
        std::string::iterator current_symbol;
        std::vector<Token> tokens;
        Result result;

        //support methods
        terminal_symbol_t const lexer(char);
        void next_symbol(void);
        bool accept(terminal_symbol_t);
        void skip_bs(void);
        bool const end_input(void);

        //methodos to evaluate the grammar
        bool expression();
        bool term();
        bool integer();
        bool natural_number();
        bool digit_excl_zero();
        bool digit();

};
#endif