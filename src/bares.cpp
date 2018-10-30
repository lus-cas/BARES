#include <iomanip>
#include "../include/parser.h"
#include "../include/evaluator.h"
#include "../include/file.h"

int main(int argc, char const *argv[]){  

    Parser parser;
    Evaluator evaluator;

    std::string expression;
    std::vector<Token> postfix;

    if(argc == 1){

        std::vector<std::string> expressions;

        while(std::getline(std::cin, expression)){
            expressions.push_back(expression);
        }

        std::cout << std::endl;

        for(auto expression : expressions){
            auto parser_result = parser.parse(expression);

            //verifies if a parsing error ocurred
            if(parser_result.type != Result::OK){
                std::cout << parser_result.error_msg() << std::endl;

            }else{
                postfix = evaluator.infix_to_postfix(parser.get_tokens());
                auto final_result = evaluator.evaluate_postfix(postfix);
                auto evaluate_result = evaluator.get_result();

                //verifies if a evaluating error ocurred
                if(evaluate_result.type != Result::OK){
                    std::cout << evaluate_result.error_msg() << std::endl;

                }else{
                    std::cout << final_result << std::endl;

                }
            } 
            
        }

    }else if(argc == 3){

        File file(argv[1], argv[2]);

        while(!file.is_eof()){
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

    }else{
        std::cout << "\nERROR: no matching running type for the reported parameters\n";
        std::cout << "\nTry: $ ./bin/bares\n";
        std::cout << "\nOr: $ ./bin/bares <input_file> [output_file]\n";
        std::cout << "\nAborting...\n" << std::endl;
    }

    return EXIT_SUCCESS;
}