/*recognize tokens for the calculator and print them out.*/

%%
"+" { printf("PLUS\n"); }
"-" { printf("MINUS\n"); }
"*" { printf("TIMES\n"); }
"/" { printf("DIVIDE"); }
"|" { printf("ABS"); }
\n  { printf("NEWLINE\n"); }
[0-9]+ { printf("NUMBER %s\n", yytext); }
[ \t] { }
.   { printf("Mystery character %s\n", yytext); }
%%
