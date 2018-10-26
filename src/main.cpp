#include <iomanip>
#include "../include/parser.h"
#include "../include/bares.h"
#include "../include/file.h"

int main(int argc, char const *argv[]){

    if(argc <= 2){
        std::cout << "\nERROR: missing file\n";
        std::cout << "\nAborting...\n" << std::endl;
        exit(-1);
    }


    File file(argv[1], argv[2]);

    std::string expression;



    return EXIT_SUCCESS;
}