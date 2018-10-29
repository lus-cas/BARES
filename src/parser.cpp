#include "../include/parser.h"

//support methods

//converts the input character c into its corresponding terminal symbol code
Parser::terminal_symbol_t const Parser::lexer(char c){
	switch(c){
        case '+':	return terminal_symbol_t::TS_ADD;
        case '-':	return terminal_symbol_t::TS_SUB;
        case '*':	return terminal_symbol_t::TS_MULT;
        case '/':	return terminal_symbol_t::TS_DIV;
        case '^':	return terminal_symbol_t::TS_POW;
        case '%':	return terminal_symbol_t::TS_MOD;
       	case '(':	return terminal_symbol_t::TS_OS;
        case ')':	return terminal_symbol_t::TS_CS;
        case ' ':	return terminal_symbol_t::TS_WS;
        case   9:	return terminal_symbol_t::TS_TAB;
        case '0':	return terminal_symbol_t::TS_ZERO;
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':	return terminal_symbol_t::TS_NON_ZERO_DIGIT;
        case '\0':	return terminal_symbol_t::TS_EOS; // end of string: the $ terminal symbol
    }

    return terminal_symbol_t::TS_INVALID;
}

//advances current_symbol iterator to the next valid symbol for processing
void Parser::next_symbol(){
	this->current_symbol++;
}

bool Parser::accept(terminal_symbol_t c){
	if(!end_input() && lexer(*current_symbol) == c){
		next_symbol();
		return true;
	}

	return false;
}

//advances the current_symbol iterator through blank spaces - white spaces (ascii: 32) or tabs (ascii: 9) - untill reach a valid character or end of the input string
void Parser::skip_bs(void){
	while(!end_input() && std::isspace(*current_symbol)){
        next_symbol(); // consumir um caractere.
    }
}

//returns true if the processing reached the end of the input string
bool const Parser::end_input(void){
	return this->current_symbol == this->expr.end();
}

//methodos to evaluate the grammar

//<expression> := <term>, { ( "+" | "-" | "*" | "/" | "%" | "^" ), <term> };
bool Parser::expression(){
	term();
    
    while(this->result.type == Result::OK){
        skip_bs();

        //parses the operator
        if(accept(Parser::terminal_symbol_t::TS_ADD)){
           this->tokens.emplace_back(Token( "+", Token::token_t::OPERATOR));

        }else if(accept(Parser::terminal_symbol_t::TS_SUB)){
           this->tokens.emplace_back(Token( "-", Token::token_t::OPERATOR));

        }else if(accept(Parser::terminal_symbol_t::TS_MULT)){
           this->tokens.emplace_back(Token( "*", Token::token_t::OPERATOR));

        }else if(accept(Parser::terminal_symbol_t::TS_DIV)){
           this->tokens.emplace_back(Token( "/", Token::token_t::OPERATOR));

        }else if(accept(Parser::terminal_symbol_t::TS_POW)){
           this->tokens.emplace_back(Token( "^", Token::token_t::OPERATOR));

        }else if(accept(Parser::terminal_symbol_t::TS_MOD)){
           this->tokens.emplace_back(Token( "%", Token::token_t::OPERATOR));

        }else break;

        //verifies if there's a valid term after the operator
        if(!term() && this->result.type == Result::ILL_FORMED_INTEGER){
            this->result.type = Result::MISSING_TERM;
        }
    }

    return this->result.type == Result::OK;
}

//<term> := "(", <expression>, ")" | <integer>;
bool Parser::term(){
	skip_bs();

	auto token_begin = current_symbol;

	if(integer()){
		//stores the token value as string
		std::string token_string;
		std::copy(token_begin, current_symbol, std::back_inserter(token_string));

		input_t token;

        try{
            token = stoll(token_string);

        }catch(const std::invalid_argument & e){
            this->result.type = Result::ILL_FORMED_INTEGER;
            this->result.at_col = std::distance(this->expr.begin(), token_begin); 

            return false;

        }catch( const std::out_of_range & e ){
            this->result.type = Result::INTEGER_OUT_OF_RANGE;
            this->result.at_col = std::distance(this->expr.begin(), token_begin); 

            return false;

        }
        
        //verifies if the token value is in the required range
        if(token < std::numeric_limits<required_t>::min() || token > std::numeric_limits<required_t>::max()){
            this->result.type = Result::INTEGER_OUT_OF_RANGE;
            this->result.at_col = std::distance(this->expr.begin(), token_begin);

        }else{
            this->tokens.emplace_back(Token(token_string, Token::token_t::OPERAND));
            
        }
	}else if(accept(terminal_symbol_t::TS_OS)){
		this->tokens.emplace_back(Token( "(", Token::token_t::SCOPE));

		expression();

		if(accept(terminal_symbol_t::TS_CS)){
			this->tokens.emplace_back(Token( ")", Token::token_t::SCOPE));

		}else{
			this->result.type = Result::MISSING_CLOSING_SCOPE;
			this->result.at_col = std::distance(this->expr.begin(), current_symbol);

		}

	}else{
		this->result.type = Result::ILL_FORMED_INTEGER;
		this->result.at_col = std::distance(this->expr.begin(), this->current_symbol);
	}

	return this->result.type == Result::OK;
}

//<integer> := 0 | [ "-" ], <natural_number>;
bool Parser::integer(){
	if(accept(terminal_symbol_t::TS_ZERO)) return true;
    
    accept(terminal_symbol_t::TS_SUB);
    return natural_number();
}

//<natural_number> := <digit_excl_zero>, {<digit>};
bool Parser::natural_number(){
	if(!digit_excl_zero()) return false;

	while(digit());

	return true;
}

//<digit_excl_zero> := "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9";
bool Parser::digit_excl_zero(){
	return accept(terminal_symbol_t::TS_NON_ZERO_DIGIT);
}

//<digit> := "0" | <digit_excl_zero>;
bool Parser::digit(){
	if(!accept(terminal_symbol_t::TS_ZERO)){
        return digit_excl_zero();
    }
    return true;
}

//Parser main function
Result Parser::parse(std::string expr){
	this->expr = expr;
    this->current_symbol = this->expr.begin();
    this->result = Result(Result::OK);

    //std::cout << *current_symbol << std::endl;

    this->tokens.clear();

    skip_bs();

    //std::cout << *current_symbol << std::endl;

    if(end_input()){
        this->result =  Result(Result::UNEXPECTED_END_OF_EXPRESSION, std::distance(this->expr.begin(), this->current_symbol));
    
    }else{
        if(expression()){
            skip_bs();
            if(!end_input()){
                this->result.type = Result::EXTRANEOUS_SYMBOL;
                this->result.at_col = std::distance(this->expr.begin(), this->current_symbol);
            }
        }
    }
    return this->result;
}

//tokens getter
std::vector<Token> const Parser::get_tokens(void){
	return this->tokens;
}
