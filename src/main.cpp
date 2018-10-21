#include "../include/bares.hpp"

using namespace std;

int main(int argc, char const *argv[]){

	//to do: make it work using std::cin and std::cout

	if(argc <= 1){
		cout << endl << "ERROR: no input file" << endl;
		cout << endl << "Aborting..." << endl;
		exit(-1);
	}
	
	// if(argc <= 1){
	// 	throw std::runtime_error("No input file");
	// }

	Bares bares (argv[1]);

	std::string x = bares.get_expressions()[0];

	cout << x;
	
	return 0;
}