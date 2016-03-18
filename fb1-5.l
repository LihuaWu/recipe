/*recognize tokens for the calculator and print them out */
%{
#include "fb1-5.tab.h"
%}

%%
"+" { return ADD; }
"-" { return SUB; }
"*" { return MUL; }
"/" { return DIV; }
"|" { return ABS; }
\n  { return EOL; }
[0-9]+ { yylval = atoi(yytext); return NUMBER; }
[ \t] { /* ignore whitespace */ } 
.   { printf("Mystery character %s\n", yytext); }
%%
