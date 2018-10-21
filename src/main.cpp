#include "../include/bares.hpp"

using namespace std;

int main(int argc, char const *argv[]){

	//to do: make it work using std::cin and std::cout

	if(argc <= 2){
		cout << endl << "ERROR: missing file" << endl;
		cout << endl << "Aborting..." << endl;
		exit(-1);
	}
	
	// if(argc <= 1){
	// 	throw std::runtime_error("No input file");
	// }

	Bares b(argv[0], argv[1]);
	//cout << b;
	
	return 0;
}