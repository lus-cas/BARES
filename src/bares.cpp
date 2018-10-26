#include "../include/bares.h"

//getters and setters
std::vector<Token> const Bares::get_tokens(void){
	return this->tokens;
}

void Bares::set_tokens(std::vector<Token> tokens){
	this->tokens = tokens;
}

//general functions

bool Bares::is_operator(symbol s){
	return std::string("*^/%+-").find(s) != std::string::npos;
}

bool Bares::is_operand(symbol s){
	return s >= '0' && s <= '9';
}

bool Bares::is_opening_scope(symbol s){
	return s == '(';
}

bool Bares::is_closing_scope(symbol s){
	return s == ')';
}

bool Bares::is_right_association(symbol s){
	return s == '^';
}

short Bares::get_precedence(symbol s){
	switch(s){
        case '^' : return 3;
        case '*' :
        case '/' :
        case '%' : return 2;
        case '+' :
        case '-' : return 1;
        case '(' : return 0;
        default  : assert( false );  return -1;
    }
}

bool Bares::higher_precedence(symbol op1, symbol op2){
	int precedence_op1 = get_precedence(op1);
	int precedence_op2 = get_precedence(op2);

    if(precedence_op1 > precedence_op2){
    	return true;

	}else if(precedence_op1 < precedence_op2){
		return false;

	}else{
    	if(is_right_association(op1)) return false;
    	return true;
    	
    }
}
