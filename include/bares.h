
#ifndef BARES_H
#define BARES_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack> 
#include <string>
#include <cassert>
#include <stdexcept> // std::runtime_error
#include "../include/parser.h"

using value_t = long int;
using symbol = char;

class Bares{
	private:
		std::vector<Token> tokens;
		value_t ctoi(char);

	public:
		//constructors and destructor
		Bares(void) = default;
		Bares(const Bares &) = delete;
		~Bares(void) = default;

		//general functions
		bool is_operator(symbol);
		bool is_operand(symbol);
		bool is_opening_scope(symbol);
		bool is_closing_scope(symbol);
		bool is_right_association(symbol);
		short get_precedence(symbol);
		bool higher_precedence(symbol, symbol);
		std::string infix_to_postfix(std::string);
		value_t evaluate_postfix(std::string);

		//math function
		value_t pow(value_t, value_t);
		value_t execute_operator(value_t, value_t, symbol);

		//getters and setters
		std::vector<Token> const get_tokens(void);
		void set_tokens(std::vector<Token>);

};


#endif