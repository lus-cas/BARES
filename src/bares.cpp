#include "../include/bares.h"

//contructor
Bares::Bares(std::string input_file_path, std::string output_file_path){
	//input file stream variable to load the arithmetic expressions file
	this->input_file.open(input_file_path);
	
	//avoids failures to open file
	if (!(this->input_file.good() && this->input_file.is_open())){
		std::cout << "\nERROR: failed to open input file \"" << input_file_path << "\"\n";
		std::cout << "\nAborting..." << std::endl;
		exit(-1);
	}

	this->output_file.open(output_file_path, std::ofstream::out | std::ofstream::app);

	if (!(this->output_file.good() && this->output_file.is_open())){
		std::cout << "\nERROR: failed to open output file \"" << output_file_path << "\"\n";
		std::cout << "\nAborting..." << std::endl;
		exit(-1);
	}

	//string variable to assume each line from file
	std::string line;

	//creates a Parser object
	Parser parser;

	while(std::getline(this->input_file, line) && ! this->input_file.fail()){
		//filling the arithmetic expressions vector from Bares class
		//this->expressions.push_back(line);

		auto result = parser.parse(line);

		if(result.type != Parser::ResultType::OK){
			write(parser_error_msg(result));

		}else{
			this->tokens = parser.get_tokens();
		}

	}
}

//destructor
Bares::~Bares(){
	if (this->input_file.is_open()) this->input_file.close();
	if (this->output_file.is_open()) this->output_file.close();
}

//getters and setters
std::vector<std::string> Bares::get_expressions(void){
	return this->expressions;
}

void Bares::set_expressions(std::vector<std::string> expressions){
	this->expressions = expressions;
}

std::vector<Token> const Bares::get_tokens(void){
	return this->tokens;
}

void Bares::set_tokens(std::vector<Token> tokens){
	this->tokens = tokens;
}

//output

//converts parsing errors messages into string
std::string Bares::parser_error_msg(const Parser::ResultType & result){
    std::string error;

    switch (result.type){
        //1. Integer constant out of range beginning at column (n)!
        case Parser::ResultType::INTEGER_OUT_OF_RANGE:
            error = "Integer constant out of range beginning at column (" + std::to_string(result.at_col) + ")!";
            break;

        //2. Missing <term> at column (n)!    
        case Parser::ResultType::MISSING_TERM:
            error = "Missing <term> at column (" + std::to_string(result.at_col) + ")!";
            break;

        //3. Extraneous symbol after valid expression found at column (n)!
        case Parser::ResultType::EXTRANEOUS_SYMBOL:
            error = "Extraneous symbol after valid expression found at column (" + std::to_string(result.at_col) + ")!";
            break;

        //4. Ill formed integer at column (n)!
        case Parser::ResultType::ILL_FORMED_INTEGER:
            error = "Ill formed integer at column (" + std::to_string(result.at_col) + ")!";
            break;

        //5. Missing closing ”)” at column (n)!    
        case Parser::ResultType::MISSING_CLOSING_SCOPE:
            error = "Missing closing \")\" at column (" + std::to_string(result.at_col) + ")!";
            break;

        //6. Unexpected end of expression at column (n)!  
        case Parser::ResultType::UNEXPECTED_END_OF_EXPRESSION:
            error = "Unexpected end of expression at column (" + std::to_string(result.at_col) + ")!";
            break;

    	//Unknow parsing error
        default:
            error = "Unhandled error found!";
            break;
    }

    return error;
}

//tris to save a string on output file
void Bares::write(std::string output){
	try{
		output_file << output << "\n";
	}catch(int & e){
		std::cout << "\nERROR: could not save data on output file\n";
		std::cout << "\nAborting..." << std::endl;
		exit(-1);
	}
}


//general functions:
