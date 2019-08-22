/*
filename: reinboltwakefield.y
additional files: reinboltwakefield.l

Name: Hannah Reinbolt and Robert Wakefield
Date: 3-19-2019
Class: CS 3500
Section: 1A
Instructor: Jennifer Leopold
Homework: Homework # 4
Assignment: Perform syntactical analysis with bison. Add TYPE differenciation.

Bison specification file.
Grammar is:
	<expr> -> intconst | ident | foo <identList> <intconstList>
	<identList> -> epsilon | <identList> ident
	<intconstList> -> intconst | <intconstList> intconst

To create the syntax analyzer:
	flex hreinbolth.l
	bison hreinbolth.y
	g++ hreinbolth.tab.c -o parser
	./parser < inputFileName

How to test example using diff:
	bison hreinbolth.y
	g++ reinbolth.tab.c -o parser
	./parser < operatorsNoErrors.txt > ~/Desktop/HW/PLT/hw3/sample_output/test.txt.out
	diff test.txt.out functionsNoErrors1.txt.out --ignore-space-change --side-by-side --ignore-case --ignore-blank-lines

Note: All the | between the lines in the diff will show you the differences between the files.

*/

%{
#include <stdio.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <stack>
#include "SymbolTable.h"

#define IS_ARITH			11
#define IS_LOGICAL		12
#define IS_REALATION	13


void printRule(const char *lhs, const char *rhs);
int yyerror(const char *s);
void printTokenInfo(const char* tokenType, const char* lexeme);
void endScope( );
void beginScope( );
bool findEntryInAnyScope(const string theName);
void printAddSymb(const string symbName, TYPE_INFO typeinfo);
void printUnDefinedError(const string symbName);
void printMulDefinedError(const string symbName);

int numLines = 1;
int comments = 0;
int spaces = 0;
stack<SYMBOL_TABLE> scopeStack;
//variable for debugging
bool deboog = false;


extern "C" {
	int yyparse(void);
	int yylex(void);
	int yywrap() {return 1;}
	}

%}

%union
{
char* text;
TYPE_INFO typeInfo;
int num;
}

/*Token declarations */
%token T_ASSIGN T_IF T_WHILE T_FUNCTION T_FOR T_IN T_NEXT T_BREAK T_TRUE T_FALSE T_QUIT T_PRINT T_CAT T_READ T_LIST T_COMMENT
%token T_WSPACE T_COMMA T_LBRACE T_RBRACE T_LPAREN T_RBRACKET T_LBRACKET T_ADD T_SUB T_MULT T_DIV T_MOD T_POWER
%token T_LT T_GT T_LE T_GE T_EQ T_NE T_NOT T_AND T_OR  T_SEMICOLON T_STRCONST T_FLOATCONST T_LETTER T_DIGIT T_UNKNOWN T_INTCONST T_IDENT

%type <text>T_IDENT
%type <num> N_REL_OP N_ADD_OP N_MULT_OP
%type <typeInfo> N_CONST N_EXPR N_IF_EXPR N_FUNCTION_DEF N_PARAM_LIST N_VAR N_PARAMS N_SINGLE_ELEMENT N_ENTIRE_VAR
%type <typeInfo> N_ARITHLOGIC_EXPR N_ASSIGNMENT_EXPR N_OUTPUT_EXPR N_INPUT_EXPR N_LIST_EXPR N_EXPR_LIST N_QUIT_EXPR
%type <typeInfo> N_SIMPLE_ARITHLOGIC N_ADD_OP_LIST N_TERM N_FACTOR N_MULT_OP_LIST N_COMPOUND_EXPR N_WHILE_EXPR N_INDEX 

%nonassoc T_RPAREN
%nonassoc T_ELSE


/* Starting point */
%start N_START

/* Transition rules */
%%

N_START				: N_EXPR
										{
										printRule ("START", "EXPR");
										endScope();
										if(deboog == true)
											printf("\n ---- Completed parsing ----\n\n");
										}
										;
