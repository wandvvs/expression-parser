cmake_minimum_required(VERSION 3.26)
project(expression_solver)

set(CMAKE_CXX_STANDARD 23)

add_executable(expression_solver
        src/entry.cxx

        src/lexer/token.cxx
        src/lexer/token.hxx
        src/lexer/lexer.cxx
        src/lexer/lexer.hxx
        src/lexer/token_type.hxx

        src/parser/nodes/ast_node.cxx
        src/parser/nodes/ast_node.hxx
        src/parser/nodes/ast_number.cxx
        src/parser/nodes/ast_number.hxx
        src/parser/nodes/ast_bin_op.cxx
        src/parser/nodes/ast_bin_op.hxx
        src/parser/parser.cxx
        src/parser/parser.hxx)
