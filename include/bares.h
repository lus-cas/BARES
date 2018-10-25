#ifndef BARES_H
#define BARES_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "../include/parser.h"

using value_t = long int;
using symbol = char;

class Bares{
	private:
		std::ifstream input_file;
		std::ofstream output_file;
		std::vector<std::string> expressions;

	public:
		//constructors and destructor
		Bares(void) = default;
		Bares(std::string, std::string);
		~Bares(void);

		//getters and setters
		std::vector<std::string> get_expressions(void);
		void set_expressions(std::vector<std::string>);

		//general functions
		bool higher_precedence(char, char);
		std::string infix_to_postfix(std::string);

		//math function
		value_t pow(value_t, value_t);
		value_t execute_operator(value_t, value_t, symbol);

		//operators overload
		friend std::ostream & operator<<(std::ostream &os, const Bares b);

};


#endif