N_EXPR				: N_IF_EXPR
										{
										printRule("EXPR", "IF_EXPR");
										$$.type = $1.type;
										$$.numParams = NOT_APPLICABLE;
										$$.returnType = NOT_APPLICABLE;
										}
							| N_WHILE_EXPR
										{
										printRule("EXPR", "WHILE_EXPR");
										$$.type = $1.type;
										$$.numParams = NOT_APPLICABLE;
										$$.returnType = NOT_APPLICABLE;
										}
							| N_FOR_EXPR
										{
										printRule("EXPR", "FOR_EXPR");
										$$.type = NOT_APPLICABLE;
										$$.numParams = NOT_APPLICABLE;
										$$.returnType = NOT_APPLICABLE;
										}
							| N_COMPOUND_EXPR
										{
										printRule("EXPR", "COMPOUND_EXPR");
										$$.type = $1.type;
										$$.numParams = NOT_APPLICABLE;
										$$.returnType = NOT_APPLICABLE;
										}
							| N_ARITHLOGIC_EXPR
										{
										printRule("EXPR", "ARITHLOGIC_EXPR");
										$$.type = $1.type;
										$$.numParams = NOT_APPLICABLE;
										$$.returnType = NOT_APPLICABLE;
										}
							| N_ASSIGNMENT_EXPR
										{
										printRule("EXPR", "ASSIGNMENT_EXPR");
										$$.type = $1.type;
										$$.numParams = NOT_APPLICABLE;
										$$.returnType = NOT_APPLICABLE;
										}
							| N_OUTPUT_EXPR
										{
										printRule("EXPR", "OUTPUT_EXPR");
										$$.type = $1.type;
										$$.numParams = NOT_APPLICABLE;
										$$.returnType = NOT_APPLICABLE;
										}
							| N_INPUT_EXPR
										{
										printRule("EXPR", "INPUT_EXPR");
										$$.type = $1.type;
										$$.numParams = NOT_APPLICABLE;
										$$.returnType = NOT_APPLICABLE;
										}
							| N_LIST_EXPR
										{
										printRule("EXPR", "LIST_EXPR");
										$$.type = $1.type;
										$$.numParams = NOT_APPLICABLE;
										$$.returnType = NOT_APPLICABLE;
										}
							| N_FUNCTION_DEF
										{
										printRule("EXPR", "FUNCTION_DEF");
										$$.type = $1.type;
										$$.numParams = NOT_APPLICABLE;
										$$.returnType = NOT_APPLICABLE;
										}
							| N_FUNCTION_CALL
										{
										printRule("EXPR", "FUNCTION_CALL");
										$$.type = NOT_APPLICABLE;
										$$.numParams = NOT_APPLICABLE;
										$$.returnType = NOT_APPLICABLE;
										}
							| N_QUIT_EXPR
										{
										printRule("EXPR", "QUIT_EXPR");
										$$.type = $1.type;
										$$.numParams = NOT_APPLICABLE;
										$$.returnType = NOT_APPLICABLE;
										exit(1);
										}
							;
N_CONST					: T_INTCONST
										{
										printRule("CONST", "INTCONST");
										$$.type = INT;
										$$.numParams = NOT_APPLICABLE;
										$$.returnType = NOT_APPLICABLE;
										}
								| T_STRCONST
										{
										printRule("CONST", "STRCONST");
										$$.type = STR;
										$$.numParams = NOT_APPLICABLE;
										$$.returnType = NOT_APPLICABLE;
										}
								| T_FLOATCONST
										{
										printRule("CONST", "FLOATCONST");
										$$.type = FLOAT;
										$$.numParams = NOT_APPLICABLE;
										$$.returnType = NOT_APPLICABLE;
										}
								| T_TRUE
										{
										printRule("CONST", "TRUE");
										$$.type = BOOL;
										$$.numParams = NOT_APPLICABLE;
										$$.returnType = NOT_APPLICABLE;
										}
								| T_FALSE
										{
										printRule("CONST", "FALSE");
										$$.type = BOOL;
										$$.numParams = NOT_APPLICABLE;
										$$.returnType = NOT_APPLICABLE;
										}
								;
