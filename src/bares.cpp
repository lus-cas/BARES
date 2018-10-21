#include "../include/bares.hpp"

Bares::Bares(){
	this->expression = " ";
}

Bares::Bares(std::string expression){
	this->expression = Bares::trim(expression);
	std::cout << this->expression << std::endl;
}

Bares::~Bares(){
	
}

std::string Bares::trim(std::string str){
	std::string trim;

	for(unsigned int i = 0; i < str.length(); i++){
		if(! (str[i] == (char)32 || str[i] == (char)9)){
			trim += str[i];
		}
	}

	return trim;
}