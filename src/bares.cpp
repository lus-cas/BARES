#include <iomanip>
#include "../include/parser.h"
#include "../include/evaluator.h"
#include "../include/file.h"

int main(int argc, char const *argv[]){

    if(argc <= 2){
        std::cout << "\nERROR: missing file\n";
        std::cout << "\nAborting...\n" << std::endl;
        exit(-1);
    }

    File file(argv[1], argv[2]);
    Parser parser;
    Evaluator evaluator;

    std::string expression;
    std::vector<std::string> postfix;

    while(! file.is_eof()){
        expression = file.read_line();
        auto result = parser.parse(expression);

        if(result.type != Parser::ResultType::OK){
            file.write_line(parser.error_msg(result));

        }else{
            postfix = evaluator.infix_to_postfix(parser.get_tokens());
            //postfix = parser.get_tokens();
        } 

    }



    return EXIT_SUCCESS;
}