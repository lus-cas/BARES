#include "../include/bares.h"

using namespace std;

int main(int argc, char const *argv[]){

	//to do: make it work using std::cin and std::cout

	if(argc <= 2){
		cout << "\nERROR: missing file\n";
		cout << "\nAborting..." << endl;
		exit(-1);
	}

	Bares b(argv[1], argv[2]);
	//cout << b;
	
	return 0;
}