#ifndef EXPRESSION_SOLVER_TOKEN_HXX
#define EXPRESSION_SOLVER_TOKEN_HXX

#include "token_type.hxx"

#include <iostream>
#include <format>

class token
{
private:
    std::string m_value;
    token_type m_type;

public:
    token();
    token(token_type type, std::string  value);

    [[nodiscard]] auto get_value() const  -> std::string;
    [[nodiscard]] auto get_type()  const  -> token_type;

    auto display() const -> void;
};

#endif //EXPRESSION_SOLVER_TOKEN_HXX