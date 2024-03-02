# Arithmetic Expression Parser
The parser implemented with C++23 uses recursive descent parsing to parse the input string and construct an Abstract Syntax Tree (AST) representing the input arithmetic expression.

## Features
- [x] Parsing arithmetic expressions containing numbers, addition, subtraction, multiplication, division, and parentheses.
- [x] Constructing an Abstract Syntax Tree (AST) representing the parsed arithmetic expressions.

## Stages of Interpretation
1. Lexical analysis (tokenization)
2. Syntax analysis (Building an AST Tree using recursive descent parsing)
3. Executing an expression

## Grammar
```
// expr : term ( ( '+' | '-' ) term )* ;
//
// term : factor ( ( '*' | '/' ) factor )* ;
//
// factor : NUMBER_LITERAL | '(' expr ')' | '-' factor ;
```

## Example usage
```cpp
#include "lexer/lexer.hxx"
#include "parser/parser.hxx"

int main()
{
    std::string input {"(10/2) + (5-2) + (10*2) * 2"};

    lexer lex(input);

    std::vector<token> tokens = lex.tokenize();
    parser pars(tokens);
    auto ast = pars.parse();

    std::cout << pars.evaluate(ast) << std::endl; // 48
}
```
