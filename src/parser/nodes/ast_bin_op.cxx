#include <utility>

#include "ast_bin_op.hxx"

ast_bin_op::ast_bin_op(std::shared_ptr<ast_node> left, token op, std::shared_ptr<ast_node> right)
    : m_left(std::move(left)), m_right(std::move(right)), m_op(std::move(op)) {}

auto ast_bin_op::get_left() const -> std::shared_ptr<ast_node> { return m_left; }

auto ast_bin_op::get_right() const -> std::shared_ptr<ast_node> { return m_right; }

auto ast_bin_op::get_op() const -> token { return m_op; }