N_COMPOUND_EXPR	:  T_LBRACE N_EXPR N_EXPR_LIST T_RBRACE
										{
										printRule("COMPOUND_EXPR", "{ EXPR EXPR_LIST }");
										$$.type = $2.type;
										$$.numParams = $2.numParams;
										$$.returnType = $2.returnType;
										}
									;
N_EXPR_LIST				: T_SEMICOLON N_EXPR N_EXPR_LIST
										{
										printRule("EXPR_LIST", "; EXPR EXPR_LIST");
										$$.type = $2.type;
										$$.numParams = $2.numParams;
										$$.returnType = $2.returnType;
										}
									| /*epsilon*/
										{
										printRule("EXPR_LIST", "epsilon");
										}
									;
N_IF_EXPR				: T_IF T_LPAREN N_EXPR T_RPAREN N_EXPR
										{
										printRule("IF_EXPR", "IF ( EXPR ) EXPR");
										}
								| T_IF T_LPAREN N_EXPR T_RPAREN N_EXPR T_ELSE N_EXPR
										{
										printRule("IF_EXPR", "IF ( EXPR ) EXPR ELSE EXPR");
										}
								;
N_WHILE_EXPR		: T_WHILE T_LPAREN N_EXPR T_RPAREN N_EXPR
										{
										printRule("WHILE_EXPR", "WHILE ( EXPR ) EXPR");
											if(($3.type == FUNCTION) || ($3.type == NULL_TYPE) || ($3.type == LIST) || ($3.type == STR))
											{
												yyerror("Arg 1 cannot be function or null or list or string");
											}
											else
											{
												$$.type = $5.type;
												$$.numParams = $5.numParams;
												$$.returnType = $5.returnType;
											}
										}
								;
N_FOR_EXPR			: T_FOR T_LPAREN T_IDENT
								{
										printRule("FOR_EXPR", "FOR ( IDENT IN EXPR ) EXPR");
										// add T_IDENT to the most recent scope if it's not in one
										string lexeme = string($3);
										if(!scopeStack.top().findEntry(lexeme))
											{
											TYPE_INFO newType = {NULL_TYPE, NOT_APPLICABLE, NOT_APPLICABLE};
											newType.type = (scopeStack.top().findEntryData(lexeme)).type;
											printAddSymb(lexeme, newType);
											}
								}
								T_IN N_EXPR T_RPAREN N_EXPR
								;

N_LIST_EXPR			: T_LIST T_LPAREN N_CONST_LIST T_RPAREN
										{
										printRule("LIST_EXPR", "LIST ( CONST_LIST )");
										$$.type = LIST;
										}
								;
N_CONST_LIST		: N_CONST T_COMMA N_CONST_LIST
										{
										printRule("CONST_LIST", "CONST, CONST_LIST");
										}
								| N_CONST
										{
										printRule("CONST_LIST", "CONST");
										}
								;
N_ASSIGNMENT_EXPR	: T_IDENT N_INDEX
										{
										// add T_IDENT to the most recent scope if it's not in a scope
										printRule("ASSIGNMENT_EXPR", "IDENT INDEX ASSIGN EXPR");
										string lexeme = string($1);
										if(!scopeStack.top().findEntry(lexeme))
											{
											TYPE_INFO newType = {NULL_TYPE, NOT_APPLICABLE, NOT_APPLICABLE};
											newType.type= scopeStack.top().findEntryData(lexeme).type;
											printAddSymb(lexeme, newType);
											}
										}
										T_ASSIGN N_EXPR
										{
											if ($2.type == NOT_APPLICABLE)
											{
												string lexeme = string($1);
												if(!scopeStack.top().findEntry(lexeme))
												{
													TYPE_INFO newType = {NOT_APPLICABLE, NOT_APPLICABLE, NOT_APPLICABLE};
													printAddSymb(lexeme, newType);
												}
												yyerror("Arg 1 cannot be list");
											}
											else
											{
												$$.type = NOT_APPLICABLE;
												$$.numParams = NOT_APPLICABLE;
												$$.returnType = NOT_APPLICABLE;
											}
										}
								;
