#include "../include/bares.hpp"

using namespace std;

int main(int argc, char const *argv[]){

	if(argc <= 1){
		cout << endl << "ERROR: no input file" << endl;
		cout << endl << "Aborting..." << endl;
		exit(-1);
	}
	
	// if(argc <= 1){
	// 	throw std::runtime_error("No input file");
	// }

	Bares bares (argv[1]);
	
	return 0;
}