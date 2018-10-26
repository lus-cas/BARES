
#ifndef EVALUATOR_H
#define EVALUATOR_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack> 
#include <string>
#include <cassert>
#include <stdexcept> // std::runtime_error
#include "../include/token.h"

using value_t = long int;
using symbol = std::string;

class Evaluator{
	private:
		value_t ctoi(char);

	public:
		//constructors and destructor
		Evaluator(void) = default;
		Evaluator(const Evaluator &) = delete;
		~Evaluator(void) = default;

		//support functions
		bool is_operator(Token);
		bool is_operand(Token);
		bool is_opening_scope(symbol);
		bool is_closing_scope(symbol);
		bool is_right_association(symbol);
		short get_precedence(symbol);
		bool higher_precedence(symbol, symbol);

		//main functions
		std::vector<symbol> infix_to_postfix(std::vector<Token>);
		value_t evaluate_postfix(std::string);

		//math function
		value_t pow(value_t, value_t);
		value_t execute_operator(value_t, value_t, symbol);

};


#endif