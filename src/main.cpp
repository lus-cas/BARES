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
    Parser parser;
    Bares bares;

    std::string expression;

    while(! file.is_eof()){
        expression = file.read_line();
        auto result = parser.parse(expression);

        if(result.type != Parser::ResultType::OK){
            file.write_line(parser.error_msg(result));

        }else{
            file.write_line(expression);
        } 

    }



    return EXIT_SUCCESS;
}

/*
int main()
{
    Parser my_parser; // Instancia um parser.
    // Tentar analisar cada expressão da lista.
    for( const auto & expr : expressions )
    {
        // Fazer o parsing desta expressão.
        auto result = my_parser.parse( expr );
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
*/