#ifndef TOKEN_H
#define TOKEN_H

#include <string>   // std::string
#include <iostream> // std::ostream

/// Represents a token.
/*!
 * This struct represents a token, which is just a pair of information
 * `value/type` that identifies the content and its type.
 */

struct Token{
    enum class token_t : int{
        OPERAND,    //!< a type representing numbers
        OPERATOR,   //!< a type representing  "+", "-", "*", "/", "%" and "^" 
        SCOPE       //!< a type representing opening and closing scopes
    };

    std::string value;  //!< the token value as a string
    token_t type;       //!< the token type, which is either token_t::OPERAND, token_t::OPERATOR or token_t::SCOPE

    /// default constructor
    explicit Token(std::string value="", token_t type = token_t::OPERAND){
        this->value = value;
        this->type = type;
    }

    /// just to help us debug the code.
    friend std::ostream & operator<<( std::ostream &os, const Token &t){
        std::string types[] = { "OPERAND", "OPERATOR", "SCOPE"};
        os << "<" << t.value << "," << types[(int)(t.type)] << ">";
        return os;
    }
};
#endif