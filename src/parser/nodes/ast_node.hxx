#ifndef EXPRESSION_SOLVER_AST_NODE_HXX
#define EXPRESSION_SOLVER_AST_NODE_HXX

#include "../../lexer/token.hxx"

#include <memory>
#include <vector>

class ast_node
{
public:
    virtual ~ast_node();
};


#endif //EXPRESSION_SOLVER_AST_NODE_HXX
