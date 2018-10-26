#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <iostream>

struct Token{
    enum class token_t : int{
        OPERAND,
        OPERATOR,
        SCOPE
    };

    std::string value;
    token_t type;

    /// Construtor default.
    // explicit Token( std::string value_="", token_t type_ = token_t::OPERAND )
    //     : value( value_ )
    //     , type( type_ )
    // {/* empty */}

    explicit Token(std::string value="", token_t type = token_t::OPERAND){
        this->value = value;
        this->type = type;
    }

    friend std::ostream & operator<<( std::ostream &os, const Token &t){
        std::string types[] = { "OPERAND", "OPERATOR", "SCOPE"};
        os << "<" << t.value << "," << types[(int)(t.type)] << ">";
        return os;
    }
};
#endif