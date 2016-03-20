/*
 * declarations for a calculator.   
 */

// interface to the lexer
extern int yylineno;
void yyerror(char*s,...);

/* nodes in the abstract syntax tree */
struct ast {
    int nodetype;
    struct ast *l;
    struct ast *r;
};

struct numval {
    int nodetype;
    double number;
};

/* build an AST */
struct ast *newast(int nodetype, struct ast *l, struct ast *r);
struct ast *newnum(double d);

/* evaluate an ast */
double eval(struct ast *);

/* delete and free an ast */
void treefree(struct ast *);
