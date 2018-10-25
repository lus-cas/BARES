#include <iostream>
#include <iomanip>
#include <vector>
#include "../include/parser.h"
#include "../include/bares.h"
/* std::vector<std::string> expressions = {
    "0",
    "4 + 1) * 8",
    "(4 + 1 % 8",
    "4 + 03",
    "10",
    "    12    +    4   8",
    "32767 - 32768 + 3",
    "5 + -32766",
    "5 + -32769",
    "12 + 3",
    "-3+-5+-6",
    "12 + 3     -3 + -34 ",
    "+12",
    "1.3 * 4",
    "a + 4",
    "       ",
    "  123 *  548",
    "4 + ",
    "32a23",
    "43 + 54 -   ",
    "1234567888889974232214433432 + 4"
}; */

// std::string parser_error_msg(const Parser::ResultType & result){
//     std::string error;

//     switch (result.type){
//         //1. Integer constant out of range beginning at column (n)!
//         case Parser::ResultType::INTEGER_OUT_OF_RANGE:
//             error = "Integer constant out of range beginning at column (" + std::to_string(result.at_col) + ")!";
//             break;

//         //2. Missing <term> at column (n)!    
//         case Parser::ResultType::MISSING_TERM:
//             error = "Missing <term> at column (" + std::to_string(result.at_col) + ")!";
//             break;

//         //3. Extraneous symbol after valid expression found at column (n)!
//         case Parser::ResultType::EXTRANEOUS_SYMBOL:
//             error = "Extraneous symbol after valid expression found at column (" + std::to_string(result.at_col) + ")!";
//             break;

//         //4. Ill formed integer at column (n)!
//         case Parser::ResultType::ILL_FORMED_INTEGER:
//             error = "Ill formed integer at column (" + std::to_string(result.at_col) + ")!";
//             break;

//         //5. Missing closing ”)” at column (n)!    
//         case Parser::ResultType::MISSING_CLOSING_SCOPE:
//             error = "Missing closing \")\" at column (" + std::to_string(result.at_col) + ")!";
//             break;

//         //6. Unexpected end of expression at column (n)!  
//         case Parser::ResultType::UNEXPECTED_END_OF_EXPRESSION:
//             error = "Unexpected end of expression at column (" + std::to_string(result.at_col) + ")!";
//             break;
    
//         default:
//             error = "Unhandled error found!";
//             break;
//     }

//     return error;
// }

int main(int argc, char const *argv[]){
    //Parser my_parser; // Instancia um parser.
    if(argc <= 2){
        std::cout << "\nERROR: missing file\n";
        std::cout << "\nAborting...\n" << std::endl;
        exit(-1);
    }

    Bares my_bares(argv[1], argv[2]);

    //to do: PEGAR DIRETAMENTE DO CONSTRUTOR PRA NÃO PRECISAR PERCORRER TODAS AS EXPRESSÕES DUAS VEZES
    // Tentar analisar cada expressão da lista.

    return EXIT_SUCCESS;
}