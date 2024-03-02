#ifndef EXPRESSION_SOLVER_TOKEN_TYPE_HXX
#define EXPRESSION_SOLVER_TOKEN_TYPE_HXX

#include <map>
#include <string>

enum class token_type
{
    NUMBER_LITERAL,
    PLUS,
    MINUS,
    MUL,
    DIV,
    LPAREN,
    RPAREN,
    END
};

static const std::map<token_type, std::string> token_type_strings =
{
        {token_type::NUMBER_LITERAL, "INTEGER"},
        {token_type::PLUS, "PLUS"},
        {token_type::MINUS, "MINUS"},
        {token_type::MUL, "MUL"},
        {token_type::DIV, "DIV"},
        {token_type::LPAREN, "LPAREN"},
        {token_type::RPAREN, "RPAREN"},
        {token_type::END, "END"},
};


#endif //EXPRESSION_SOLVER_TOKEN_TYPE_HXX
