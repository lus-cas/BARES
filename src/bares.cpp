#include <iomanip>
#include "../include/parser.h"
#include "../include/evaluator.h"
#include "../include/file.h"

int main(int argc, char const *argv[]){  

    Parser parser;
    //Evaluator evaluator;

    std::string expression;
    std::vector<std::string> postfix;

    if(argc <= 2){

        std::vector<std::string> expressions;

        while(std::getline(std::cin, expression)){
            expressions.push_back(expression);
        }

        std::cout << std::endl;

        for(auto expression : expressions){
            auto result = parser.parse(expression);

            if(result.type != Parser::ResultType::OK){
                std::cout << parser.error_msg(result) << std::endl;

            }else{
                //postfix = evaluator.infix_to_postfix(parser.get_tokens());
                //postfix = parser.get_tokens();
            } 
            
        }

    }else{

        File file(argv[1], argv[2]);

        while(! file.is_eof()){
            expression = file.read_line();
            auto result = parser.parse(expression);

            if(result.type != Parser::ResultType::OK){
                file.write_line(parser.error_msg(result));

            }else{
                //postfix = evaluator.infix_to_postfix(parser.get_tokens());
                //postfix = parser.get_tokens();
            } 

        }

    }

    return EXIT_SUCCESS;
}