#include <utility>

#include "ast_number.hxx"

ast_number::ast_number(token  value)
    : m_value(std::move(value)) {}

auto ast_number::get_value() -> token { return m_value; }