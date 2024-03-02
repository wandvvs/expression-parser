# Arithmetic Expression Parser
The parser implemented with C++23 uses recursive descent parsing to parse the input string and construct an Abstract Syntax Tree (AST) representing the input arithmetic expression.

## Features
- [x] Parsing arithmetic expressions containing numbers, addition, subtraction, multiplication, division, and parentheses.
- [x] Constructing an Abstract Syntax Tree (AST) representing the parsed arithmetic expressions.

## Stages of Interpretation
1. Lexical analysis (tokenization)
2. Building an AST Tree using recursive descent parsing
3. Executing an expression

## Grammar
```
// expr : term ( ( '+' | '-' ) term )* ;
//
// term : factor ( ( '*' | '/' ) factor )* ;
//
// factor : NUMBER_LITERAL | '(' expr ')' | '-' factor ;
```
