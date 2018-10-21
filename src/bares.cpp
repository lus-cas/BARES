#include "../include/bares.hpp"

//default contructor
Bares::Bares(){
}

//contructor
Bares::Bares(std::string expression_file_path){
	//input file stream variable to load the arithmetic expressions file
	std::ifstream expression_file;
	expression_file.open(expression_file_path);
	
	//avoids failures to open file
	if (!(expression_file.good() && expression_file.is_open())){
		std::cout << std::endl << "ERROR: failed to open file '" << expression_file_path << "'" << std::endl;
		std::cout << std::endl << "Aborting..." << std::endl;
		exit(-1);
	}

	//string variable to assume each line from file
	std::string line;

	while(std::getline(expression_file, line) && ! expression_file.fail()){
		//filling the arithmetic expressions vector from Bares class
		this->expressions.push_back(Bares::trim(line)); //prevents blank spaces and tabs
	}
}

//destructor
Bares::~Bares(){
	
}

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
std::ostream & operator<<(std::ostream &os, const Bares b){
	for(int i = 0; i < (int)(b.expressions.end() - b.expressions.begin()); i++){
		os << b.expressions[i] << "\n";
	}

	return os;
}