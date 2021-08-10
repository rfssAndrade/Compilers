%option c++ prefix="fir_scanner_" outfile="fir_scanner.cpp"
%option stack noyywrap yylineno 8bit debug
%{ 
// make relevant includes before including the parser's tab file
#include <string>
#include <cstring>
#include <sstream>
#include <cdk/ast/sequence_node.h>
#include <cdk/ast/expression_node.h>
#include <cdk/ast/lvalue_node.h>
#include "fir_parser.tab.h"

static std::vector<int> deferred;
static std::ostringstream strlit;

// don't change this
#define yyerror LexerError
%}

LETTER  [A-Za-z_]
IDENTIFIER   [A-Za-z]({LETTER}|[[:digit:]])*

%x X_COMMENT
%x X_STRING
%x X_TILDE
%x X_ZERO
%%

 //{yydebug=1;}
 /* ============================================ */
 /* ==== [            COMMENTS            ] ==== */
 /* ============================================ */

"!!".*$                ; /* match the whole line (it is ignored) */

"(*"                   yy_push_state(X_COMMENT);
<X_COMMENT>"*)"        yy_pop_state();
<X_COMMENT>.|"\n"      ; /* ignore comments */

 /* ============================================ */
 /* ==== [              TYPES             ] ==== */
 /* ============================================ */

"int"                  return tTYPE_INT;
"float"                return tTYPE_FLOAT;
"string"               return tTYPE_STRING;
"void"                 return tTYPE_VOID;
"null"                 return tNULL;
"sizeof"               return tSIZEOF;

 /* ============================================ */
 /* ==== [          CONDITIONALS          ] ==== */
 /* ============================================ */

"if"                   return tIF;
"then"                 return tTHEN;
"else"                 return tELSE;

 /* ============================================ */
 /* ==== [            ITERATION           ] ==== */
 /* ============================================ */

"while"                return tWHILE;
"do"                   return tDO;
"finally"              return tFINALLY;
"leave"                return tLEAVE;
"restart"              return tRESTART;

 /* ============================================ */
 /* ==== [            OPERATORS           ] ==== */
 /* ============================================ */

">="                   return tGE; 
"<="                   return tLE; 
"=="                   return tEQ; 
"!="                   return tNE;
"&&"                   return tAND;
"||"                   return tOR;

 /* ============================================ */
 /* ==== [            SEPARATORS          ] ==== */
 /* ============================================ */

"return"               return tRETURN;
"write"                return tWRITE;
"writeln"              return tWRITELN;
"->"                   return tARROW;
">>"                   return tEPILOGUE;

 /* ============================================ */
 /* ==== [             INTEGERS           ] ==== */
 /* ============================================ */

0|[1-9][0-9]*          { try { yylval.i = std::stoi(yytext, nullptr, 10); return tINTEGER; } catch (std::out_of_range &e) { yyerror("overflow"); } }
[0][0-7]+              { try { yylval.i = std::stoi(yytext, nullptr, 8); return tINTEGER; } catch (std::out_of_range &e) { yyerror("overflow"); } }
[0][0-9]+              yyerror("invalid number");

 /* ============================================ */
 /* ==== [              REALS             ] ==== */
 /* ============================================ */

([0-9]*\.[0-9]+|[0-9]+\.[0-9]*)([eE][-+]?[0-9]+)?|([0-9]+)([eE][-+]?[0-9]+) { try { yylval.d = std::stod(yytext); return tFLOAT; } catch (std::out_of_range &e) { yyerror("overflow"); } }

 /* ============================================ */
 /* ==== [           IDENTIFIERS          ] ==== */
 /* ============================================ */

{IDENTIFIER} { yylval.s = new std::string(yytext); return tIDENTIFIER; }

 /* ============================================ */
 /* ==== [             STRINGS            ] ==== */
 /* ============================================ */

"'"                            yy_push_state(X_STRING);
<X_STRING>"~"                  yy_push_state(X_TILDE);
<X_STRING>"'"                  {
                                 yylval.s = new std::string(strlit.str());
                                 strlit.str("");
                                 yy_pop_state();
                                 return tSTRING;
                               }
<X_STRING>"\n"                 yyerror("newline in string");
<X_STRING>.                    strlit << *yytext;

<X_TILDE>n                     strlit << '\n'; yy_pop_state();
<X_TILDE>r                     strlit << '\r'; yy_pop_state();
<X_TILDE>t                     strlit << '\t'; yy_pop_state();
<X_TILDE>"~"                   strlit <<  '~'; yy_pop_state();
<X_TILDE>"'"                   strlit <<  '\''; yy_pop_state();
<X_TILDE>0                     yy_push_state(X_ZERO);

<X_TILDE>[[:xdigit:]]{1,2}     {
                                strlit << (char) std::stoi(yytext, nullptr, 16);
                                yy_pop_state();
                               }
<X_TILDE>"\n"                  yyerror("newline in string");
<X_TILDE>.                     strlit << *yytext; yy_pop_state();

<X_ZERO>"'"                    yy_pop_state();
<X_ZERO>"\n"                   yyerror("newline in string");
<X_ZERO>.                      ;

 /* ============================================ */
 /* ==== [              OTHER             ] ==== */
 /* ============================================ */

[-<>,;(){}@+*/%~?=\[\]]    return *yytext;
[ \t\r\n]                  ; /* ignore whitespace */
.                          yyerror(yytext);

%%