N_INDEX					: T_LBRACKET T_LBRACKET N_EXPR T_RBRACKET T_RBRACKET
										{
										printRule("INDEX", "[[ EXPR ]]");
										}
								| /*epsilon*/
										{
										printRule("INDEX", "epsilon");
										}
								;
N_QUIT_EXPR			: T_QUIT T_LPAREN T_RPAREN
										{
										printRule("QUIT_EXPR", "QUIT()");
										$$.type = NULL_TYPE;
										$$.numParams = NOT_APPLICABLE;
										$$.returnType = NOT_APPLICABLE;
										}
								;
N_OUTPUT_EXPR		: T_PRINT T_LPAREN N_EXPR T_RPAREN
										{
										printRule("OUTPUT_EXPR", "PRINT ( EXPR )");
										if(($3.type == FUNCTION) || ($3.type == NULL_TYPE))
											{
												yyerror("Arg 1 cannot be function or null");
											}
											else
											{
												$$.type = $3.type;
												$$.numParams = NOT_APPLICABLE;
												$$.returnType = NOT_APPLICABLE;
											}
										}

								| T_CAT T_LPAREN N_EXPR T_RPAREN
										{
										printRule("OUTPUT_EXPR", "CAT ( EXPR )");
										$$.type = NULL_TYPE;
										}
								;
N_INPUT_EXPR		: T_READ T_LPAREN N_VAR T_RPAREN
										{
										printRule("INPUT_EXPR", "READ ( VAR )");
										}
								;
N_FUNCTION_DEF	: T_FUNCTION
										{
										// new symbol table
										beginScope();
										}
								T_LPAREN N_PARAM_LIST T_RPAREN N_COMPOUND_EXPR
								{
									printRule("FUNCTION_DEF", "FUNCTION ( PARAM_LIST ) COMPOUND_EXPR");
									$$.type = FUNCTION;
									$$.numParams = NOT_APPLICABLE;
									$$.returnType = NOT_APPLICABLE;
									//close the symbol table for this function
									endScope();
								}
								;
N_PARAM_LIST		: N_PARAMS
										{
										printRule("PARAM_LIST", "PARAMS");
										$$.type = $1.type;
										$$.numParams = NOT_APPLICABLE;
										$$.returnType = NOT_APPLICABLE;
										}
								| N_NO_PARAMS
										{
										printRule("PARAM_LIST", "NO_PARAMS");
										}
								;
N_NO_PARAMS		: /*epsilon*/
										{
										printRule("NO_PARAMS", "epsilon");
										}
								;
N_PARAMS				: T_IDENT
										{
										printRule("PARAMS", "IDENT");

										// add T_IDENT to the most recent scope if it's not in a scope
										string lexeme = string($1);
										if(findEntryInAnyScope(lexeme))
											{
											TYPE_INFO newType = {$$.type, $$.numParams, $$.returnType};
											printAddSymb(lexeme, newType);
											printMulDefinedError(lexeme);
											}
										// if it's not in a scope then add to recent scope
										else
											{
											TYPE_INFO newType = {$$.type, $$.numParams, $$.returnType};
											printAddSymb(lexeme, newType);
											$$.type = INT;
											$$.numParams = NOT_APPLICABLE;
											$$.returnType = NOT_APPLICABLE;
											}
											$$.type = INT;
										}
								| T_IDENT T_COMMA N_PARAMS
										{
										printRule("PARAMS", "IDENT, PARAMS");
											$$.type = INT;
											$$.numParams = NOT_APPLICABLE;
											$$.returnType = NOT_APPLICABLE;
										// add T_IDENT to the most recent scope if it's not in a scope
										string lexeme = string($1);
										if(findEntryInAnyScope(lexeme))
											{
											TYPE_INFO newType = {$$.type, $$.numParams, $$.returnType};
											printAddSymb(lexeme, newType);
											printMulDefinedError(lexeme);
											}
										// if it's not in a scope then add to recent scope
										else
											{
											TYPE_INFO newType = {$$.type, $$.numParams, $$.returnType};
											printAddSymb(lexeme, newType);
											}
										$$.type = INT;

										}
								;
