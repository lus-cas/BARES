#include "../include/bares.hpp"

Bares::Bares(){
}

Bares::Bares(std::string expression_file_path){
	std::ifstream expression_file;
	expression_file.open(expression_file_path);
	
	if (!(expression_file.good() && expression_file.is_open())){
		std::cout << std::endl << "ERROR: fail to open file '" << expression_file_path << "'" << std::endl;
		std::cout << std::endl << "Aborting..." << std::endl;
		exit(-1);
	}

	std::string line;

	while(std::getline(expression_file, line) && ! expression_file.fail()){
		this->expressions.push_back(Bares::trim(line));
	}

	// for(int i = 0; i < (int)(this->expressions.end() - this->expressions.begin()); i++){
	// 	std::cout << this->expressions[i] << std::endl;
	// }
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