/*
Hannah Reinbolt
1-31-2019
PLT section 1A
Assignment #1 - Lexical Analyzer

Example run:
-------------
flex reinbolth.l
g++ lex.yy.c -o lexer
lexer < inputFileName
*/

%{
/* Const, vars, function prototypes and #includes */

#define T_IDENT				1
#define T_INTCONST			2
#define T_UNKNOWN		3
#define T_FOO					4
#define T_DIGIT					5
#define T_LETTER				6
#define T_FLOATCONST	7
#define T_STRCONST		8
#define T_SEMICOLON		9
#define T_COMMA				10
#define T_LBRACE			11
#define T_RBRACE			12
#define T_RPAREN			13
#define T_LPAREN			14
#define T_RBRACKET		15
#define T_LBRACKET		16
#define T_ADD					17
#define T_SUB					18
#define T_MULT				19
#define T_DIV					20
#define T_MOD					21
#define T_POWER				22
#define T_LT						23
#define T_GT						24
#define T_LE						25
#define T_GE					26
#define T_EQ					27
#define T_NE						28
#define T_NOT					29
#define T_AND					30
#define T_OR					31
#define T_ASSIGN				32
#define T_IF						33
#define T_ELSE					34
#define T_WHILE				35
#define T_FUNCTION			36
#define T_FOR					37
#define T_IN						38
#define T_NEXT					39
#define T_BREAK				40
#define T_TRUE					41
#define T_FALSE				42
#define T_QUIT					43
#define T_PRINT				44
#define T_CAT					45
#define T_READ				46
#define T_LIST					47
#define T_COMMENT			48
#define T_WSPACE			49

int numLines = 0;
int comments = 0;
int spaces = 0;
void printTokenInfo(const char* tokenType, const char* lexeme);
%}

/* Defines of regular expressions*/ 
WSPACE		[ \t\r]+
NEWLINE		\n

DIGIT		[0-9]
LETTER		[a-zA-Z]

IDENT		[a-zA-Z0-9\_]+[a-zA-Z0-9\_]*
INTCONST	[+-]?[0-9]+

FLOATCONST	[+-]?[0-9]*\.[0-9]+
STRCONST	\"([^"\n]|\.)*\"

COMMENT		#+.*\n*
%%


";"		{
			printTokenInfo("SEMICOLON", yytext);
			return T_SEMICOLON;
		}
","		{
			printTokenInfo("COMMA", yytext);
			return T_COMMA;
		}
"{"		{
			printTokenInfo("LBRACE", yytext);
			return T_LBRACE;
		}
"}"		{
			printTokenInfo("RBRACE", yytext);
			return T_RBRACE;
		}
")"		{
			printTokenInfo("RPAREN", yytext);
			return T_RPAREN;
		}
"("		{
			printTokenInfo("LPAREN", yytext);
			return T_LPAREN;
		}
"]"		{
			printTokenInfo("RBRACKET", yytext);
			return T_RBRACKET;
		}
"["		{
			printTokenInfo("LBRACKET", yytext);
			return T_LBRACKET;
		}
"+"		{
			printTokenInfo("ADD", yytext);
			return T_ADD;
		}
"-"		{
			printTokenInfo("SUB", yytext);
			return T_SUB;
		}
"*"		{
			printTokenInfo("MULT", yytext);
			return T_MULT;
		}
"/"		{
			printTokenInfo("DIV", yytext);
			return T_DIV;
		}
"%%"		{
			printTokenInfo("MOD", yytext);
			return T_MOD;
		}
"^"		{
			printTokenInfo("POWER", yytext);
			return T_POWER;
		}
"<"		{
			printTokenInfo("LT", yytext);
			return T_LT;
		}
">"		{
			printTokenInfo("GT", yytext);
			return T_GT;
		}
"<="		{
			printTokenInfo("LE", yytext);
			return T_LE;
		}
">="		{
			printTokenInfo("GE", yytext);
			return T_GE;
		}
"=="		{
			printTokenInfo("EQ", yytext);
			return T_EQ;
		}
"!="		{
			printTokenInfo("NE", yytext);
			return T_NE;
		}
"!"		{
			printTokenInfo("NOT", yytext);
			return T_NOT;
		}
"&"		{
			printTokenInfo("AND", yytext);
			return T_AND;
		}
"|"		{
			printTokenInfo("OR", yytext);
			return T_OR;
		}
"="		{
			printTokenInfo("ASSIGN", yytext);
			return T_ASSIGN;
		}
"if"		{
			printTokenInfo("IF", yytext);
			return T_IF;
		}
"else"		{
			printTokenInfo("ELSE", yytext);
			return T_ELSE;
		}
"while"		{
			printTokenInfo("WHILE", yytext);
			return T_WHILE;
		}
"function"	{
			printTokenInfo("FUNCTION", yytext);
			return T_FUNCTION;
		}
"for"		{
			printTokenInfo("FOR", yytext);
			return T_FOR;
		}
"in"		{
			printTokenInfo("IN", yytext);
			return T_IN;
		}
"next"		{
			printTokenInfo("NEXT", yytext);
			return T_NEXT;
		}
"break"		{
			printTokenInfo("BREAK", yytext);
			return T_BREAK;
		}
"TRUE"		{
			printTokenInfo("TRUE", yytext);
			return T_TRUE;
		}
"FALSE"		{
			printTokenInfo("FALSE", yytext);
			return T_FALSE;
		}
"quit"		{
			printTokenInfo("QUIT", yytext);
			return T_QUIT;
		}
"print"		{
			printTokenInfo("PRINT", yytext);
			return T_PRINT;
		}
"cat"		{
			printTokenInfo("CAT", yytext);
			return T_CAT;
		}
"read"		{
			printTokenInfo("READ", yytext);
			return T_READ;
		}
"list"		{
			printTokenInfo("LIST", yytext);
			return T_LIST;
		}
{COMMENT}		{
			comments++;
		}
{FLOATCONST}	{
			printTokenInfo("FLOATCONST", yytext);
			return T_FLOATCONST;
		}
{INTCONST}	{
			printTokenInfo("INTCONST", yytext);
			return T_INTCONST;
		}
{STRCONST}	{
			printTokenInfo("STRCONST", yytext);
			return T_STRCONST;
		}
{IDENT}		{
			printTokenInfo("IDENT", yytext);
			return T_IDENT;
		}
{NEWLINE}	{
			numLines++;
		}
{WSPACE}	{
			spaces++;
		}
.		{
			printTokenInfo("UNKNOWN", yytext);
			return T_UNKNOWN;
		}
%%
// User-Written code here
void printTokenInfo(const char* tokenType, const char* lexeme)
{
	printf("TOKEN: %s LEXEME: %s\n", tokenType, lexeme);
}

// You should specify a yywrap function.
// Having it return 1 means only 1 input file will be scanned.
int yywrap() { return 1; }

int main()
{
	while (yylex()); // Keep processing tokens till 0 is returned
	return 0;
}








