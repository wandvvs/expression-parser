#include <utility>

#include "token.hxx"

token::token() = default;

token::token(token_type type, std::string  value)
    : m_type(type), m_value(std::move(value)) {}

auto token::get_value() const -> std::string { return m_value; }
auto token::get_type()  const -> token_type { return m_type; }

auto token::display() const -> void
{
    std::cout << std::format("Token type: {}\tToken value: {}", token_type_strings.at(get_type()), get_value()) << std::endl;
}