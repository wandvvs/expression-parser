#ifndef EXPRESSION_SOLVER_PARSER_HXX
#define EXPRESSION_SOLVER_PARSER_HXX

#include "nodes/ast_number.hxx"
#include "nodes/ast_bin_op.hxx"

class parser
{
private:
    std::vector<token>& m_tokens;
    size_t m_pos;
    token m_current_token;

    static auto error() -> void;

    auto advance() -> void;
    auto consume(token_type type) -> token;

    auto factor() -> std::shared_ptr<ast_node>;
    auto term() -> std::shared_ptr<ast_node>;
    auto expression() -> std::shared_ptr<ast_node>;

public:
    explicit parser(std::vector<token>& tokens);

    auto parse() -> std::shared_ptr<ast_node>;
    [[nodiscard]] auto evaluate(std::shared_ptr<ast_node> node) const -> int;
};


#endif //EXPRESSION_SOLVER_PARSER_HXX
