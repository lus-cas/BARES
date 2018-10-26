#include "../include/bares.h"

//getters and setters
std::vector<Token> const Bares::get_tokens(void){
	return this->tokens;
}

void Bares::set_tokens(std::vector<Token> tokens){
	this->tokens = tokens;
}

//general functions:
