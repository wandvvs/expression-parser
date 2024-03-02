#include "parser.hxx"

parser::parser(std::vector<token>& tokens)
    : m_tokens(tokens), m_pos(0), m_current_token(m_tokens.at(m_pos)) {}

auto parser::error() -> void { throw std::runtime_error("Invalid syntax."); }

auto parser::advance() -> void
{
    ++m_pos;

    if(m_pos < m_tokens.size() && m_current_token.get_type() != token_type::END)
    {
        m_current_token = m_tokens.at(m_pos);
    }
}

auto parser::consume(token_type type) -> token
{
    if(m_current_token.get_type() == type)
    {
        advance();
        return m_current_token;
    }
    error();
}

auto parser::factor() -> std::shared_ptr<ast_node>
{
    token token = m_current_token;

    if(token.get_type() == token_type::LPAREN)
    {
        consume(token_type::LPAREN);
        std::shared_ptr<ast_node> expr = expression();
        consume(token_type::RPAREN);

        return expr;
    }
    else if (token.get_type() == token_type::NUMBER_LITERAL)
    {
        consume(token_type::NUMBER_LITERAL);
        return std::make_shared<ast_number>(token);
    }
    else if (token.get_type() == token_type::MINUS)
    {
        consume(token_type::MINUS);
        std::shared_ptr<ast_node> expr = factor();
        class token number_token(token_type::NUMBER_LITERAL, "0");
        return std::make_shared<ast_bin_op>(std::make_shared<ast_number>(number_token), token, expr);
    }
    else
    {
        error();
    }
}


auto parser::term() -> std::shared_ptr<ast_node>
{
    std::shared_ptr<ast_node> node = factor();

    while(m_current_token.get_type() == token_type::MUL || m_current_token.get_type() == token_type::DIV)
    {
        token op = m_current_token;
        if (op.get_type() == token_type::MUL)
            consume(token_type::MUL);
        else if (op.get_type() == token_type::DIV)
            consume(token_type::DIV);
        std::shared_ptr<ast_node> right = factor();
        node = std::make_shared<ast_bin_op>(node, op, right);
    }

    return node;
}

auto parser::expression() -> std::shared_ptr<ast_node>
{
    std::shared_ptr<ast_node> node = term();

    while (m_current_token.get_type() == token_type::PLUS || m_current_token.get_type() == token_type::MINUS)
    {
        token op = m_current_token;
        if (op.get_type() == token_type::PLUS)
            consume(token_type::PLUS);
        else if (op.get_type() == token_type::MINUS)
            consume(token_type::MINUS);
        std::shared_ptr<ast_node> right = term();
        node = std::make_shared<ast_bin_op>(node, op, right);
    }

    return node;
}

auto parser::parse() -> std::shared_ptr<ast_node> { return expression(); }

auto parser::evaluate(const std::shared_ptr<ast_node> node) const -> int
{
    if (auto num_node = std::dynamic_pointer_cast<ast_number>(node))
        return std::stoi(num_node->get_value().get_value());
    else if (auto bin_op_node = std::dynamic_pointer_cast<ast_bin_op>(node))
    {
        int left_val = evaluate(bin_op_node->get_left());
        int right_val = evaluate(bin_op_node->get_right());

        if (bin_op_node->get_op().get_type() == token_type::MUL)
            return left_val * right_val;
        else if (bin_op_node->get_op().get_type() == token_type::DIV)
            return left_val / right_val;
        else if (bin_op_node->get_op().get_type() == token_type::PLUS)
            return left_val + right_val;
        else if (bin_op_node->get_op().get_type() == token_type::MINUS)
            return left_val - right_val;
    }
    error();
}
