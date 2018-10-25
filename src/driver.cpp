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

void print_error_msg(const Parser::ResultType & result, std::string str){
    std::string error_indicator(str.size()+1, ' ');
    error_indicator[result.at_col] = '^';

    switch (result.type){
        case Parser::ResultType::UNEXPECTED_END_OF_EXPRESSION:
            std::cout << ">>> Unexpected end of input at column (" << result.at_col << ")!\n";
            break;
        case Parser::ResultType::ILL_FORMED_INTEGER:
            std::cout << ">>> Ill formed integer at column (" << result.at_col << ")!\n";
            break;
        case Parser::ResultType::MISSING_TERM:
            std::cout << ">>> Missing <term> at column (" << result.at_col << ")!\n";
            break;
        case Parser::ResultType::EXTRANEOUS_SYMBOL:
            std::cout << ">>> Extraneous symbol after valid expression found at column (" << result.at_col << ")!\n";
            break;
        case Parser::ResultType::INTEGER_OUT_OF_RANGE:
            std::cout << ">>> Integer constant out of range beginning at column (" << result.at_col << ")!\n";
            break;
        case Parser::ResultType::MISSING_CLOSING_SCOPE:
            std::cout << ">>> Missing closing \")\" at column (" << result.at_col << ")!\n";
            break;
        default:
            std::cout << ">>> Unhandled error found!\n";
            break;
    }
    std::cout << "\"" << str << "\"\n";
    std::cout << " " << error_indicator << std::endl;
}

int main(int argc, char const *argv[]){
    //Parser my_parser; // Instancia um parser.
    if(argc <= 2){
        std::cout << "\nERROR: missing file\n";
        std::cout << "\nAborting...\n" << std::endl;
        exit(-1);
    }

    Bares my_bares(argv[1], argv[2]);
    Parser my_parser;

    // Tentar analisar cada expressão da lista.
    for(const auto & expr : my_bares.get_expressions()){
        // Fazer o parsing desta expressão.
        auto result = my_parser.parse(expr);
        // Preparar cabeçalho da saida.
        std::cout << std::setfill('=') << std::setw(80) << "\n";
        std::cout << std::setfill(' ') << ">>> Parsing \"" << expr << "\"\n";
        // Se deu pau, imprimir a mensagem adequada.
        if ( result.type != Parser::ResultType::OK )
            print_error_msg( result, expr );    
        else
            std::cout << ">>> Expression SUCCESSFULLY parsed!\n";
         // Recuperar a lista de tokens.
        auto lista = my_parser.get_tokens();
        std::cout << ">>> Tokens: { ";
        std::copy( lista.begin(), lista.end(),
                std::ostream_iterator< Token >(std::cout, " ") );
        std::cout << "}\n";
        std::cout << std::endl;
    }
    std::cout << "\n>>> Normal exiting...\n";
    return EXIT_SUCCESS;
}