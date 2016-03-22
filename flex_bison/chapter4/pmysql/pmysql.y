/* Parser for mysql subset */

%{
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

void yyerror(char *s, ...);
void emit(char *s, ...);
%}

%union {
    int     intval;
    double  floatval;
    char    *strval;
    int     subtok;
}

/* names and lieral values*/
%token <strval> NAME
%token <strval> STRING 
%token <intval> INTNUM
%token <intval> BOOL
%token <floatval> APPROXNUM

/* user @abc names */
%token <strval> USERVAR

/* operators and precedence levels*/
%right ASSIGN
%left OR
%left XOR
%left ANDOP
%nonassoc IN IS LIKE REGEXP
%left NOT '!'
%left BETWEEN
%left <subtok> COMPARISON /* = <> < > <= >= <=> */
%left '|'
%left '&'
%left <subtok> SHIFT /*<< >> */
%left '+' '-'
%left '*' '/' '%' MOD
%left '^'
%nonassoc UMINUS


%token ADD
%token ALL
%token ALTER
%token ANALYZE
%token AND
%token ANY
%token AS
%token ASC
%token AUTO_INCREMENT
%token BEFORE
%token BETWEEN
%token BIGINT
%token BINARY
%token BIT
%token BLOB
%token BOTH
%token BY
%token CALL
%token CASCADE
%token CASE
%token CHANGE
%token CHAR
%token CHECK
%token COLLATE
%token COLUMN
%token COMMENT
%token CONDITION
%token CONSTRAINT
%token CONTINUE
%token CONVERT
%token CREATE
%token CROSS
%token CURRENT_DATE
%token CURRENT_TIME
%token CURRENT_TIMESTAMP
%token CURRENT_USER
%token CURSOR
%token DATABASE
%token DATABASES
%token DATE
%token DATETIME
%token DAY_HOUR
%token DAY_MICROSECOND
%token DAY_MINUTE
%token DAY_SECOND
%token DECIMAL
%token DECLARE
%token DEFAULT
%token DELAYED
%token DELETE
%token DESC
%token DESCRIBE
%token DETERMINISTIC
%token DISTINCT
%token DISTINCTROW
%token DIV
%token DOUBLE
%token DROP
%token DUAL
%token EACH
%token ELSE
%token ELSEIF
%token ENCLOSED
%token END
%token ENUM
%token ESCAPED
%token <subtok> EXISTS
%token EXIT
%token EXPLAIN
%token FETCH
%token FLOAT
%token FOR
%token FORCE
%token FOREIGN
%token FROM
%token FULLTEXT
%token GRANT
%token GROUP
%token HAVING
%token HIGH_PRIORITY
%token HOUR_MICROSECOND
%token HOUR_MINUTE
%token HOUR_SECOND
%token IF
%token IGNORE
%token IN
%token INDEX
%token INFILE
%token INNER
%token INOUT
%token INSENSITIVE
%token INSERT
%token INT
%token INTEGER
%token INTERVAL
%token INTO
%token ITERATE
%token JOIN
%token KEY
%token KEYS
%token KILL
%token LEADING
%token LEAVE
%token LEFT
%token LIKE
%token LIMIT
%token LINES
%token LOAD
%token LOCALTIME
%token LOCALTIMESTAMP
%token LOCK
%token LONG
%token LONGBLOB
%token LONGTEXT
%token LOOP
%token LOW_PRIORITY
%token MATCH
%token MEDIUMBLOB
%token MEDIUMINT
%token MEDIUMTEXT
%token MINUTE_MICROSECOND
%token MINUTE_SECOND
%token MOD
%token MODIFIES
%token NATURAL
%token NOT
%token NO_WRITE_TO_BINLOG
%token NULLX
%token NUMBER
%token ON
%token ONDUPLICATE
%token OPTIMIZE
%token OPTION
%token OPTIONALLY
%token OR
%token ORDER
%token OUT
%token OUTER
%token OUTFILE
%token PRECISION
%token PRIMARY
%token PROCEDURE
%token PURGE
%token QUICK
%token READ
%token READS
%token REAL
%token REFERENCES
%token REGEXP
%token RELEASE
%token RENAME
%token REPEAT
%token REPLACE
%token REQUIRE
%token RESTRICT
%token RETURN
%token REVOKE
%token RIGHT
%token ROLLUP
%token SCHEMA
%token SCHEMAS
%token SECOND_MICROSECOND
%token SELECT
%token SENSITIVE
%token SEPARATOR
%token SET
%token SHOW
%token SMALLINT
%token SOME
%token SONAME
%token SPATIAL
%token SPECIFIC
%token SQL
%token SQLEXCEPTION
%token SQLSTATE
%token SQLWARNING
%token SQL_BIG_RESULT
%token SQL_CALC_FOUND_ROWS
%token SQL_SMALL_RESULT
%token SSL
%token STARTING
%token STRAIGHT_JOIN
%token TABLE
%token TEMPORARY
%token TEXT
%token TERMINATED
%token THEN
%token TIME
%token TIMESTAMP
%token TINYBLOB
%token TINYINT
%token TINYTEXT
%token TO
%token TRAILING
%token TRIGGER
%token UNDO
%token UNION
%token UNIQUE
%token UNLOCK
%token UNSIGNED
%token UPDATE
%token USAGE
%token USE
%token USING
%token UTC_DATE
%token UTC_TIME
%token UTC_TIMESTAMP
%token VALUES
%token VARBINARY
%token VARCHAR
%token VARYING
%token WHEN
%token WHERE
%token WHILE
%token WITH
%token WRITE
%token XOR
%token YEAR
%token YEAR_MONTH
%token ZEROFILL

 /* functions with special syntax */