N_FUNCTION_CALL	: T_IDENT T_LPAREN N_ARG_LIST T_RPAREN
										{
										printRule("FUNCTION_CALL", "IDENT ( ARG_LIST )");
										string lexeme = string($1);
										if(!findEntryInAnyScope(lexeme))
											{
											printUnDefinedError(lexeme);
											}
										}
								;
N_ARG_LIST				: N_ARGS
										{
										printRule("ARG_LIST", "ARGS");
										}
								| N_NO_ARGS
										{
										printRule("ARG_LIST", "NO_ARGS");
										}
								;
N_NO_ARGS				: /*epsilon*/
										{
										printRule("NO_ARGS", "epsilon");
										}
								;
N_ARGS						: N_EXPR
										{
										printRule("ARGS", "EXPR");
										}
								| N_EXPR T_COMMA N_ARGS
										{
										printRule("ARGS", "EXPR, ARGS");
										}
								;
N_ARITHLOGIC_EXPR	: N_SIMPLE_ARITHLOGIC
										{
										printRule("ARITHLOGIC_EXPR", "SIMPLE_ARITHLOGIC");

										if($1.type == NOT_APPLICABLE)
										{
											yyerror("Arg 11 must be integer or float or bool");
										}
										else if(($1.type == IS_ARITH) && ($1.type != FLOAT))
										{
											$$.type = INT;
											$$.numParams = NOT_APPLICABLE;
											$$.returnType = NOT_APPLICABLE;
										}
										else if($1.type == FLOAT)
										{
											$$.type = FLOAT;
											$$.numParams = NOT_APPLICABLE;
											$$.returnType = NOT_APPLICABLE;
										}
										else if(($1.type == IS_LOGICAL) || ($1.type == IS_REALATION))
										{
											$$.type = BOOL;
											$$.numParams = NOT_APPLICABLE;
											$$.returnType = NOT_APPLICABLE;
										}
										}
								| N_SIMPLE_ARITHLOGIC N_REL_OP N_SIMPLE_ARITHLOGIC
										{
										printRule("ARITHLOGIC_EXPR", "SIMPLE_ARITHLOGIC REL_OP SIMPLE_ARITHLOGIC");
										if(($1.type == NOT_APPLICABLE) || ($3.type == NOT_APPLICABLE))
										{
											yyerror("Arg 3 must be integer or float or bool");
										}
										else if(($1.type == IS_ARITH) && ($3.type == IS_ARITH))
										{
											$$.type = INT;
											$$.numParams = NOT_APPLICABLE;
											$$.returnType = NOT_APPLICABLE;
										}
										else if(($1.type == FLOAT) || ($3.type == FLOAT))
										{
											$$.type = FLOAT;
											$$.numParams = NOT_APPLICABLE;
											$$.returnType = NOT_APPLICABLE;
										}
										else if(($1.type == IS_LOGICAL) || ($1.type == IS_REALATION) || ($3.type == IS_LOGICAL) || ($3.type == IS_REALATION))
										{
											$$.type = BOOL;
											$$.numParams = NOT_APPLICABLE;
											$$.returnType = NOT_APPLICABLE;
										}
										else
										{
											yyerror("Arg 4 must be integer or float or bool");
										}
										}
								;
