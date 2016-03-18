/*simplest version of calculator */
/* following the same rule with flex, which also have three-part structure with declarations, rules, and C code. */
%{
#include <stdio.h>
%}

/* declare tokens */
%token NUMBER
%token ADD SUB MUL DIV ABS
%token EOL
%token OP CP

%%

calclist: /* nothing */
    | calclist exp EOL { printf("= %d\n", $2);  }
    | calclist EOL {printf("> "); }
    ;

exp: factor /*default $$ = $1 */
    | exp ADD factor { $$ = $1 + $3; }
    | exp SUB factor { $$ = $1 - $3; }
    | exp ABS factor { $$ = $1 | $3; }
    ;

factor: term 
    | factor MUL term { $$ = $1 * $3; }
    | factor DIV term { $$ = $1 / $3; }
    ;

term: NUMBER
    | ABS term { $$ = ($2 >= 0) ? $2 : - $2; }
    | OP exp CP { $$ = $2; }
    ;
%%

main(int argc, char** argv) {
    printf("> ");
    yyparse();
}

yyerror(char* s) {
    fprintf(stderr, "error: %s\n", s);
}
