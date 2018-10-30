#include "../include/evaluator.h"

Result Evaluator::get_result(){
	return this->result;
}

bool Evaluator::is_operator(Token t){
	return t.type == Token::token_t::OPERATOR;
}

bool Evaluator::is_operand(Token t){
	return t.type == Token::token_t::OPERAND;
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

value_t Evaluator::execute_operator(value_t x, value_t y, symbol o){
	switch (o[0]){
		case '^':	return pow(x, y);
		case '*':	return x * y;
		case '/':	if(y == 0){
						this->result.type = Result::DIVISION_BY_ZERO;
						return -1;
					}
					return x / y;
		case '%':	if(y == 0){
						this->result.type = Result::DIVISION_BY_ZERO;
						return -1;
					}
					return x % y;
		case '+': 	return x + y;
		case '-': 	return x - y;
		default	: 	assert (false); return -1;
	}
}

//main functions

std::vector<Token> Evaluator::infix_to_postfix(std::vector<Token> infix){
	std::vector<Token> postfix; // output Token vector
	std::stack<Token> stack;	// auxiliar stack

	for(auto token : infix){
		if(is_operand(token)){						// if it's an operand, goes straight to output vector
			postfix.emplace_back(token);

		}else if(is_opening_scope(token.value)){	// if it's an opening scope, goes to the auxiliar stack
			stack.push(token);

		}else if(is_closing_scope(token.value)){	// if it's a closing scope, pushs the expressions terms to the output
			while(!is_opening_scope(stack.top().value)){
				postfix.emplace_back(stack.top());
				stack.pop();
			}
			stack.pop();

		}else if(is_operator(token)){				// if it's an operator, replace it
			while(!stack.empty() && higher_precedence(stack.top().value, token.value)){
				postfix.emplace_back(stack.top());
				stack.pop();
			}
			stack.push(token);

		}else{
		}
	}

	while(!stack.empty()){
		postfix.emplace_back(stack.top());
		stack.pop();
	}

	return postfix;
}

value_t Evaluator::evaluate_postfix(std::vector<Token> postfix){
	this->result = Result(Result::OK);	// defines the Result result as OK by default
	std::stack<value_t> stack;			// stores the results of the operations

	for(auto t : postfix){
		if(is_operand(t)){
			stack.push(std::stoi(t.value));

		}else if(is_operator(t)){
			auto y = stack.top();
			stack.pop();

			auto x = stack.top();
			stack.pop();

			auto result = execute_operator(x, y, t.value);

			if(result < -32768 || result > 32767){
				this->result.type = Result::NUMERIC_OVERFLOW;
				stack.push(-1);	
			}else{
				stack.push(result);	
			}
			
		}else{
			assert( false );
		}
	}

	return stack.top();
}