N_SIMPLE_ARITHLOGIC	: N_TERM N_ADD_OP_LIST
										{
										printRule("SIMPLE_ARITHLOGIC", "TERM ADD_OP_LIST");
										// add a rule here
										if(($2.type == NOT_APPLICABLE))
										{
											if($1.type != NOT_APPLICABLE)
											{
												$$.type = $1.type;
												$$.numParams = NOT_APPLICABLE;
												$$.returnType = NOT_APPLICABLE;
											}
											else
											{
												yyerror("Arg 5 must be integer or float or bool");
											}
										}
										else if (($2.type == IS_ARITH) || ($1.type == IS_ARITH))
										{
											$$.type = INT;
											$$.numParams = NOT_APPLICABLE;
											$$.returnType = NOT_APPLICABLE;
										}
										else if (($2.type == IS_LOGICAL) || ($1.type == IS_LOGICAL))
										{
											$$.type = BOOL;
											$$.numParams = NOT_APPLICABLE;
											$$.returnType = NOT_APPLICABLE;
										}
										else
										{
											$$.type = FLOAT;
											$$.numParams = NOT_APPLICABLE;
											$$.returnType = NOT_APPLICABLE;
										}
										}
								;
N_ADD_OP_LIST				: N_ADD_OP N_TERM N_ADD_OP_LIST
										{
										printRule("ADD_OP_LIST", "ADD_OP TERM ADD_OP_LIST");
										// add a thing here
										if($1 == IS_ARITH)
										{
											if(($3.type == NOT_APPLICABLE) || ($3.type != BOOL) || ($3.type != INT) || ($3.type != FLOAT))
											{
												// episilon here
												if(($2.type != NOT_APPLICABLE))
												{
													$$.type = $2.type;
													$$.numParams = NOT_APPLICABLE;
													$$.returnType = NOT_APPLICABLE;
												}
												else
												{
													yyerror("Arg 6 must be integer or float or bool");
												}
											}
											else if (($2.type == IS_ARITH) && ($3.type == IS_ARITH))
											{
												$$.type = INT;
												$$.numParams = NOT_APPLICABLE;
												$$.returnType = NOT_APPLICABLE;
											}
											else
											{
												$$.type = FLOAT;
												$$.numParams = NOT_APPLICABLE;
												$$.returnType = NOT_APPLICABLE;
											}
										}
										else if($1 == IS_LOGICAL)
										{
											$$.type = BOOL;
											$$.numParams = NOT_APPLICABLE;
											$$.returnType = NOT_APPLICABLE;
										}
										else
										{
											yyerror("Arg 7 must be integer or float or bool");
										}
										}
								| /*epsilon*/
										{
										printRule("ADD_OP_LIST", "epsilon");
										$$.type = NOT_APPLICABLE;
										$$.numParams = NOT_APPLICABLE;
										$$.returnType = NOT_APPLICABLE;
										}
								;
N_TERM					: N_FACTOR N_MULT_OP_LIST
										{
										printRule("TERM", "FACTOR MULT_OP_LIST");
										// add a thing here
										if(($2.type == NOT_APPLICABLE) || ($2.type != BOOL) || ($2.type != INT) || ($2.type != FLOAT))
										{
											if(($1.type != NOT_APPLICABLE))
											{
												$$.type = $1.type;
												$$.numParams = NOT_APPLICABLE;
												$$.returnType = NOT_APPLICABLE;
											}
											else
											{
												yyerror("Arg 8 must be integer or float or bool");
											}
										}
										else if (($1.type == IS_LOGICAL) && ($2.type == IS_LOGICAL))
										{
											$$.type = BOOL;
											$$.numParams = NOT_APPLICABLE;
											$$.returnType = NOT_APPLICABLE;
										}
										else if (($1.type == IS_ARITH) && ($2.type == IS_ARITH))
										{
											$$.type = INT;
											$$.numParams = NOT_APPLICABLE;
											$$.returnType = NOT_APPLICABLE;
										}
										else
										{
											$$.type = FLOAT;
											$$.numParams = NOT_APPLICABLE;
											$$.returnType = NOT_APPLICABLE;
										}
										}
								;
