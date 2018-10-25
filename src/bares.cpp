#include "../include/bares.h"

//contructor
Bares::Bares(std::string input_file_path, std::string output_file_path){
	//input file stream variable to load the arithmetic expressions file
	this->input_file.open(input_file_path);
	
	//avoids failures to open file
	if (!(this->input_file.good() && this->input_file.is_open())){
		std::cout << "\nERROR: failed to open input file '" << input_file_path << "'\n";
		std::cout << "\nAborting..." << std::endl;
		exit(-1);
	}

	this->output_file.open(output_file_path, std::ofstream::out | std::ofstream::app);

	if (!(this->output_file.good() && this->output_file.is_open())){
		std::cout << "\nERROR: failed to open output file '" << output_file_path << "'\n";
		std::cout << "\nAborting..." << std::endl;
		exit(-1);
	}

	//string variable to assume each line from file
	std::string line;

	while(std::getline(this->input_file, line) && ! this->input_file.fail()){
		//filling the arithmetic expressions vector from Bares class
		this->expressions.push_back(line); //prevents blank spaces and tabs
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


//general functions:

//output stream operator << overload
// std::ostream & operator<<(std::ostream &os, const Bares b){
// 	for(int i = 0; i < (int)(b.expressions.end() - b.expressions.begin()); i++){
// 		os << b.expressions[i] << "\n";
// 	}
// 	return os;
// }