#ifndef EXPRESSION_SOLVER_AST_NUMBER_HXX
#define EXPRESSION_SOLVER_AST_NUMBER_HXX

#include "ast_node.hxx"

class ast_number : public ast_node
{
private:
    token m_value;

public:
    explicit ast_number(token  value);

    auto get_value() -> token;
};


#endif //EXPRESSION_SOLVER_AST_NUMBER_HXX
