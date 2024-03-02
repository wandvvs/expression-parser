//
// Created by wand on 02.03.2024.
//

#include "lexer.hxx"

lexer::lexer(const std::string &input)
    : m_input(input), m_pos(0), m_current(input.at(0)) {}

auto lexer::move_next() -> void
{
    ++m_pos;

    if (m_pos > m_input.size() - 1)
    {
        m_current = '\0';
    }
    else
    {
        m_current = m_input.at(m_pos);
    }
}

auto lexer::parse_digit() -> std::string
{
    std::string result {};

    while(std::isdigit(m_current))
    {
        result.push_back(m_current);
        move_next();
    }

    return result;
}

auto lexer::tokenize() -> std::vector<token>
{
    std::vector<token> tokens {};

    while (m_current != '\0')
    {
        if(!std::isspace(m_current))
        {
            if(std::isdigit(m_current))
            {
                tokens.emplace_back(token_type::NUMBER_LITERAL, parse_digit());
            }

            switch (m_current)
            {
                case '+':
                {
                    tokens.emplace_back(token_type::PLUS, std::string(1, m_current));
                    move_next();
                    break;
                }

                case '-':
                {
                    tokens.emplace_back(token_type::MINUS, std::string(1, m_current));
                    move_next();
                    break;
                }
                case '*':
                {
                    tokens.emplace_back(token_type::MUL, std::string(1, m_current));
                    move_next();
                    break;
                }

                case '/':
                {
                    tokens.emplace_back(token_type::DIV, std::string(1, m_current));
                    move_next();
                    break;
                }

                case '(':
                {
                    tokens.emplace_back(token_type::LPAREN, std::string(1, m_current));
                    move_next();
                    break;
                }

                case ')':
                {
                    tokens.emplace_back(token_type::RPAREN, std::string(1, m_current));
                    move_next();
                    break;
                }
            }
        }
        else
        {
            move_next();
        }
    }

    tokens.emplace_back(token_type::END, "EOF");

    return tokens;
}
