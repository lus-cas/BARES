#ifndef RESULT_H
#define RESULT_H

#include <string>
#include <iostream>

struct Result{
    typedef std::ptrdiff_t posistion_t; //column location determination.

    //possible syntax errors.
    enum code_t{
            OK, //expression successfuly parsed.
            UNEXPECTED_END_OF_EXPRESSION,
            ILL_FORMED_INTEGER,
            MISSING_TERM,
            EXTRANEOUS_SYMBOL,
            INTEGER_OUT_OF_RANGE,
            MISSING_CLOSING_SCOPE,
            DIVISION_BY_ZERO,
            NUMERIC_OVERFLOW
    };

    code_t type;
    posistion_t at_col;

    //default constructor
    explicit Result(code_t type = OK, posistion_t at_col = 0){
        this->type = type;
        this->at_col = at_col;
    }

    std::string error_msg(){
        std::string error;

        switch (this->type){
            //1. Integer constant out of range beginning at column (n)!
            case Result::INTEGER_OUT_OF_RANGE:
                error = "Integer constant out of range beginning at column (" + std::to_string(this->at_col) + ")!";
                break;

            //2. Missing <term> at column (n)!    
            case Result::MISSING_TERM:
                error = "Missing <term> at column (" + std::to_string(this->at_col) + ")!";
                break;

            //3. Extraneous symbol after valid expression found at column (n)!
            case Result::EXTRANEOUS_SYMBOL:
                error = "Extraneous symbol after valid expression found at column (" + std::to_string(this->at_col) + ")!";
                break;

            //4. Ill formed integer at column (n)!
            case Result::ILL_FORMED_INTEGER:
                error = "Ill formed integer at column (" + std::to_string(this->at_col) + ")!";
                break;

            //5. Missing closing ”)” at column (n)!    
            case Result::MISSING_CLOSING_SCOPE:
                error = "Missing closing \")\" at column (" + std::to_string(this->at_col) + ")!";
                break;

            //6. Unexpected end of expression at column (n)!  
            case Result::UNEXPECTED_END_OF_EXPRESSION:
                error = "Unexpected end of expression at column (" + std::to_string(this->at_col) + ")!";
                break;

            //7. Division by zero!
            case Result::DIVISION_BY_ZERO:
                error = "Division by zero!";
                break;

            //8. Numeric overflow error!
            case Result::NUMERIC_OVERFLOW:
                error = "Numeric overflow error!";
                break;
        
            default:
                error = "Unhandled error found!";
                break;
        }

        return error;
    }
};

#endif