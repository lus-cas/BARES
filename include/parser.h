#ifndef PARSER_H
#define PARSER_H

#include <iostream> // std::cout and std::cin
#include <iterator> // std::distance
#include <vector>   // std::vector
#include <sstream>  // std::istringstream
#include <cstddef>  // std::ptrdiff_t
#include <limits>   // std::numeric_limits
#include <algorithm>// std::copy
#include <cctype>   // std::isspace
#include "token.h"  // Token struct
#include "result.h" // Result struct

/// This class represents a parser that **validates** and **tokenizes** an expression.
/*!
 *
 * It implements a recursive descendent parser that validates expressions according to a
 * EBNF grammar. While validating an expression, it also tokenizes the input expression
 * into its components, creating a list of tokens as an output.
 *
 * The EBNF grammar is:
 * ```
 *  <expression>       :=   <term>, { ( "+" | "-" | "*" | "/" | "%" | "^" ), <term> };
 *  <term>             :=   "(", <expression>, ")" | <integer>;
 *  <integer>          :=   0 | [ "-" ], <natural_number>;
 *  <natural_number>   :=   <digit_excl_zero>, {<digit>};
 *  <digit_excl_zero>  :=   "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9";
 *  <digit>            :=   "0" | <digit_excl_zero>;
 * ```
 */

class Parser{
    public:
        //==== special methods
        /// default constructor
        Parser(void) = default;
        /// turn off copy constructor
        Parser(const Parser &) = delete;
        /// default destructor
        ~Parser(void) = default;
        /// turn off assignment operator.
        Parser &operator=(const Parser &) = delete;

        //==== alias
        typedef short int required_t;   //!< it's required to use the short int type
        typedef long long int input_t;  //!< in order to read any number input, the integer input type must be larger than the requided one
        
        //==== parsing methods
        Result parse(std::string);  // parses a expression validating its grammar

        //==== getters and setters
        std::vector<Token> const get_tokens(void); // returns the token list from the parsing

    private:
        /// terminal symbols table
        enum class terminal_symbol_t{ // the symbols:-
            TS_ADD,             //!< "+"
            TS_SUB,             //!< "-"
            TS_MULT,            //!< "*"
            TS_DIV,             //!< "/"
            TS_POW,             //!< "^"
            TS_MOD,             //!< "%"
            TS_OS,              //!< "("
            TS_CS,              //!< ")"
            TS_ZERO,            //!< "0"
            TS_NON_ZERO_DIGIT,  //!< digits from "1" to "9"
            TS_WS,              //!< white space
            TS_TAB,             //!< tab
            TS_EOS,             //!< "End Of String"
            TS_INVALID          //!< invalid token
        };

         //==== private members
        std::string expr;                       //!< the source expression to be parsed
        std::string::iterator current_symbol;   //!< pointer to the current char inside the expression
        std::vector<Token> tokens;              //!< resulting list of tokens extracted from the expression
        Result result;                          //!< the result for the current expression (either error of OK).

        //==== support methods
        terminal_symbol_t const lexer(char);    // get the corresponding code for a given input char
        void next_symbol(void);                 // advances the iterator to the next char in the expression
        bool accept(terminal_symbol_t);         // verifies if the given parameter corresponds to the current char
        void skip_bs(void);                     // skips blank spaces: white spaces and tabs
        bool const end_input(void);             // returns true if the end of the input is reached

        //=== NTS methods
        bool expression();
        bool term();
        bool integer();
        bool natural_number();
        bool digit_excl_zero();
        bool digit();

};
#endif