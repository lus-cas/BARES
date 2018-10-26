#include "../include/evaluator.h"

// support functions
bool Evaluator::is_operator(Token t){
	return t.type ==  Token::token_t::OPERATOR;
}

bool Evaluator::is_operand(Token t){
	return t.type ==  Token::token_t::OPERAND;
}

bool Evaluator::is_opening_scope(symbol s){
	return s == "(";
}

bool Evaluator::is_closing_scope(symbol s){
	return s == ")";
}

bool Evaluator::is_right_association(symbol s){
	return s == "^";
}

short Evaluator::get_precedence(symbol s){
	switch(s[0]){
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

bool Evaluator::higher_precedence(symbol op1, symbol op2){
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

//main functions

value_t Evaluator::pow(value_t b, value_t e){
	if(e < 1) return 1;
	return b * pow(b, e-1);
}

value_t Evaluator::execute_operator(value_t x, value_t y, symbol o){
	switch (o[0]){
		case '^':	return pow(x, y);
		case '*':	return x * y;
		case '/':	if(y == 0) //Division by zero!
					return x / y;
		case '%':	if(y == 0) //Division by zero!
					return x % y;
		case '+': 	return x + y;
		case '-': 	return x - y;
		default	: 	assert (false); return -1;
	}
}

//converts an infix expression (as Token list) into a postfix expression (as string list)
std::vector<symbol> Evaluator::infix_to_postfix(std::vector<Token> infix){
	std::vector<symbol> postfix;
	std::stack<symbol> stack;

	for(auto token : infix){
		if(is_operand(token)){
			postfix.emplace_back(token.value);

		}else if(is_opening_scope(token.value)){
			stack.push(token.value);

		}else if(is_closing_scope(token.value)){
			while(!is_opening_scope(stack.top())){
				postfix.emplace_back(stack.top());
				stack.pop();
			}
			stack.pop();

		}else if(is_operator(token)){
			while(!stack.empty() && higher_precedence(stack.top(), token.value)){
				postfix.emplace_back(stack.top());
				stack.pop();
			}
			stack.push(token.value);

		}else{
		}
	}

	while(not stack.empty()){
		postfix.emplace_back(stack.top());
		stack.pop();
	}

	return postfix;
}