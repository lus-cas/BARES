#include <iomanip>
#include "../include/parser.h"
#include "../include/evaluator.h"
#include "../include/file.h"

int main(int argc, char const *argv[]){  

    Parser parser;
    Evaluator evaluator;

    std::string expression;
    std::vector<Token> postfix;

    if(argc <= 2){

        std::vector<std::string> expressions;

        while(std::getline(std::cin, expression)){
            expressions.push_back(expression);
        }

        std::cout << std::endl;

        for(auto expression : expressions){
            auto result = parser.parse(expression);

            if(result.type != Result::OK){
                std::cout << result.error_msg() << std::endl;

            }else{
                //postfix = evaluator.infix_to_postfix(parser.get_tokens());
                //postfix = parser.get_tokens();
            } 
            
        }

    }else{

        File file(argv[1], argv[2]);

        while(! file.is_eof()){
            expression = file.read_line();
            auto parse_result = parser.parse(expression);

            //verifies if a parsing error ocurred
            if(parse_result.type != Result::OK){
                file.write_line(parse_result.error_msg());

            }else{

                postfix = evaluator.infix_to_postfix(parser.get_tokens());
                auto final_result = evaluator.evaluate_postfix(postfix);
                auto evaluate_result = evaluator.get_result();

                //verifies if a evaluating error ocurred
                if(evaluate_result.type != Result::OK){
                     file.write_line(evaluate_result.error_msg());

                }else{
                    file.write_line(std::to_string(final_result));

                }
                
            } 

        }

    }

    return EXIT_SUCCESS;
}