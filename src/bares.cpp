#include "../include/bares.hpp"

//default contructor
Bares::Bares(){

}

//contructor
Bares::Bares(std::string expression_file_path){
	//input file stream variable to load the arithmetic expressions file
	this->input_file.open(expression_file_path);
	
	//avoids failures to open file
	if (!(this->input_file.good() && this->input_file.is_open())){
		std::cout << std::endl << "ERROR: failed to open file '" << expression_file_path << "'" << std::endl;
		std::cout << std::endl << "Aborting..." << std::endl;
		exit(-1);
	}

	//string variable to assume each line from file
	std::string line;

	while(std::getline(this->input_file, line) && ! this->input_file.fail()){
		//filling the arithmetic expressions vector from Bares class
		this->expressions.push_back(Bares::trim(line)); //prevents blank spaces and tabs
	}
}

//destructor
Bares::~Bares(){
	// if (this->input_file.is_open()) this->input_file.close();
	// if (this->output_file.is_open()) this->output_file.close();
}

//getters and setters
std::vector<std::string> Bares::get_expressions(void){
	return this->expressions;
}

void Bares::set_expressions(std::vector<std::string> expressions){
	this->expressions = expressions;
}


//general functions:

//function to remove blank spaces and tabs from strings
std::string Bares::trim(std::string str){
	std::string trim;

	for(unsigned int i = 0; i < str.length(); i++){
		if(! (str[i] == (char)32 || str[i] == (char)9)){
			trim += str[i];
		}
	}

	return trim;
}

//output stream operator << overload
std::ostream & operator<<(std::ostream &os, const Bares &b){
	for(int i = 0; i < (int)(b.expressions.end() - b.expressions.begin()); i++){
		os << b.expressions[i] << "\n";
	}
	return os;
}