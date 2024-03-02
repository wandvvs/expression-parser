//
// Created by wand on 02.03.2024.
//

#ifndef EXPRESSION_SOLVER_LEXER_HXX
#define EXPRESSION_SOLVER_LEXER_HXX

#include "token.hxx"

#include <vector>

class lexer
{
private:
    std::string m_input;
    size_t m_pos;
    char m_current;

    auto move_next() -> void;
    auto parse_digit() -> std::string;

public:
    explicit lexer(const std::string& input);

    auto tokenize() -> std::vector<token>;
};


#endif //EXPRESSION_SOLVER_LEXER_HXX
