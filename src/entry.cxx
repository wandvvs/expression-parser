#include <iostream>

#include "lexer/lexer.hxx"
#include "parser/parser.hxx"

int main()
{
    std::string input {"(10/2) + (5-2) + (10*2) * 2"};

    lexer lex(input);

    std::vector<token> tokens = lex.tokenize();
    parser pars(tokens);
    auto ast = pars.parse();

    std::cout << pars.evaluate(ast) << std::endl;
}
