#ifndef EXPRESSION_SOLVER_AST_BIN_OP_HXX
#define EXPRESSION_SOLVER_AST_BIN_OP_HXX

#include "ast_node.hxx"


class ast_bin_op : public ast_node
{
private:
    std::shared_ptr<ast_node> m_left;
    token m_op;
    std::shared_ptr<ast_node> m_right;

public:
    ast_bin_op(std::shared_ptr<ast_node> left, token op, std::shared_ptr<ast_node> right);

    [[nodiscard]] auto get_left() const -> std::shared_ptr<ast_node>;
    [[nodiscard]] auto get_right() const -> std::shared_ptr<ast_node>;
    [[nodiscard]] auto get_op() const -> token;

};


#endif //EXPRESSION_SOLVER_AST_BIN_OP_HXX
