#include "../include/bares.hpp"

using namespace std;

int main(void){
	string expression;
	
	cout << "Insert arithmetic expression: ";
	std::getline(std::cin, expression);

	cout << "\n *inserted string: " << expression <<endl;

	Bares Bares(expression);

	//cout << Bares.expression << endl;
	
	return 0;
}