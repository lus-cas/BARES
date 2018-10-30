
#ifndef EVALUATOR_H
#define EVALUATOR_H

#include <iostream>		//std::cin and std::cout
#include <string>		//std::string, std::to_string and std::stoi
#include <vector>		//std::vector
#include <algorithm>	//std::distance
#include <cmath>		//pow
#include <stack> 		//std::stack
#include <cassert>		//assert
#include "token.h"		//Token struct
#include "result.h"		//Result struct

/*!
 * Converts an arithmetic expression in infix notation into postfix
 * representation. After the convertion is successfyly done, the
 * program evaluates the expression based on stacks and queues.
 */

//=== alias
using value_t = long int;	//!< type to operate on.
using symbol = std::string;	//!< symbol in this implementation is a string object.

class Evaluator{
	private:
		 //==== private members.
		Result result; //!< the evaluating result for the current expression

	public:
		//constructors and destructor
		Evaluator(void) = default;
		Evaluator(const Evaluator &) = delete;
		~Evaluator(void) = default;

		//result getter
		Result get_result(void);

		//support functions
		bool is_operator(Token);
		bool is_operand(Token);
		bool is_opening_scope(symbol);
		bool is_closing_scope(symbol);
		bool is_right_association(symbol);
		short get_precedence(symbol);
		bool higher_precedence(symbol, symbol);

		//main functions
		std::vector<Token> infix_to_postfix(std::vector<Token>);
		value_t evaluate_postfix(std::vector<Token>);

		//math function
		value_t execute_operator(value_t, value_t, symbol);

};


#endif