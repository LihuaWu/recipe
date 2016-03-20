/*fb2-4 text concordance */
%option noyywrap nodefault yylineno case-insensitive

%{
/* the symbol table */
    struct symbol {
        char* name;
        struct ref *reflist;
    };

    struct ref {
        struct ref *next;
        char* filename;
        int flags;
        int lineno;
    };

    /* simple symtab of fixed size */
    #define NHASH 9997
    struct symbol symtab[NHASH];
    
    struct symbol *lookup(char*);
    void addref(int, char*, char*, int);

    char* curfilename;
%}

%%
 /* rules for concordance generator */
 /* skip common words */
a  |
an |
be |
to /* ignore */

[a-z]+(\'(s|t))?    { addref(yylineno, curfilename, yytext, 0); }
.|\n            /* ignore everything else */

%%

main(int argc, char** argv) {
    int i;
    if (argc < 2) {
        curfilename = "(stdin)";
        yylineno = 1;
        yylex();
    } else {
        for (i = 1; i < argc; i++) {
            FILE *f = fopen(argv[i], "r");
            
            if (!f) {
                perror(argv[1]);
                return (1);
            } 
            curfilename = argv[i];
            yyrestart(f);
            yylineno = 1;
            yylex();
            fclose(f);
        }
        printrefs();
    }
}