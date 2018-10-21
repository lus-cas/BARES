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
		std::string expression;

	public:
		//contruroes e destrutor
		Bares(void);
		Bares(std::string);
		~Bares(void);

		//funções gerais
		std::string trim(std::string);

		//sobrecarga
		friend std::ostream & operator<<(std::ostream &os, const Bares b);
};


#endif