N_MULT_OP_LIST	: N_MULT_OP N_FACTOR N_MULT_OP_LIST
										{
										printRule("MULT_OP_LIST", "MULT_OP FACTOR MULT_OP_LIST");
										if($1 == IS_ARITH)
										{
											if(($3.type == NOT_APPLICABLE) || ($3.type != BOOL) || ($3.type != INT) || ($3.type != FLOAT))
											{
												// episilon here
												if(($2.type != NOT_APPLICABLE))
												{
													$$.type = $2.type;
													$$.numParams = NOT_APPLICABLE;
													$$.returnType = NOT_APPLICABLE;
												}
												else
												{
													yyerror("Arg 9 must be integer or float or bool");
												}
											}
											else if (($2.type == IS_ARITH) && ($3.type == IS_ARITH))
											{
												$$.type = INT;
												$$.numParams = NOT_APPLICABLE;
												$$.returnType = NOT_APPLICABLE;
											}
											else
											{
												$$.type = FLOAT;
												$$.numParams = NOT_APPLICABLE;
												$$.returnType = NOT_APPLICABLE;
											}
										}
										else if($1 == IS_LOGICAL)
										{
											$$.type = BOOL;
											$$.numParams = NOT_APPLICABLE;
											$$.returnType = NOT_APPLICABLE;
										}
										else
										{
											yyerror("Arg 10 must be integer or float or bool");
										}
										}
								| /*epsilon*/
										{
										printRule("MULT_OP_LIST", "epsilon");
										$$.type = NOT_APPLICABLE;
										$$.numParams = NOT_APPLICABLE;
										$$.returnType = NOT_APPLICABLE;
										}
								;
N_FACTOR				: N_VAR
										{
										printRule("FACTOR", "VAR");
										$$.type = $1.type;
										$$.numParams = NOT_APPLICABLE;
										$$.returnType = NOT_APPLICABLE;
										}
								| N_CONST
										{
										printRule("FACTOR", "CONST");
										$$.type = $1.type;
										$$.numParams = NOT_APPLICABLE;
										$$.returnType = NOT_APPLICABLE;
										}
								| T_LPAREN N_EXPR T_RPAREN
										{
										printRule("FACTOR", "( EXPR )");
										$$.type = $2.type;
										$$.numParams = NOT_APPLICABLE;
										$$.returnType = NOT_APPLICABLE;
										}
								| T_NOT N_FACTOR
										{
										printRule("FACTOR", "! FACTOR");
										$$.type = $2.type;
										$$.numParams = NOT_APPLICABLE;
										$$.returnType = NOT_APPLICABLE;
										}
								;
N_ADD_OP				: T_ADD
										{
										printRule("ADD_OP", "+");
										$$ = IS_ARITH;
										}
								| T_SUB
										{
										printRule("ADD_OP", "-");
										$$ = IS_ARITH;
										}
								| T_OR
										{
										printRule("ADD_OP", "|");
										$$ = IS_LOGICAL;
										}
								;
N_MULT_OP			: T_MULT
										{
										printRule("MULT_OP", "*");
										$$ = IS_ARITH;
										}
								| T_DIV
										{
										printRule("MULT_OP", "/");
										$$ = IS_ARITH;
										}
								| T_AND
										{
										printRule("MULT_OP", "&");
										$$ = IS_LOGICAL;
										}
								| T_MOD
										{
										printRule("MULT_OP", "%%");
										$$ = IS_ARITH;
										}
								| T_POWER
										{
										printRule("MULT_OP", "^");
										$$ = IS_ARITH;
										}
								;
N_REL_OP				: T_LT
										{
										printRule("REL_OP", "<");
										}
								| T_GT
										{
										printRule("REL_OP", ">");
										}
								| T_LE
										{
										printRule("REL_OP", "<=");
										}
								| T_GE
										{
										printRule("REL_OP", ">=");
										}
								| T_EQ
										{
										printRule("REL_OP", "==");
										}
								| T_NE
										{
										printRule("REL_OP", "!=");
										}
								;
