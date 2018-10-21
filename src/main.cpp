#include "../include/bares.hpp"

using namespace std;

int main(int argc, char const *argv[]){

	if(argc <= 1){
		cout << endl << "ERROR: no input file" << endl;
		cout << endl << "Aborting..." << endl;
		exit(-1);
	}
	
	Bares bares (argv[1]);
	
	return 0;
}