%token FSUBSTRING
%token FTRIM
%token FDATE_ADD FDATE_SUB
%token FCOUNT

%type <intval> select_opts select_expr_list
%type <intval> val_list opt_val_list case_list
%type <intval> groupby_list opt_with_rollup opt_asc_desc
%type <intval> table_references opt_inner_cross opt_outer
%type <intval> left_or_right opt_left_or_right_outer column_list
%type <intval> index_list opt_for_join

%type <intval> delete_opts delete_list
%type <intval> insert_opts insert_vals insert_vals_list
%type <intval> insert_asgn_list opt_if_not_exists update_opts update_asgn_list
%type <intval> opt_temporary opt_length opt_binary opt_uz enum_list
%type <intval> column_atts data_type opt_ignore_replace create_col_list

%start stmt_list

%%

stmt_list: stmt ';'
    | stmt_list ';'
    ;

 /* expressions */

expr:NAME   { emit("NAME %s", $1); free ($1); }
    | NAME '.' NAME { emit("FIELDNAME %s.%s", $1, $3); free($1); free($3); }  
    | USERVAR       { emit("USERVAR %s", $1); free($1); }
    | STRING        { emit("STRING %s", $1); free($1); }
    | INTNUM        { emit("NUMBER %d", $1); }
    | APPROXNUM        { emit("FLOAT %g", $1); }
    | BOOL          { emit("BOOL %s", $1); }
;

expr: expr '+' expr { emit("ADD"); }
    | expr '-' expr { emit("SUB"); }
    | expr '*' expr { emit("MUL"); }
    | expr '/' expr { emit("DIV"); }
    | expr '%' expr { emit("MOD"); }
    | expr MOD expr { emit("MOD"); }
    | '-' expr %prec UMINUS { emit("NEG"); }
    | expr ANDOP expr { emit("AND"); }
    | expr OR    expr { emit("OR"); }
    | expr XOR   expr { emit("XOR"); }
    | expr '|'   expr { emit("BITOR"); }
    | expr '&'   expr { emit("BITAND"); }
    | expr '^'   expr { emit("BITXOR"); }
    | expr SHIFT expr { emit("SHIFT %s", $2==1?"left":"right"); }
    | NOT expr { emit("NOT"); }
    | '!' expr { emit("NOT"); }
    | expr COMPARISON expr { emit("CMP %d", $2); }

     /* recursive selects and comparisons thereto*/
    | expr COMPARISON '(' select_stmt ')' { emit("CMPSELECT %d", $2);}
    | expr COMPARISON ANY '(' select_stmt ')' { emit("CMPANYSELECT %d", $2);}
    | expr COMPARISON SOME '(' select_stmt ')' { emit("CMPSOMESELECT %d", $2);}
    | expr COMPARISON ALL '(' select_stmt ')' { emit("CMPALLSELECT %d", $2);}
;

expr: expr IS NULLX { emit("ISNULL"); }
    | expr IS NOT NULLX { emit("ISNULL"); emit("NOT"); }
    | expr IS BOOL  { emit("ISBOOL %d", $3); }
    | expr IS NOT BOOL  { emit("ISBOOL %d", $4); emit("NOT"); }
    | USERVAR ASSIGN expr { emit("ASSIGN @%s", $1); free($1); }
;

expr: expr BETWEEN expr AND expr $prec BETWEEN { emit("BETWEEN"); }

val_list: expr { $$ = 1; }
    | expr ',' val_list { $$ = 1 + $3; }
;
opt_val_list: '/* nil*/' { $$ = 0;}
    | val_list
;

expr : expr IN '(' val_list ')' { emit("ISIN %d", $4); }
    | expr NOT IN '(' val_list ')' { emit("ISIN %d", $5); emit("NOT"); }
    | expr IN '(' select_stmt ')' { emit("CMPANYSELECT 4"); }
    | expr NOT IN '(' select_stmt ')' { emit("CMPALLSELECT 3"); }
    | EXISTS '(' select_stmt ')' { emit("EXISTSSELECT"); if ($1) emit("NOT");  }

    /*regular functions */
expr : NAME '(' opt_val_list ')' { emit("CALL %d %s", $3, $1); free($1); }

    /* functions with special syntax */
expr : FCOUNT '(' '*' ')' { emit("COUNTALL"); }
    | FCOUNT '(' expr ')' { emit(" CALL 1 COUNT"); }
;

expr: FSUBSTRING '(' val_list ')' { emit("CALL %d SUBSTR", $3); }
    | FSUBSTRING '(' expr FROM expr ')' { emit("CALL 2 SUBSTR"); }
    | FSUBSTRING '(' expr FROM expr FOR expr ')' { emit("CALL 3 SUBSTR"); }
    | FTRIM '(' val_list ')'    { emit("CALL %d TRIM", $3); }
    | FTRIM '(' trim_ltb expr FROM val_list ')' { emit("CALL 3 TRIM"); }
;

trim_ltb: LEADING   { emit("NUMBER 1"); }
    | TRAILING  { emit("NUBMER 2"); }
    | BOTH  { emit("NUMBER 3"); }
;