N_VAR						: N_ENTIRE_VAR
										{
										printRule("VAR", "ENTIRE_VAR");
										$$.type = $1.type;
										$$.numParams = NOT_APPLICABLE;
										$$.returnType = NOT_APPLICABLE;
										}
								| N_SINGLE_ELEMENT
										{
										printRule("VAR", "SINGLE_ELEMENT");
										$$.type = $1.type;
										$$.numParams = NOT_APPLICABLE;
										$$.returnType = NOT_APPLICABLE;
										}
								;
N_SINGLE_ELEMENT	: T_IDENT T_LBRACKET T_LBRACKET N_EXPR T_RBRACKET T_RBRACKET
										{
										printRule("SINGLE_ELEMENT", "IDENT [[ EXPR ]]");
										string lexeme = string($1);
										// first make sure that it exists
										if (findEntryInAnyScope(lexeme))
										{
											// if ident exists it should have a type right? right?
											if (scopeStack.top().findEntryData(lexeme).type == LIST)// < so then why does this fuck up?
											{
												$$.type = INT_OR_STR_OR_BOOL_OR_FLOAT;
												$$.numParams = NOT_APPLICABLE;
												$$.returnType = NOT_APPLICABLE;
											}
											else
											{
												yyerror("Arg 1 must be list");
											}
										}
										else
										{
											printUnDefinedError(lexeme);
										}
										}
								;
N_ENTIRE_VAR			: T_IDENT
										{
										printRule("ENTIRE_VAR", "IDENT");
										$$.type = INT;
										$$.numParams = NOT_APPLICABLE;
										$$.returnType = NOT_APPLICABLE;
										//check if undefined
										string lexeme = string($1);
										if(!findEntryInAnyScope(lexeme))
											{
											printUnDefinedError(lexeme);
											}
										}
								;
%%

//symbol table files
#include <stack>
#include "SymbolTable.h" //we dont need the other one because it is included in this one

#include "lex.yy.c"
extern FILE *yyin;

void printRule(const char *lhs, const char *rhs)
{
	if (deboog == true)
		printf("%s -> %s\n", lhs, rhs);
}

int yyerror(const char *s)
{
	char str[9];
	sprintf(str, "%d", numLines);
	printf("Line %s", str);
	printf(": %s\n",s);
	exit(1);
	return(1);
}

void printTokenInfo(const char* tokenType, const char* lexeme)
{
	if (deboog == true)
		printf("TOKEN: %s	LEXEME: %s\n", tokenType, lexeme);
}


void printMulDefinedError(const string symbName)
{
	char str[9];
	sprintf(str, "%d", numLines);
	printf("Line %s", str);
	printf(": Multiply defined identifier\n");
	exit(1);
}

void printUnDefinedError(const string symbName)
{
	char str[9];
	sprintf(str, "%d", numLines);
	printf("Line %s", str);
	printf(": Undefined identifier\n");
	exit(1);
}

void printAddSymb(const string symbName, TYPE_INFO typeinfo)
{
	scopeStack.top().addEntry(SYMBOL_TABLE_ENTRY(symbName, typeinfo));
	if (deboog == true)
		printf("___Adding %s to symbol table\n", symbName.c_str());
}

bool findEntryInAnyScope(const string theName)
{
	if (scopeStack.empty()) return(false);
	bool found = scopeStack.top().findEntry(theName);
	if (found)
		return(true);
	else { // check in "next higher" scope
		SYMBOL_TABLE symbolTable = scopeStack.top();
		scopeStack.pop();
		found = findEntryInAnyScope(theName);
		scopeStack.push(symbolTable); // restore the stack
		return(found);
	}
}

void beginScope( )
{
	scopeStack.push(SYMBOL_TABLE( ));
	if (deboog == true)
		printf("\n___Entering new scope...\n\n");
}

void endScope( )
{
	scopeStack.pop( );
	if (deboog == true)
		printf("\n___Exiting scope...\n\n");
}


int main()
{
	// make the global table
	beginScope();

	do
	{
		yyparse();
		numLines++;
	} while(!feof(yyin));

	return 0;
}
