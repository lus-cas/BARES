
#ifndef EVALUATOR_H
#define EVALUATOR_H

#include <iostream>		// std::cin and std::cout
#include <string>		// std::string, std::to_string and std::stoi
#include <vector>		// std::vector
#include <algorithm>	// std::distance
#include <cmath>		// pow
#include <stack> 		// std::stack
#include <cassert>		// assert
#include "token.h"		// Token struct
#include "result.h"		// Result struct

/// Changes the expressions representation and solves them.
/*!
 * Converts an arithmetic expression in infix notation into postfix
 * representation. After the convertion is successfyly done, the
 * program evaluates the expression based on stacks and queues
 */

//=== alias
using value_t = long int;	//!< type to operate on
using symbol = std::string;	//!< symbol in this implementation is a string object

class Evaluator{
	private:
		//==== private members
		Result result; //!< the evaluating result for the current expression

	public:
		//==== special methods
        /// default constructor
		Evaluator(void) = default;
		/// turn off copy constructor
		Evaluator(const Evaluator &) = delete;
		/// default destructor
		~Evaluator(void) = default;

		//==== getters and setters
		Result get_result(void); // retrieves the Result type result

		//=== support methods.
		bool is_operator(Token);				// returns true if the parameter token is an operator
		bool is_operand(Token);					// returns true if the parameter token is an operand
		bool is_opening_scope(symbol);			// returns true if the parameter symbol is an opening scope
		bool is_closing_scope(symbol);			// returns true if the parameter symbol is a closing scope
		bool is_right_association(symbol);		// verifies if the operator has right association
		short get_precedence(symbol);			// returns the precedence of the symbol
		bool higher_precedence(symbol, symbol);	/* returns true if the the first operator has higher precedence
												than the second one. if both operators have the same precedence,
												returns false if the first operator has right association,
												or true otherwise */

		//==== converction methods
		std::vector<Token> infix_to_postfix(std::vector<Token>); // converts an infix expression (as Token list) into a postfix expression (as string list)
		value_t evaluate_postfix(std::vector<Token>);			 //	solves the postfix expression	

		//==== math methods
		value_t execute_operator(value_t, value_t, symbol); // returns the result of the operation between the two first parameters

};


#endif