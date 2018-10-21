#ifndef BARES_HPP
#define BARES_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

class Bares{
	private:
		std::ifstream input_file;
		std::ofstream output_file;
		std::vector<std::string> expressions;

	public:
		//constructors and destructor
		Bares(void);
		Bares(std::string, std::string);
		~Bares(void);

		//getters and setters
		std::vector<std::string> get_expressions(void);
		void set_expressions(std::vector<std::string>);

		//general functions
		std::string trim(std::string);
		bool higher_precedence(char, char);
		std::string inflix_to_postfix(std::string);

		//operators overload
		friend std::ostream & operator<<(std::ostream &os, const Bares b);

};


#endif