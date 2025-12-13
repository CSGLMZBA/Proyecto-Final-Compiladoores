%{
	#include <iostream>
	#include <iomanip>
	#include <fstream>
	#include <string>
	#include <list>
	#include <cstring>
	#include <stdio.h>
	#include <stdlib.h>
	using namespace std; 
	extern void yyerror(const char *);
	#include "symfuncs.h"
	#include "genlib.h"

	int yylex();
	extern FILE * yyin;

	enum OP_TYPES
	{
		PLUS_OP = 1,
		ADDR_OP,
		MINUS_OP,
		DEREF_OP,
		TWOCOMP_OP,
		NOT_OP
	};

	enum ASSIGN_TYPES {
		EQ_ASSIGN_OP = 1,
		MUL_ASSIGN_OP,
		DIV_ASSIGN_OP,
		MOD_ASSIGN_OP,
		ADD_ASSIGN_OP,
		SUB_ASSIGN_OP,
		LEFT_ASSIGN_OP,
		RIGHT_ASSIGN_OP,
		AND_ASSIGN_OP,
		XOR_ASSIGN_OP,
		OR_ASSIGN_OP
	};


	#include <cstdarg>

	int parse_opt = 0;

	int message (const std::string msg, ...)
	{
		int rv = 0;
		va_list args;
		char *format = (char *)msg.c_str();
		va_start(args, msg);
		if(parse_opt)
			rv = printf(format, args);
		va_end(args);
		return rv;
	}

%}

%union {
	struct {
		union 
		{
			char cval;
			long int ival;
			double dval;
			char *str;
			char *name;
		};
		int type;
	} token;
	VAR_DATA *id_data; // Datos de identificador
	std::list < VAR_DATA *> *idlist;
	int scsp;
	int qual;
	int typsp;
	int op;
	int typ;
	int asop;
	int instr;
	std::list<int> *sqlist;
	VAR_DATA sym; /* Para poner datos sobre una variable ya declarada */
	struct {
		int typq;
		int level;
	} pstruc;
	struct {
		std::list<int> *breaklist;          /* Para salto fuera de un switch */
		std::list<int> *nextlist;           /* Para salto a siguiente instruccion */
		std::list<int> *continuelist;        /* Para salto a inicio de un ciclo  */
		std::list<GOTO_DATA *> *gotolist;   /* Para salto con GOTO */
		std::list<CASE_DATA *> *caselist;   /* Para saltos a los case de un switch */
	}lists;
}

%token <token.name> IDENTIFIER CONSTANT <token.str> STRING_LITERAL SIZEOF
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN



%nonassoc NO_ELSE
%nonassoc ELSE

%type <id_data> direct_declarator
%type <id_data> declarator
%type <id_data> init_declarator
%type <idlist> init_declarator_list
%type <scsp> storage_class_specifier
%type <sqlist> declaration_specifiers
%type <typsp> type_specifier 
%type <qual> type_qualifier
%type <sym> assignment_expression
%type <sym> expression
%type <sym> primary_expression
%type <sym> postfix_expression
%type <sym> unary_expression
%type <sym> cast_expression
%type <sym> multiplicative_expression
%type <sym> additive_expression
%type <sym> shift_expression
%type <sym> relational_expression
%type <sym> equality_expression 
%type <sym> and_expression
%type <sym> exclusive_or_expression
%type <sym> inclusive_or_expression
%type <sym> logical_and_expression
%type <sym> logical_or_expression
%type <sym> conditional_expression
%type <sym> initializer
%type <idlist> parameter_type_list
%type <idlist> parameter_list
%type <sym> parameter_declaration
%type <sym> argument_expression_list
%type <pstruc> pointer
%type <qual> type_qualifier_list
%type <op> unary_operator
%type <typ> type_name
%type <sqlist> specifier_qualifier_list
%type <asop> assignment_operator
%type <sym> constant_expression
%type <lists> jump_statement
%type <lists> statement
%type <lists> labeled_statement
%type <lists> compound_statement
%type <lists> selection_statement
%type <lists> iteration_statement
%type <lists> statement_list
%type <sym> expression_statement
%type <instr> N
%type <lists> M 
%type <sym> logic_expression
%type <sym> logic_expression_statement
%start translation_unit
%%

primary_expression
	: IDENTIFIER				{
									string *name = new string($1); /* El nombre es el atributo id del token IDENTIFIER */
									symrec *s = getsym(name);
									if(s == NULL)
									{
										message("Variable %s", $1);
										yyerror("not declared!");
									}
									printf("primary_expression: IDENTIFIER");
									cout << "<" << *name << ">" << "\n";
									$$.var = s; /* La variable de la tabla de simbolos que se encontro con getsym() */
									$$.typ = s->typ; /* el tipo se obtuvo de la tabla de simbolos */
									$$.dimlist = s->dimlist;
									$$.plevel = 0;
								}
	| CONSTANT					{
									symrec *s;
									std::string *name;
									printf("primary_expression: CONSTANT");
									switch($<token.type>1)
									{
										case DOUBLEVAL:
											cout << "<(double)" << $<token.dval>1 << ">" << "\n";
											name = newtemp(); /* Crear nueva variable temporal */
											s = putsym(name, DOUBLEVAL | CONST_SPEC);
											$$.val.doubleval = $<token.dval>1;
											*(double *)(datablock+s->offset) = $<token.dval>1;
											$$.typ = s->typ;
											$$.var = s;
											break;
										case INTVAL:
											cout << "<(int)" << $<token.ival>1 << ">" << "\n";
											name = newtemp(); /* Crear nueva variable temporal */
											s = putsym(name, INTVAL | CONST_SPEC);
											$$.val.intval = $<token.ival>1;
											*(int *)(datablock+s->offset) = $<token.ival>1;
											$$.typ = s->typ;
											$$.var = s;
											break;
										case CHARVAL:
											cout << "<(char)" << $<token.cval>1 << ">" << "\n";
											name = newtemp(); /* Crear nueva variable temporal */
											s = putsym(name, CHARVAL | CONST_SPEC);
											$$.val.charval = $<token.cval>1;
											*(char *)(datablock+s->offset) = $<token.cval>1;
											$$.typ = s->typ;
											$$.var = s;
											break;
									}
								}
	| STRING_LITERAL			{
									symrec *s;
									std::string *name;
									string *str = new string($1);
									printf("primary_expression: STRING_LITERAL");
									cout << "<\"" << *str << ">\"" << "\n";
									/* Crear variable temporal para guardar cadena */
									name = newtemp();
									/* Agrefa variable temporal a tabla de simbolos */
									s = putsym(name, STRVAL | CONST_SPEC);
									/* DETERMINA TAMAÑO DE CADENA */
									s->size + strlen($1)+1;
									/* Copia cadena a bloque de datos datablock */
									memcpy(datablock+s->offset, $1, s->size);
									/* Incrementar valor de posicion libre en bloque datos */
									data_location(s->size);
									/* Propagar atributos de variables temporal al nodo padre primary_expression */
									$$.name = name;
									$$.typ = s->typ;
									$$.var = s;
								}
	| '(' expression ')'		{
									printf("primary_expression: '(' expression ')'\n");
									$$ = $2;
								}
	;

postfix_expression
	: primary_expression										{
																	printf("postfix_expression: primary_expression\n");
																	$$ = $1;
																}
	| postfix_expression '[' expression ']'						{
																	printf("postfix_expression: postfix_expression '[' expression ']'\n");
																	$$ = $1;
																	if($1.var == NULL)
																		yyerror("Error: Array name must be specified");
																	if(!isintegral($3.typ))
																		yyerror("Array subscript mus be integral!\n");
																	if($1.plevel > 0)
																	{
																		string *name = newtemp(); /* para sizeof(type) */
																		symrec *s0 = putsym(name, INTVAL | CONST_SPEC);
																		*(int *) (datablock+s0->offset) = getsizeof($$.typ);
																		name = newtemp(); /* para dimension N */
																		symrec *s1 = putsym(name, INTVAL | CONST_SPEC);
																		*(int *) (datablock+s1->offset) = getrdim($$.dimlist, $1.plevel - 1);
																		name = newtemp(); /* para resultado de j*sizeof (type) */
																		symrec *s2 = putsym(name, INTVAL | VAR_SPEC);
																		gencode(MULT_IR, $3.var, s0, s2);
																		name = newtemp(); /* para offset_ant * N */
																		symrec *s3 = putsym(name, INTVAL | VAR_SPEC);
																		gencode(MULT_IR, $$.var2, s1, s3);
																		name = newtemp(); /* para calcular offset */
																		symrec *s4 = putsym(name, INTVAL | VAR_SPEC);
																		gencode(ADD_IR, s3, s2, s4);
																		$$.var2 = s4;
																	}
																	else
																	{
																		string *name = newtemp();
																		symrec *s1 = putsym(name, INTVAL | CONST_SPEC);
																		*(int *)(datablock+s1->offset) = getsizeof($$.typ);
																		name = newtemp();
																		symrec *s2 = putsym(name, INTVAL | VAR_SPEC);
																		gencode(MULT_IR, $3.var, s1, s2);
																		$$.var2 = s2;
																	}
																	//message ("$$.var = %p\n", $$.var);
																	//message ("$$.var2 = %p\n", $$.var2);
																	$$.typ |= ARRAY_SPEC;
																	$$.plevel++;	
																}
	| postfix_expression '(' ')'								{
																	symrec *s;
																	std::string *name = newtemp();
																	printf("postfix_expression: postfix_expression '(' ')'\n");
																	s = putsym(name, $1.typ & 0x1F);
																	$$.typ = s->typ;
																	gencode(CALL_IR, $1.var, nullptr, s);
																	$$.var = s;
																}
	| postfix_expression '(' argument_expression_list ')'		{
																	printf("postfix_expression: postfix_expression '(' argument_expression_list ')'\n");
																	symrec *s, *s2, *s3;
																	std::list<VAR_DATA *>::reverse_iterator it;
																	std::string *name = newtemp();
																	s = putsym(name, $1.typ & 0x1F);
																	$$.typ = s->typ;
																	for(it = $3.arglist->rbegin(); it != $3.arglist->rend(); it++)
																	{
																		gencode(PARAM_IR, (*it)->var, nullptr, nullptr);
																	}
																	s3 = new symrec();
																	s3 -> name = "";
																	s3 -> offset = $3.arglist->size();
																	gencode(CALL_IR, $1.var, s3, s);
																	$$.var = s;	
																}
	| postfix_expression '.' IDENTIFIER							{printf("postfix_expression: postfix_expression '.' IDENTIFIER\n");}
	| postfix_expression PTR_OP IDENTIFIER						{printf("postfix_expression: postfix_expression PTR_OP IDENTIFIER\n");}
	| postfix_expression INC_OP									{
																	printf("postfix_expression: postfix_expression INC_OP	\n");
																	if($1.typ & VAR_SPEC)
																	{
																		/* Crear variables temporal para guardar valor de postfix_expression antes de incremento */
																		std::string *name = newtemp();
																		symrec *s;
																		/* Agregar variable temporal a tabla de simbolos */
																		s = putsym(name, $1.typ);
																		/* Generar instruccion de codigo intermedio para asignacion */
																		gencode(STORE_IR, $1.var, nullptr, s);
																		gencode(INC_IR, $1.var, nullptr, $1.var);
																		$$.name = name;
																		$$.typ = $1.typ;
																		$$.var = s;
																	}
																	else
																		yyerror("Error: Operand of increment operator must be an variable\n");

																}
	| postfix_expression DEC_OP									{
																	printf("postfix_expression: postfix_expression DEC_OP\n");
																	if($1.typ & VAR_SPEC)
																	{
																		/* Crear variables temporal para guardar valor de postfix_expression antes de incremento */
																		std::string *name = newtemp();
																		symrec *s;
																		/* Agregar variable temporal a tabla de simbolos */
																		s = putsym(name, $1.typ);
																		/* Generar instruccion de codigo intermedio para asignacion */
																		gencode(STORE_IR, $1.var, nullptr, s);
																		gencode(DEC_IR, $1.var, nullptr, $1.var);
																		$$.name = name;
																		$$.typ = $1.typ;
																		$$.var = s;
																		
																	}
																	else
																		yyerror("Error: Operand of increment operator must be an variable\n");
																}
	;

argument_expression_list
	: assignment_expression											{
																		printf("argument_expression_list: assignment_expression\n");
																		std::list<VAR_DATA * > *newlist = new std::list<VAR_DATA * >();
																		VAR_DATA * newstruc = new VAR_DATA();
																		*newstruc = $1;
																		newlist->push_back(newstruc);
																		$$.name = new std::string();
																		$$.typ = 0;
																		$$.arglist = newlist;
																	}
	| argument_expression_list ',' assignment_expression			{
																		printf("argument_expression_list: argument_expression_list ',' assignment_expression\n");
																		VAR_DATA * newstruc = new VAR_DATA();
																		*newstruc = $3;
																		$$ = $1;
																		$$.arglist->push_back(newstruc);
																	}
	;

unary_expression
	: postfix_expression					{
												printf("unary_expression: postfix_expression\n");
												$$ = $1;	
											}
	| INC_OP unary_expression				{
												printf("unary_expression: INC_OP unary_expression\n");
												if($2.typ & VAR_SPEC)
												{
													/* Generar instruccion de codigo intermedio para incremento */
													gencode(INC_IR, $2.var, nullptr, $2.var);
													/* Propagar atributos de variable temporal al nodo padre postfix_expression */
													$$.name = $2.name;
													$$.typ = $2.typ;
													$$.var = $2.var;
												}
												else
													yyerror("Error: Operand of increment operator must be an variable name\n");
											}
	| DEC_OP unary_expression				{
												printf("unary_expression: DEC_OP unary_expression\n");
												if($2.typ & VAR_SPEC)
												{
													/* Generar instruccion de codigo intermedio para incremento */
													gencode(DEC_IR, $2.var, nullptr, $2.var);
													/* Propagar atributos de variable temporal al nodo padre postfix_expression */
													$$.name = $2.name;
													$$.typ = $2.typ;
													$$.var = $2.var;
												}
												else
													yyerror("Error: Operand of increment operator must be an variable name\n");
											}
	| unary_operator cast_expression		{
												std::string *name;
												symrec *s;
												printf("unary_expression: unary_operator cast_expression\n");
												/* Generar instruccion de codigo intermedio */
												switch($1)
												{
													case PLUS_OP:
														name = $2.name;
														s = $2.var;
														$$.typ = $2.typ;
														break;
													case ADDR_OP:
														name = newtemp();
														s = putsym(name, INTVAL);
														gencode(ADDRESS_IR, $2.var, nullptr, s);
														$$.typ = INTVAL;
														break;
													case DEREF_OP:
														name = newtemp();
														if(!ispointer($2.typ))
															yyerror("Error: Operand must be a pointer\n");
														s = putsym(name, $2.typ & ~POINTER_SPEC);
														gencode(DEREF_IR, $2.var, nullptr, s);
														$$.typ = $2.typ;
														break;
													case MINUS_OP:
														name = newtemp();
														s = putsym(name, $2.typ);
														gencode(MINUS_IR, $2.var, nullptr, s);
														$$.typ = $2.typ;
														break;
													case TWOCOMP_OP:
														name = newtemp();
														s = putsym(name, INTVAL);
														gencode(TWOCOMP_IR, $2.var, nullptr, s);
														$$.typ = INTVAL;
														break;
													case NOT_OP:
														name = newtemp();
														/*s = putsym(name, INTVAL);
														gencode(NOT_IR, $2.var, nullptr, s);*/
														$$.truelist = $2.falselist;
														$$.falselist = $2.truelist;
														$$.typ = INTVAL;
														break;
												}
												$$.name = name;
												$$.var = s;	
											}
	| SIZEOF unary_expression				{
												printf("unary_expression: SIZEOF unary_expression\n");
												/* Crear variable temporal para guardar valor tamaño de unary_expression*/
												std::string *name = newtemp();
												symrec *s;
												/* Agregar variable temporal a tabla de simbolos */
												s = putsym(name, INTVAL | CONST_SPEC);
												/* Copiar tamaño de unary_espression en bloques de datos datablack */
												*(int *)(datablock+s->offset) = getsizeof($2.typ);
												/* Propagar atributos de postfix_expression al nodo padre unary_expression */
												$$.name = name;
												$$.typ = INTVAL | CONST_SPEC;
												$$.var = s;
											}
	| SIZEOF '(' type_name ')'				{
												printf("unary_expression: SIZEOF '(' type_name ')'\n");
												/* Crear variable temporal para guardar valor tamaño de unary_expression*/
												std::string *name = newtemp();
												symrec *s;
												/* Agregar variable temporal a tabla de simbolos */
												s = putsym(name, INTVAL | CONST_SPEC);
												/* Copiar tamaño de unary_espression en bloques de datos datablack */
												*(int *)(datablock+s->offset) = getsizeof($3);
												/* Propagar atributos de postfix_expression al nodo padre unary_expression */
												$$.name = name;
												$$.typ = INTVAL | CONST_SPEC;
												$$.var = s;
											}
	;

unary_operator
	: '&'									{
												printf("unary_operator: '&'\n");
												$$ = ADDR_OP;
											}
	| '*'									{
												printf("unary_operator: '*'\n");
												$$ = DEREF_OP;
											}
	| '+'									{
												printf("unary_operator: '+'\n");
												$$ = PLUS_OP;
											}
	| '-'									{
												printf("unary_operator: '-'\n");
												$$ = MINUS_OP;
											}
	| '~'									{
												printf("unary_operator: '~'\n");
												$$ = TWOCOMP_OP;
											}
	| '!'									{
												printf("unary_operator: '!'\n");
												$$ = NOT_OP;
											}
	;

cast_expression
	: unary_expression						{
												printf("cast_expression: unary_expression\n");
												$$ = $1;	
												if(isarray($1.typ))
												{
													std::string *name = newtemp();
													symrec *s;
													s = putsym(name, $1.typ & ~ARRAY_SPEC);
													gencode(LOADA_IR, $1.var, $1.var2, s);
													$$.name = name;
													//cout << "yar =" << *name << endl;
													$$.typ = s->typ;
													$$.var = s;
												}
											}
	| '(' type_name ')' cast_expression		{
												printf("cast_expression: '(' type_name ')' cast_expression\n");
												std::string *name = newtemp(); /* Crear nueva variable temporal para resultados */
												symrec *s;
												int typ = $2 & 0x1F;
												switch(typ)
												{
													case CHARVAL:
														s=putsym(name, CHARVAL | VAR_SPEC);
														gencode(CALL_IR, $4.var, NULL, s);
														break;
													case INTVAL:
														s=putsym(name, INTVAL | VAR_SPEC);
														gencode(INT_IR, $4.var, NULL, s);
														break;
													case FVAL:
														s=putsym(name, FVAL | VAR_SPEC);
														gencode(FLOAT_IR, $4.var, NULL, s);
														break;
													/*case DOUBLEVAL
														s=putsym(name, DOUBLEVAL | VAR_SPEC);
														gencode(DOUBLEVAL_IR, $4.var, NULL, s);
														break;*/
												}
												$$.name = name;
												$$.typ = s->typ;
												$$.var = s;	
											}
	;

multiplicative_expression
	: cast_expression										{
																printf("multiplicative_expression: cast_expression\n");
																$$ = $1;	
															}
	| multiplicative_expression '*' cast_expression			{
																printf("multiplicative_expression: multiplicative_expression '*' cast_expression\n");
																std::string *name = newtemp(); /* Crear nueva variable temporal para resultado*/
																symrec *s;
																s = putsym(name, gettype($1.typ, $3.typ) & ~CONST_SPEC | VAR_SPEC);/* Agregar variable temporal a tabla de simbolos */
																gencode(MULT_IR, $1.var, $3.var, s);/*Genera godigo intermedio de resta */
																$$.name = name;
																$$.var = s;	
															}	
	| multiplicative_expression '/' cast_expression			{
																printf("multiplicative_expression: multiplicative_expression '/' cast_expression\n");
																std::string *name = newtemp(); /* Crear nueva variable temporal para resultado*/
																symrec *s;
																s = putsym(name, gettype($1.typ, $3.typ) & ~CONST_SPEC | VAR_SPEC);/* Agregar variable temporal a tabla de simbolos */
																gencode(DIV_IR, $1.var, $3.var, s);/*Genera godigo intermedio de resta */
																$$.name = name;
																$$.var = s;
															}
	| multiplicative_expression '%' cast_expression			{
																printf("multiplicative_expression: multiplicative_expression '%%' cast_expression\n");
																std::string *name = newtemp(); /* Crear nueva variable temporal para resultado*/
																symrec *s;
																s = putsym(name, gettype($1.typ, $3.typ) & ~CONST_SPEC | VAR_SPEC);/* Agregar variable temporal a tabla de simbolos */
																gencode(MOD_IR, $1.var, $3.var, s);/*Genera godigo intermedio de resta */
																$$.name = name;
																$$.var = s;
															}
	;

additive_expression
	: multiplicative_expression								{
																printf("additive_expression: multiplicative_expression	\n");
																$$ = $1;	
															}
	| additive_expression '+' multiplicative_expression		{
																printf("additive_expression: additive_expression '+' multiplicative_expression\n");
																std::string *name = newtemp(); /* Crear nueva variable temporar para resultado */
																symrec *s;
																s = putsym(name, gettype($1.typ, $3.typ) & ~CONST_SPEC | VAR_SPEC);
																gencode(ADD_IR, $1.var, $3.var, s);
																$$.name = name;
																$$.var = s;
															}
	| additive_expression '-' multiplicative_expression		{
																printf("additive_expression: additive_expression '-' multiplicative_expression\n");
																std::string *name = newtemp(); /* Crear nueva variable temporar para resultado */
																symrec *s;
																s = putsym(name, gettype($1.typ, $3.typ) & ~CONST_SPEC | VAR_SPEC);
																gencode(SUB_IR, $1.var, $3.var, s);
																$$.name = name;
																$$.var = s;
															}
	;

shift_expression
	: additive_expression									{
																printf("shift_expression: additive_expression\n");
																$$ = $1;	
															}
	| shift_expression LEFT_OP additive_expression			{printf("shift_expression: shift_expression LEFT_OP additive_expression\n");}
	| shift_expression RIGHT_OP additive_expression			{printf("shift_expression: shift_expression RIGHT_OP additive_expression\n");}
	;

relational_expression
	: shift_expression										{
																printf("relational_expression: shift_expression\n");
																$$ = $1;	
															}
	| relational_expression '<' shift_expression			{
																printf("relational_expression: relational_expression '<' shift_expression\n");
																symrec *s1 = $1.var, *s2 = $3.var;
																$$.truelist = makelist(nextinstr);
																gencode(IF_LT_IR, s1, s2, nullptr);
																$$.falselist = makelist (nextinstr);
																gencode(GOTO_IR);
															}
	| relational_expression '>' shift_expression			{
																printf("relational_expression: relational_expression '>' shift_expression\n");
																symrec *s1 = $1.var, *s2 = $3.var;
																$$.truelist = makelist(nextinstr);
																gencode(IF_GT_IR, s1, s2, nullptr);
																$$.falselist = makelist (nextinstr);
																gencode(GOTO_IR);
															}
	| relational_expression LE_OP shift_expression			{
																printf("relational_expression: relational_expression LE_OP shift_expression\n");
																symrec *s1 = $1.var, *s2 = $3.var;
																$$.truelist = makelist(nextinstr);
																gencode(IF_LE_IR, s1, s2, nullptr);
																$$.falselist = makelist (nextinstr);
																gencode(GOTO_IR);
															}
	| relational_expression GE_OP shift_expression			{
																printf("relational_expression: relational_expression GE_OP shift_expression\n");
																symrec *s1 = $1.var, *s2 = $3.var;
																$$.truelist = makelist(nextinstr);
																gencode(IF_GE_IR, s1, s2, nullptr);
																$$.falselist = makelist (nextinstr);
																gencode(GOTO_IR);
															}
	;

equality_expression
	: relational_expression									{
																printf("equality_expression: relational_expression	\n");
																$$ = $1;
															}
	| equality_expression EQ_OP relational_expression		{
																printf("equality_expression: equality_expression EQ_OP relational_expression\n");
																symrec *s1 = $1.var, *s2 = $3.var;
																$$.truelist = makelist(nextinstr);
																gencode(IF_EQ_IR, s1, s2, nullptr);
																$$.falselist = makelist (nextinstr);
																gencode(GOTO_IR);
															}
	| equality_expression NE_OP relational_expression		{
																printf("equality_expression: equality_expression NE_OP relational_expression\n");
																symrec *s1 = $1.var, *s2 = $3.var;
																$$.truelist = makelist(nextinstr);
																gencode(IF_NE_IR, s1, s2, nullptr);
																$$.falselist = makelist (nextinstr);
																gencode(GOTO_IR);
															}
	;

and_expression
	: equality_expression									{
																printf("and_expression: equality_expression\n");
																$$ = $1;
															}
	| and_expression '&' equality_expression				{
																printf("and_expression: and_expression '&' equality_expression\n");
																std::string *name = newtemp(); /* Crear nueva variable temporal para resultados */
																symrec *s;
																s = putsym(name, gettype($1.typ, $3.typ) & ~CONST_SPEC | VAR_SPEC);
																gencode(AND_IR, $1.var, $3.var, s);
																$$.name = name;
																$$.var = s;
															}
	;

exclusive_or_expression
	: and_expression										{
																printf("exclusive_or_expression: and_expression\n");
																$$ = $1;	
															}
	| exclusive_or_expression '^' and_expression			{
																printf("exclusive_or_expression: exclusive_or_expression '^' and_expression\n");
																std::string *name = newtemp(); /* Crear nueva variable temporal para resultados */
																symrec *s;
																s = putsym(name, gettype($1.typ, $3.typ) & ~CONST_SPEC | VAR_SPEC);
																gencode(XOR_IR, $1.var, $3.var, s);
																$$.name = name;
																$$.var = s;
															}
	;

inclusive_or_expression
	: exclusive_or_expression								{
																printf("inclusive_or_expression: exclusive_or_expression\n");
																$$ = $1;	
															}
	| inclusive_or_expression '|' exclusive_or_expression	{
																printf("inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression\n");
																std::string *name = newtemp(); /* Crear nueva variable temporal para resultados */
																symrec *s;
																s = putsym(name, gettype($1.typ, $3.typ) & ~CONST_SPEC | VAR_SPEC);
																gencode(OR_IR, $1.var, $3.var, s);
																$$.name = name;
																$$.var = s;
															}
	;

logical_and_expression
	: inclusive_or_expression								{
																printf("logical_and_expression: inclusive_or_expression	\n");
																$$ = $1;	
															}
	| logical_and_expression AND_OP N inclusive_or_expression	{
																	printf("logical_and_expression: logical_and_expression AND_OP inclusive_or_expression\n");
																	backpatch($1.truelist, $3);
																	$$.truelist = $4.truelist;
																	$$.falselist = $1.falselist;
																	$$.falselist->merge(*($4.falselist));
																	$$.typ = INTVAL;
																}
	;


logical_or_expression
	: logical_and_expression								{
																printf("logical_or_expression: logical_and_expression	\n");
																$$ = $1;	
															}
	| logical_or_expression OR_OP N logical_and_expression	{
																printf("logical_or_expression: logical_or_expression OR_OP logical_and_expression\n");
																backpatch($1.falselist, $3);
																$$.falselist = $4.falselist;
																$$.truelist = $1.truelist;
																$$.truelist->merge(*($4.truelist));
																$$.typ = INTVAL;
															}
	;
M:	/* Empty */												{ /* Agrega direccion de siguiente instruccion de IR en atributo nextlist y generar instruccion de salto pendiente*/
																$$.nextlist = makelist(nextinstr);
																gencode(GOTO_IR);
															}
conditional_expression
	: logical_or_expression													{
																				printf("conditional_expression: logical_or_expression	\n");
																				$$ = $1;
																			}
	| logical_or_expression '?' N expression ':' 							{
																				string *name = newtemp();
																				symrec *s = putsym(name, $4.typ & ~CONST_SPEC | VAR_SPEC);
																				gencode(STORE_IR, $4.var, NULL, s);
																				$4.var = s;
																			}
	
	M N conditional_expression												{
																				//printf("conditional_expression: logical_or_expression '?' expression ':' conditional_expression\n");
																				gencode(STORE_IR, $9.var, NULL, $4.var);
																				$$.var = $4.var;
																				backpatch($1.truelist, $3);
																				backpatch($1.falselist, $8);
																				backpatch($7.nextlist, nextinstr);
																				$$.truelist = nullptr;
																				$$.falselist = nullptr;	
																			}
	;

assignment_expression
	: conditional_expression										{
																		printf("assignment_expression: conditional_expression\n");
																		$$ = $1;
																	}
	| unary_expression assignment_operator assignment_expression	{
																		printf("assignment_expression: unary_expression assignment_operator assignment_expression\n");
																		/* Verificar si hay saltos pendientes en assignment_expression
																			si los hay, asignar el valor logico 0 o 1.
																		*/
																		if($3.truelist || $3.falselist)
																		{
																			std::string *name = newtemp(); /* Nueva variable temporal */
																			symrec *s1, *s0;
																			s0 = putsym(name, INTVAL | CONST_SPEC);
																			*(int *)(datablock+s0->offset) = 0;
																			name = newtemp();
																			s1 = putsym(name, INTVAL | CONST_SPEC);
																			*(int *)(datablock+s1->offset) = 1;
																			name = newtemp();
																			$3.var = putsym(name, INTVAL | CONST_SPEC);
																			$3.typ = INTVAL | VAR_SPEC;
																			$3.name = name;
																			backpatch($3.truelist, nextinstr);
																			gencode(STORE_IR, s1, nullptr, $3.var);
																			gencode(GOTO_IR, nullptr, nullptr, nextinstr+2);
																			backpatch($3.falselist, nextinstr);
																			gencode(STORE_IR, s0, nullptr, $3.var);
																		}	
																		/* Comparar el atributo de assignment_operator ($2) */
																		switch($2)
																		{
																			case EQ_ASSIGN_OP:
																				if(!isarray($1.typ))
																					gencode(STORE_IR, $3.var, nullptr, $1.var);
																				else
																					gencode(STORE_IR, $3.var, $1.var2, $1.var);
																				break;
																			case MUL_ASSIGN_OP:
																				if(!isarray($1.typ))
																				{
																					std::string *name = newtemp(); /* Crear nueva variable temporal para resultado*/
																					symrec *s;
																					s = putsym(name, gettype($1.typ, $3.typ) & ~CONST_SPEC | VAR_SPEC);
																					gencode(MULT_IR, $1.var, $3.var, s);
																					gencode(STORE_IR, s, nullptr, $1.var);
																				}
																				else
																				{
																					std::string *name = newtemp();
																					std::string *name1 = newtemp(); /* Crear nueva variable temporal para resultado*/
																					symrec *s , *result;
																					s = putsym(name, $1.typ & ~ARRAY_SPEC | VAR_SPEC);
																					result = putsym(name1, gettype($1.typ, $3.typ) & ~ARRAY_SPEC | VAR_SPEC);
																					gencode(LOADA_IR, $1.var, $1.var2, s);
																					gencode(MULT_IR, s, $3.var, result);
																					gencode(STORE_IR, result, $1.var2, $1.var);
																				}
																				break;
																			case DIV_ASSIGN_OP:
																				if(!isarray($1.typ))
																				{
																					std::string *name = newtemp(); /* Crear nueva variable temporal para resultados */
																					symrec *s;
																					s = putsym(name, gettype($1.typ, $3.typ) & ~CONST_SPEC | VAR_SPEC);
																					gencode(DIV_IR, $1.var, $3.var, s);
																					gencode(STORE_IR, s, nullptr, $1.var);
																				}
																				else
																				{
																					std::string *name = newtemp();
																					std::string *name1 = newtemp(); /* Crear nueva variable temporal para resultado*/
																					symrec *s , *result;
																					s = putsym(name, $1.typ & ~ARRAY_SPEC | VAR_SPEC);
																					result = putsym(name1, gettype($1.typ, $3.typ) & ~ARRAY_SPEC | VAR_SPEC);
																					gencode(LOADA_IR, $1.var, $1.var2, s);
																					gencode(DIV_IR, s, $3.var, result);
																					gencode(STORE_IR, result, $1.var2, $1.var);
																				}
																				break;
																			case MOD_ASSIGN_OP:
																				if(!isarray($1.typ))
																				{
																					std::string *name = newtemp(); /* Crear nueva variable temporal para resultados */
																					symrec *s;
																					s = putsym(name, gettype($1.typ, $3.typ) & ~CONST_SPEC | VAR_SPEC);
																					gencode(MOD_IR, $1.var, $3.var, s);
																					gencode(STORE_IR, s, nullptr, $1.var);
																				}
																				else
																				{
																					std::string *name = newtemp();
																					std::string *name1 = newtemp(); /* Crear nueva variable temporal para resultado*/
																					symrec *s , *result;
																					s = putsym(name, $1.typ & ~ARRAY_SPEC | VAR_SPEC);
																					result = putsym(name1, gettype($1.typ, $3.typ) & ~ARRAY_SPEC | VAR_SPEC);
																					gencode(LOADA_IR, $1.var, $1.var2, s);
																					gencode(MOD_IR, s, $3.var, result);
																					gencode(STORE_IR, result, $1.var2, $1.var);
																				}
																				break;
																			case ADD_ASSIGN_OP:
																				if(!isarray($1.typ))
																				{
																					std::string *name = newtemp(); /* Crear nueva variable temporal para resultados */
																					symrec *s;
																					s = putsym(name, gettype($1.typ, $3.typ) & ~CONST_SPEC | VAR_SPEC);
																					gencode(ADD_IR, $1.var, $3.var, s);
																					gencode(STORE_IR, s, nullptr, $1.var);
																				}
																				else
																				{
																					std::string *name = newtemp();
																					std::string *name1 = newtemp(); /* Crear nueva variable temporal para resultado*/
																					symrec *s , *result;
																					s = putsym(name, $1.typ & ~ARRAY_SPEC | VAR_SPEC);
																					result = putsym(name1, gettype($1.typ, $3.typ) & ~ARRAY_SPEC | VAR_SPEC);
																					gencode(LOADA_IR, $1.var, $1.var2, s);
																					gencode(ADD_IR, s, $3.var, result);
																					gencode(STORE_IR, result, $1.var2, $1.var);
																				}
																				break;
																			case SUB_ASSIGN_OP:
																				if(!isarray($1.typ))
																				{
																					std::string *name = newtemp(); /* Crear nueva variable temporal para resultados */
																					symrec *s;
																					s = putsym(name, gettype($1.typ, $3.typ) & ~CONST_SPEC | VAR_SPEC);
																					gencode(SUB_IR, $1.var, $3.var, s);
																					gencode(STORE_IR, s, nullptr, $1.var);
																				}
																				else
																				{
																					std::string *name = newtemp();
																					std::string *name1 = newtemp(); /* Crear nueva variable temporal para resultado*/
																					symrec *s , *result;
																					s = putsym(name, $1.typ & ~ARRAY_SPEC | VAR_SPEC);
																					result = putsym(name1, gettype($1.typ, $3.typ) & ~ARRAY_SPEC | VAR_SPEC);
																					gencode(LOADA_IR, $1.var, $1.var2, s);
																					gencode(SUB_IR, s, $3.var, result);
																					gencode(STORE_IR, result, $1.var2, $1.var);
																				}
																				break;
																			case LEFT_ASSIGN_OP:
																				if(!isarray($1.typ))
																				{
																					std::string *name = newtemp(); /* Crear nueva variable temporal para resultados */
																					symrec *s;
																					s = putsym(name, gettype($1.typ, $3.typ) & ~CONST_SPEC | VAR_SPEC);
																					gencode(LSHIFT_IR, $1.var, $3.var, s);
																					gencode(STORE_IR, s, nullptr, $1.var);
																				}
																				else
																				{
																					std::string *name = newtemp();
																					std::string *name1 = newtemp(); /* Crear nueva variable temporal para resultado*/
																					symrec *s , *result;
																					s = putsym(name, $1.typ & ~ARRAY_SPEC | VAR_SPEC);
																					result = putsym(name1, gettype($1.typ, $3.typ) & ~ARRAY_SPEC | VAR_SPEC);
																					gencode(LOADA_IR, $1.var, $1.var2, s);
																					gencode(LSHIFT_IR, s, $3.var, result);
																					gencode(STORE_IR, result, $1.var2, $1.var);
																				}
																				break;
																			case RIGHT_ASSIGN_OP:
																				if(!isarray($1.typ))
																				{
																					std::string *name = newtemp(); /* Crear nueva variable temporal para resultados */
																					symrec *s;
																					s = putsym(name, gettype($1.typ, $3.typ) & ~CONST_SPEC | VAR_SPEC);
																					gencode(RSHIFT_IR, $1.var, $3.var, s);
																					gencode(STORE_IR, s, nullptr, $1.var);
																				}
																				else
																				{
																					std::string *name = newtemp();
																					std::string *name1 = newtemp(); /* Crear nueva variable temporal para resultado*/
																					symrec *s , *result;
																					s = putsym(name, $1.typ & ~ARRAY_SPEC | VAR_SPEC);
																					result = putsym(name1, gettype($1.typ, $3.typ) & ~ARRAY_SPEC | VAR_SPEC);
																					gencode(LOADA_IR, $1.var, $1.var2, s);
																					gencode(LSHIFT_IR, s, $3.var, result);
																					gencode(STORE_IR, result, $1.var2, $1.var);
																				}
																				break;
																			case AND_ASSIGN_OP:
																				if(!isarray($1.typ))
																				{
																					std::string *name = newtemp(); /* Crear nueva variable temporal para resultados */
																					symrec *s;
																					s = putsym(name, gettype($1.typ, $3.typ) & ~CONST_SPEC | VAR_SPEC);
																					gencode(AND_IR, $1.var, $3.var, s);
																					gencode(STORE_IR, s, nullptr, $1.var);
																				}
																				else
																				{
																					std::string *name = newtemp();
																					std::string *name1 = newtemp(); /* Crear nueva variable temporal para resultado*/
																					symrec *s , *result;
																					s = putsym(name, $1.typ & ~ARRAY_SPEC | VAR_SPEC);
																					result = putsym(name1, gettype($1.typ, $3.typ) & ~ARRAY_SPEC | VAR_SPEC);
																					gencode(LOADA_IR, $1.var, $1.var2, s);
																					gencode(AND_IR, s, $3.var, result);
																					gencode(STORE_IR, result, $1.var2, $1.var);
																				}
																				break;
																			case XOR_ASSIGN_OP:
																				if(!isarray($1.typ))
																				{
																					std::string *name = newtemp(); /* Crear nueva variable temporal para resultados */
																					symrec *s;
																					s = putsym(name, gettype($1.typ, $3.typ) & ~CONST_SPEC | VAR_SPEC);
																					gencode(XOR_IR, $1.var, $3.var, s);
																					gencode(STORE_IR, s, nullptr, $1.var);
																				}
																				else
																				{
																					std::string *name = newtemp();
																					std::string *name1 = newtemp(); /* Crear nueva variable temporal para resultado*/
																					symrec *s , *result;
																					s = putsym(name, $1.typ & ~ARRAY_SPEC | VAR_SPEC);
																					result = putsym(name1, gettype($1.typ, $3.typ) & ~ARRAY_SPEC | VAR_SPEC);
																					gencode(LOADA_IR, $1.var, $1.var2, s);
																					gencode(XOR_IR, s, $3.var, result);
																					gencode(STORE_IR, result, $1.var2, $1.var);
																				}
																				break;
																			case OR_ASSIGN_OP:
																				if(!isarray($1.typ))
																				{
																					std::string *name = newtemp(); /* Crear nueva variable temporal para resultados */
																					symrec *s;
																					s = putsym(name, gettype($1.typ, $3.typ) & ~CONST_SPEC | VAR_SPEC);
																					gencode(OR_IR, $1.var, $3.var, s);
																					gencode(STORE_IR, s, nullptr, $1.var);
																				}
																				else
																				{
																					std::string *name = newtemp();
																					std::string *name1 = newtemp(); /* Crear nueva variable temporal para resultado*/
																					symrec *s , *result;
																					s = putsym(name, $1.typ & ~ARRAY_SPEC | VAR_SPEC);
																					result = putsym(name1, gettype($1.typ, $3.typ) & ~ARRAY_SPEC | VAR_SPEC);
																					gencode(LOADA_IR, $1.var, $1.var2, s);
																					gencode(OR_IR, s, $3.var, result);
																					gencode(STORE_IR, result, $1.var2, $1.var);
																				}
																				break;
																		}	
																	}
	;

assignment_operator
	: '='					{
								printf("assignment_operator: '='\n");
								$$ = EQ_ASSIGN_OP;
							}
	| MUL_ASSIGN			{
								printf("assignment_operator: MUL_ASSIGN\n");
								$$ = MUL_ASSIGN_OP;
							}
	| DIV_ASSIGN			{	
								printf("assignment_operator: DIV_ASSIGN\n");
								$$ = DIV_ASSIGN_OP;
							}
	| MOD_ASSIGN			{
								printf("assignment_operator: MOD_ASSIGN\n");
								$$ = MOD_ASSIGN_OP;
							}
	| ADD_ASSIGN			{
								printf("assignment_operator: ADD_ASSIGN\n");
								$$ = ADD_ASSIGN_OP;
							}
	| SUB_ASSIGN			{
								printf("assignment_operator: SUB_ASSIGN\n");
								$$ = SUB_ASSIGN_OP;
							}
	| LEFT_ASSIGN			{
								printf("assignment_operator: LEFT_ASSIGN\n");
								$$ = LEFT_ASSIGN_OP;
							}
	| RIGHT_ASSIGN			{
								printf("assignment_operator: RIGHT_ASSIGN\n");
								$$ = RIGHT_ASSIGN_OP;
							}
	| AND_ASSIGN			{
								printf("assignment_operator: AND_ASSIGN\n");
								$$ = AND_ASSIGN_OP;
							}
	| XOR_ASSIGN			{
								printf("assignment_operator: XOR_ASSIGN\n");
								$$ = XOR_ASSIGN_OP;
							}
	| OR_ASSIGN				{
								printf("assignment_operator: OR_ASSIGN	\n");
								$$ = OR_ASSIGN_OP;
							}
	;

expression
	: assignment_expression						{
													printf("expression: assignment_expression\n");
													$$ = $1;
												}
	| expression ',' assignment_expression		{
													printf("expression: expression ',' assignment_expression\n");
													$$ = $1;
												}
	;

constant_expression	
	: conditional_expression					{
													printf("assignment_operator: conditional_expression\n");
													$$ = $1;	
												}
	;

declaration
	: declaration_specifiers ';'							{printf("declaration: declaration_specifiers ';'\n");}
	| declaration_specifiers init_declarator_list ';'		{
																int typ;
																printf("declaration: declaration_specifiers init_declarator_list ';'\n");
																std::list<VAR_DATA *>::iterator it;
																typ = get_type($1);
																//cout << "Declaring variables: "<<endl;
																for(it = $2->begin(); it != $2 -> end(); it++)
																{
																	symrec *s;
																	//cout << *(*it)->name <<endl;
																	if(isarray((*it)->typ))
																		installarray((*it)->name, typ | VAR_SPEC | ((*it)->typ & ~0x1F), (*it)->dimlist);
																	else
																		if(isfunction((*it)->typ))
																			s=install((*it)->name, typ | FUNC_SPEC | ((*it)->typ & ~0x1F));
																		else 
																		{
																			s=install((*it)->name, typ | VAR_SPEC | ((*it)->typ & ~0x1F));
																			if ((*it) -> init)
																			{
																				if(currscope > 0) /* Verifica que sea variable local */
																					gencode(STORE_IR, (*it)->var, nullptr, s);
																				else{
																					initvar(s, (*it)->var);
																				}
																			}
																		}
																}

															}
	;

declaration_specifiers
	: storage_class_specifier								{
																list<int> *newlist = new list<int>; 
																printf("declaration_specifiers: storage_class_specifier\n");
																newlist->push_back($1);
																$$=newlist;
															}
	| storage_class_specifier declaration_specifiers		{	
																printf("declaration_specifiers: storage_class_specifier declaration_specifiers\n");
																$$ = $2;
																$$->push_back($1);
															}
	| type_specifier										{
																list<int> *newlist = new list<int>;
																printf("declaration_specifiers: type_specifier\n");
																newlist->push_back($1);
																$$=newlist;
															}
	| type_specifier declaration_specifiers					{
																printf("declaration_specifiers: type_specifier declaration_specifiers\n");
																$$ = $2;
																$$->push_back($1);
															}
	| type_qualifier										{
																list<int> *newlist = new list<int>;
																printf("declaration_specifiers: type_qualifier\n");
																newlist->push_back($1);
																$$=newlist;
															}
	| type_qualifier declaration_specifiers					{
																printf("declaration_specifiers: type_qualifier declaration_specifiers\n");
																$$ = $2;
																$$->push_back($1);
															}
	;

init_declarator_list
	: init_declarator								{
														std::list<VAR_DATA *> *newlist = new std::list<VAR_DATA *>;
														VAR_DATA *newstruc = $1;
														printf("init_declarator_list: init_declarator	\n");
														newlist->push_back(newstruc);
														$$ = newlist;
													}
	| init_declarator_list ',' init_declarator		{
														printf("init_declarator_list: init_declarator_list ',' init_declarator\n");
														$$=$1;
														$$->push_back($3);
													}
	;

init_declarator
	: declarator						{
											printf("init_declarator: declarator\n");
											$$ = $1;
										} 
	| declarator '=' initializer		{
											printf("init_declarator: declarator '=' initializer\n");
											$$ = $1;
											$$->init = 1;
											$$->var = $3.var;
										}
	;

storage_class_specifier
	: TYPEDEF					{
									printf("storage_class_specifier: TYPEDEF\n");
									$$=TYPEDEF_SPEC;
								}
	| EXTERN					{
									printf("storage_class_specifier: EXTERN\n");
									$$= EXTERN_SPEC;
								}
	| STATIC					{
									printf("storage_class_specifier: STATIC\n");
									$$ = STATIC_SPEC;
								}
	| AUTO						{	
									printf("storage_class_specifier: AUTO\n");
									$$ = AUTO_SPEC;
								}
	| REGISTER					{
									printf("storage_class_specifier: REGISTER\n");
									$$ = REGISTER_SPEC;
								}
	;

type_specifier
	: VOID							{
										printf("type_specifier: VOID\n");
										$$ = VOID_SPEC;
									}
	| CHAR							{
										printf("type_specifier: CHAR\n");
										$$ = CHAR_SPEC;
									}
	| SHORT							{
										printf("type_specifier: SHORT\n");
										$$ = SHORT_SPEC;
									}
	| INT							{
										printf("type_specifier: INT\n");
										$$ = INT_SPEC;
									}
	| LONG							{
										printf("type_specifier: LONG\n");
										$$ = LONG_SPEC;
									}
	| FLOAT							{
										printf("type_specifier: FLOAT\n");
										$$ = FLOAT_SPEC;
									}
	| DOUBLE						{
										printf("type_specifier: DOUBLE\n");
										$$ = DOUBLE_SPEC;
									}
	| SIGNED						{
										printf("type_specifier: SIGNED\n");
										$$ = SIGNED_SPEC;
									}
	| UNSIGNED						{
										printf("type_specifier: UNSIGNED\n");
										$$ = UNSIGNED_SPEC;
									}
	| struct_or_union_specifier		{
										printf("type_specifier: struct_or_union_specifier\n");
										
									}
	| enum_specifier				{
										printf("type_specifier: enum_specifier\n");
										$$ = ENUM_SPEC;
									}
	| TYPE_NAME						{
										printf("type_specifier: TYPE_NAME\n");
										$$ = TYPENAME_SPEC;
									}
	;

struct_or_union_specifier
	: struct_or_union IDENTIFIER '{' struct_declaration_list '}'	{printf("struct_or_union_specifier: struct_or_union IDENTIFIER '{' struct_declaration_list '}'\n");}
	| struct_or_union '{' struct_declaration_list '}'				{printf("struct_or_union_specifier: struct_or_union '{' struct_declaration_list '}'	\n");}
	| struct_or_union IDENTIFIER									{printf("struct_or_union_specifier: struct_or_union IDENTIFIER\n");}
	;

struct_or_union
	: STRUCT														{printf("struct_or_union_specifier: STRUCT\n");}
	| UNION															{printf("struct_or_union_specifier: UNION\n");}
	;

struct_declaration_list
	: struct_declaration											{printf("struct_declaration_list: struct_declaration\n");}
	| struct_declaration_list struct_declaration					{printf("struct_declaration_list: struct_declaration_list struct_declaration\n");}
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';'			{printf("struct_declaration: specifier_qualifier_list struct_declarator_list ';'\n");}
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list						{
																		printf("specifier_qualifier_list: type_specifier specifier_qualifier_list\n");
																		$$=$2;
																		$$->push_back($1);
																	}
	| type_specifier												{
																		printf("specifier_qualifier_list: type_specifier\n");
																		std::list<int> *newlist = new std::list<int>;
																		newlist->push_back($1);
																		$$ = newlist;
																	}
	| type_qualifier specifier_qualifier_list						{
																		printf("specifier_qualifier_list: type_qualifier specifier_qualifier_list\n");
																		$$ = $2;
																		$$->push_back($1);
																	}
	| type_qualifier												{
																		printf("specifier_qualifier_list: type_qualifier\n");
																		std::list<int> *newlist = new std::list<int>;
																		newlist->push_back($1);
																		$$ = newlist;
																	}
	;

struct_declarator_list
	: struct_declarator												{printf("struct_declarator_list: struct_declarator\n");}
	| struct_declarator_list ',' struct_declarator					{printf("struct_declarator_list: struct_declarator_list ',' struct_declarator\n");}
	;

struct_declarator
	: declarator								{printf("struct_declarator: declarator\n");}
	| ':' constant_expression					{printf("struct_declarator: ':' constant_expression\n");}
	| declarator ':' constant_expression		{printf("struct_declarator: declarator ':' constant_expression\n");}
	;

enum_specifier
	: ENUM '{' enumerator_list '}'				{printf("enum_specifier: ENUM '{' enumerator_list '}'	\n");}
	| ENUM IDENTIFIER '{' enumerator_list '}'	{printf("enum_specifier: ENUM IDENTIFIER '{' enumerator_list '}'\n");}
	| ENUM IDENTIFIER							{printf("enum_specifier: ENUM IDENTIFIER\n");}
	;

enumerator_list
	: enumerator								{printf("enumerator_list: enumerator\n");}
	| enumerator_list ',' enumerator			{printf("enumerator_list: enumerator_list ',' enumerator\n");}	
	;

enumerator
	: IDENTIFIER								{printf("enumerator: IDENTIFIER\n");}
	| IDENTIFIER '=' constant_expression		{printf("enumerator: IDENTIFIER '=' constant_expression\n");}
	;

type_qualifier
	: CONST			{
						printf("type_qualifier: CONST\n");
						$$ = CONST_SPEC; 
					}
	| VOLATILE		{
						printf("type_qualifier: VOLATILE\n");
						$$ = VOLATILE_SPEC;
					}
	;

declarator
	: pointer direct_declarator			{
											printf("declarator: pointer direct_declarator\n");
											$$ = $2;
											$$->plevel = $1.level;
											$$->typ |= POINTER_SPEC | $1.typq;	
										}
	| direct_declarator					{
											printf("declarator: direct_declarator\n");
											$$ = $1;
											if(isarray($$->typ))
											{
												/* Arreglos sin dimensiones son punteros */
												if(allzero($$->dimlist))
												{
													$$->typ &= ~ARRAY_SPEC;
													$$->typ |= POINTER_SPEC;
												}
												else
												{
													if(product($$->dimlist)==0)
														yyerror("Array dimensions must be specified!");
												}
											}
										}
	;

direct_declarator
	: IDENTIFIER										{
															string *name = new string($1); /* El nombre es el atributo id del token IDENTIFIER */
															printf("direct_declarator: IDENTIFIER");
															cout << "<" << *name << ">" << "\n";
															VAR_DATA *newsym = new VAR_DATA();
															newsym->name = new string($1);
															newsym->dimlist = nullptr;
															$$ = newsym;
														}
	| '(' declarator ')'								{
															printf("direct_declarator: '(' declarator ')'\n");

														}
	| direct_declarator '[' constant_expression ']'		{
															printf("direct_declarator: direct_declarator '[' constant_expression ']'\n");
															if(!isintegral($3.typ))
																yyerror("Array dimension must be integral!");
															if(!isconstant($3.typ))
																yyerror("Array dimension must be constant!");
															$$ = $1;
															if($$->dimlist == nullptr)
																$$->dimlist = new list<int >;
															$$->dimlist->push_back($3.val.intval);
															$$->typ |= ARRAY_SPEC;	
														}
	| direct_declarator '[' ']'							{
															printf("direct_declarator: direct_declarator '[' ']'\n");
															$$ = $1;
															if($$->dimlist == nullptr)
																$$->dimlist = new list<int >;
															$$->dimlist->push_back(0);
															$$->typ |= ARRAY_SPEC;	
														}
	| direct_declarator '(' parameter_type_list ')'		{
															printf("direct_declarator: direct_declarator '(' parameter_type_list ')'\n");
															$$ = $1;
															$$->typ |= FUNC_SPEC;
															$$->arglist = $3;
															$$->init = 0;
														}
	| direct_declarator '(' identifier_list ')'			{printf("direct_declarator: direct_declarator '(' identifier_list ')'	\n");}
	| direct_declarator '(' ')'							{
															printf("direct_declarator: direct_declarator '(' ')'	\n");
															$$ = $1;
															$$->typ |= FUNC_SPEC;
															$$->init = 0;
														}
	;

pointer
	: '*'									{
												printf("pointer: '*'\n");
												$$.typq = 0;
												$$.level = 1;
											}
	| '*' type_qualifier_list				{
												printf("pointer: '*' type_qualifier_list\n");
												$$.typq = $2;
												$$.level = 1;	
											}
	| '*' pointer							{
												printf("pointer: '*' pointer\n");
												$$ = $2;
												$$.level++;	
											}
	| '*' type_qualifier_list pointer		{
												printf("pointer: '*' type_qualifier_list pointer\n");
												$$ = $3;
												$$.typq = $2;
												$$.level++;
											}
	;

type_qualifier_list
	: type_qualifier						{
												printf("type_qualifier_list: type_qualifier\n");
												$$ = $1;
											}
	| type_qualifier_list type_qualifier	{printf("type_qualifier_list: type_qualifier_list type_qualifier\n");
												$$ = $1;
												$$ |= $2;
											}
	;

parameter_type_list							
	: parameter_list							{
													printf("parameter_type_list: parameter_list\n");
													$$ = $1;	
												}
	| parameter_list ',' ELLIPSIS				{printf("parameter_type_list: parameter_list ',' ELLIPSIS\n");}
	;

parameter_list
	: parameter_declaration							{
														printf("parameter_list: parameter_declaration\n");
														std::list<VAR_DATA *> *newlist = new std::list<VAR_DATA *>;
														VAR_DATA *newstruc = new VAR_DATA();
														*newstruc = $1;
														newlist->push_back(newstruc);
														$$ = newlist;
													}
	| parameter_list ',' parameter_declaration		{	
														printf("parameter_list: parameter_list ',' parameter_declaration\n");
														$$ = $1;
														VAR_DATA *newstruc = new VAR_DATA();
														*newstruc = $3;
														$$->push_back(newstruc);
													}
	;

parameter_declaration
	: declaration_specifiers declarator					{
															printf("parameter_declaration: declaration_specifiers declarator\n");
															$$.name = $2->name;
															if(!isarray($2->typ))
																$$.typ = get_type($1);
															else
																$$.typ = get_type($1) | ARRAY_SPEC;
														}
	| declaration_specifiers abstract_declarator		{printf("parameter_declaration: declaration_specifiers abstract_declarator\n");}
	| declaration_specifiers							{printf("parameter_declaration: declaration_specifiers\n");}
	;

identifier_list
	: IDENTIFIER								{
													string *name = new string($1); /* El nombre es el atributo id del token IDENTIFIER */
													printf("identifier_list: IDENTIFIER");
													cout << "<" << *name << ">" << "\n";	
												}
	| identifier_list ',' IDENTIFIER			{
													string *name = new string($3); /* El nombre es el atributo id del token IDENTIFIER */
													printf("identifier_list: identifier_list ',' IDENTIFIER");
													cout << "<" << *name << ">" << "\n";
												}
	;

type_name
	: specifier_qualifier_list							{
															printf("type_name: specifier_qualifier_list\n");
															$$ = get_type($1);	
														}
	| specifier_qualifier_list abstract_declarator		{printf("type_name: specifier_qualifier_list abstract_declarator\n");}
	;

abstract_declarator
	: pointer									{printf("abstract_declarator: pointer\n");}
	| direct_abstract_declarator				{printf("abstract_declarator: direct_abstract_declarator\n");}
	| pointer direct_abstract_declarator		{printf("abstract_declarator: pointer direct_abstract_declarator\n");}
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'									{printf("direct_abstract_declarator: '(' abstract_declarator ')'\n");}
	| '[' ']'														{printf("direct_abstract_declarator: '[' ']'\n");}
	| '[' constant_expression ']'									{printf("direct_abstract_declarator: '[' constant_expression ']'\n");}
	| direct_abstract_declarator '[' ']'							{printf("direct_abstract_declarator: direct_abstract_declarator '[' ']' \n");}
	| direct_abstract_declarator '[' constant_expression ']'		{printf("direct_abstract_declarator: direct_abstract_declarator '[' constant_expression ']'\n");}
	| '(' ')'														{printf("direct_abstract_declarator: '(' ')'\n");}
	| '(' parameter_type_list ')'									{printf("direct_abstract_declarator: '(' parameter_type_list ')'\n");}
	| direct_abstract_declarator '(' ')'							{printf("direct_abstract_declarator: direct_abstract_declarator '(' ')'\n");}
	| direct_abstract_declarator '(' parameter_type_list ')'		{printf("direct_abstract_declarator: direct_abstract_declarator '(' parameter_type_list ')'\n");}
	;

initializer
	: assignment_expression					{
												printf("initializer: assignment_expression\n");
												$$ = $1;	
											}
	| '{' initializer_list '}'				{printf("initializer: '{' initializer_list '}'\n");}
	| '{' initializer_list ',' '}'			{printf("initializer: '{' initializer_list ',' '}'\n");}
	;

initializer_list							
	: initializer							{printf("initializer_list: initializer\n");}
	| initializer_list ',' initializer		{printf("initializer_list: initializer_list ',' initializer\n");}
	;

P : /* */						
  ;

statement
	: labeled_statement			{
									printf("statement: labeled_statement\n");
									$$ = $1;
									$$.nextlist = NULL;
								}
	| P 						{
									enter_scope();
								}
	  compound_statement		{
		  							printf("statement: compound_statement\n");
									//printlocalvars();
									exit_scope();
									$$ = $3;
								}
	| expression_statement		{
									printf("statement: expression_statement\n");
									$$.nextlist = NULL;
									$$.breaklist = NULL;
									$$.continuelist = NULL;
									$$.gotolist = NULL;
									$$.caselist = NULL;	
								}
	| selection_statement		{
									printf("statement: selection_statement\n");
									$$ = $1;
									$$.caselist = NULL;
								}
	| iteration_statement		{
									printf("statement: iteration_statement\n");
									$$ = $1;
									$$.caselist = NULL;
								}
	| jump_statement			{
									printf("statement: jump_statement\n");
									$$ = $1;
									$$.caselist = NULL;
								}
	;

N: /* Empty */					{	
									/* Retornar direccion de siguiente instruccion de IR */
									$$ = nextinstr;
								}
	;

labeled_statement
	: IDENTIFIER ':' N statement					{
														printf("labeled_statement: IDENTIFIER ':' statement\n");
														putlab(new string($1), $3);
														$$.nextlist = NULL;
														$$.breaklist = NULL;
														$$.continuelist = NULL;
														$$.gotolist = NULL;
														$$.caselist = NULL;
													}
	| CASE constant_expression ':' N statement		{
														printf("labeled_statement: CASE constant_expression ':' statement\n");
														$$.breaklist = $5.breaklist;
														$$.continuelist = $5.continuelist;
														$$.gotolist = $5.gotolist;
														if(!isconstant($2.typ))
															yyerror("Error: CASE espression must be constant\n");
														if(!isintegral($2.typ))
															yyerror("Error: CASE espression must be integral constant\n");
														$$.caselist = makecaselist($2.val, $2.typ, $4);
													}
	| DEFAULT ':' N statement						{
														printf("labeled_statement: DEFAULT ':' statement\n");
														$$.breaklist = $4.breaklist;
														$$.continuelist = $4.continuelist;
														$$.gotolist = $4.gotolist;
														$$.caselist = makecaselist($3);
													}
	;

compound_statement
	: '{' '}'										{
														printf("compound_statement: '{' '}'\n");
														$$.breaklist = NULL;
														$$.continuelist = NULL;
														$$.gotolist = NULL;
														$$.nextlist = NULL;
													}
	| '{' statement_list '}'						{
														printf("compound_statement: '{' statement_list '}'\n");
														$$ = $2;
													}
	| '{' declaration_list '}'						{
														printf("compound_statement: '{' declaration_list '}'\n");
														$$.breaklist = NULL;
														$$.continuelist = NULL;
														$$.gotolist = NULL;
														$$.nextlist = NULL;
													}
	| '{' declaration_list statement_list '}'		{
														printf("compound_statement: '{' declaration_list statement_list '}'\n");
														$$ = $3;
													}
	;

declaration_list
	: declaration									{printf("declaration_list: declaration\n");}
	| declaration_list declaration					{printf("declaration_list: declaration_list declaration\n");}
	;

statement_list						
	: statement										{
														printf("statement_list: statement\n");
														$$ = $1;
													}
	| statement_list N statement					{
														printf("statement_list: statement_list statement\n");
														backpatch($1.nextlist, $2);
														$$ = $1;
														$$.nextlist = $3.nextlist;
														$$.breaklist = merge($1.breaklist, $3.breaklist);
														$$.continuelist = merge($1.continuelist, $3.continuelist);
														$$.gotolist = merge($1.gotolist, $3.gotolist);
														$$.caselist = merge($1.caselist, $3.caselist);
													}
	;

expression_statement
	: ';'											{
														printf("expression_statement: ';'\n");
														$$.truelist = nullptr;
														$$.falselist = nullptr;
													}
	| expression ';'								{
														printf("expression_statement: expression ';'\n");
														$$ = $1;
													}
	;

logic_expression: expression 						{
														$$ = $1;
														/* Verificar si expression es compracion u operacion logica*/
														if($1.truelist == nullptr || $1.falselist == nullptr)
														{
															std::string *name = newtemp(); /* Nueva variable temporal */
															symrec *s0;
															s0 = putsym(name, INTVAL | CONST_SPEC);
															* (int *)(datablock+s0->offset) = 0;
															$$.truelist = makelist(nextinstr);
															gencode(IF_NE_IR, $1.var, s0, nullptr);
															$$.falselist = makelist(nextinstr);
															gencode(GOTO_IR);
														}
													}

selection_statement
	: IF '(' logic_expression ')' N statement %prec NO_ELSE			{
																		printf("selection_statement: IF '(' expression ')' statement\n");
																		backpatch($3.truelist, $5);
																		$$.nextlist = merge($3.falselist, $6.nextlist);
																		$$.breaklist = $6.breaklist;
																		$$.continuelist = $6.continuelist;
																		$$.gotolist = $6.gotolist;
																	}
	| IF '(' logic_expression ')' N statement ELSE M N statement	{
																		printf("selection_statement: IF '(' expression ')' statement ELSE statement\n");
																		backpatch($3.truelist, $5);
																		backpatch($3.falselist, $9);
																		$$.nextlist = merge($6.nextlist, $8.nextlist, $10.nextlist);
																		$$.breaklist = merge($6.breaklist, $10.breaklist);
																		$$.continuelist = merge($6.continuelist, $10.continuelist);
																		$$.gotolist = merge($6.gotolist, $10.gotolist);
																	}
	| SWITCH '(' expression ')' M statement							{
																		printf("selection_statement: SWITCH '(' expression ')' statement\n");
																		if(!isintegral($3.typ))
																			yyerror("Error: switch expression must be integral\n");
																		$6.breaklist = merge ($6.breaklist, makelist(nextinstr));
																		gencode(GOTO_IR); /* Saltar al final del switch */
																		/* Completar salto denerado en regla de M */
																		backpatch($5.nextlist, nextinstr);
																		std::list<CASE_DATA *>::iterator it;
																		if($6.caselist != NULL)
																		{
																			for(it = $6.caselist->begin(); it != $6.caselist->end(); it++)
																			{
																				int addr = (*it)->addr;
																				int typ = (*it)->typ;
																				if(typ == VOIDVAL)
																					gencode(GOTO_IR, addr);
																				else
																				{
																					std::string *name = newtemp(); /* Nueva variable temporal */
																					symrec *s;
																					s = putsym(name, INTVAL | CONST_SPEC);
																					symrec *s1 = $3.var;
																					* (int *)((char *)datablock+s->offset) = (*it)->val.intval;
																					if(isconstant($3.typ))
																					{
																						name = newtemp();
																						s1 = putsym(name, INTVAL | CONST_SPEC);
																						*(int *)((char *)datablock+s->offset) = $3.val.intval;
																					}
																					gencode(IF_EQ_IR, s1, s, addr);
																				}
																			}
																		}
																		backpatch($6.breaklist, nextinstr);
																		$$.breaklist = NULL;
																		$$.continuelist = $6.continuelist;
																		$$.gotolist = $6.gotolist;
																		$$.nextlist = NULL;
																	}
	;
logic_expression_statement : expression_statement													{
																										$$=$1;
																										/* Verificar si espression es comparacion u operacion logica */
																										if($1.truelist == nullptr || $1.falselist == nullptr)
																										{
																											std::string *name = newtemp();
																											symrec *s0;
																											s0 = putsym(name, INTVAL | CONST_SPEC);
																											* (int *)(datablock+s0->offset) = 0;
																											$$.truelist = makelist(nextinstr);
																											gencode(IF_NE_IR, $1.var, s0, nullptr);
																											$$.falselist = makelist(nextinstr);
																											gencode(GOTO_IR);
																										}
																									}
;
iteration_statement
	: WHILE N '(' logic_expression ')' N statement													{
																										printf("iteration_statement: WHILE '(' expression ')' statement\n");
																										backpatch($7.nextlist, $2);
																										backpatch($7.continuelist, $2);
																										backpatch($4.truelist, $6);
																										$$.nextlist = $4.falselist;
																										gencode(GOTO_IR, $2);
																										backpatch($7.breaklist, nextinstr);
																										$$.breaklist = NULL;
																										$$.continuelist = NULL;
																										$$.gotolist = $7.gotolist;
																									}
| DO N statement WHILE N '(' logic_expression ')' ';'												{
																										printf("iteration_statement: DO statement WHILE '(' expression ')' ';'\n");
																										backpatch($7.truelist, $2);
																										backpatch($3.nextlist, $5);
																										backpatch($3.continuelist, $5);
																										backpatch($3.breaklist, nextinstr);
																										$$.breaklist = NULL;
																										$$.continuelist = NULL;
																										$$.nextlist = $7.falselist;
																										$$.gotolist = $3.gotolist;
																									}
| FOR '(' expression_statement N logic_expression_statement N ')' statement							{
																										printf("iteration_statement: FOR '(' expression_statement expression_statement ')' statement\n");
																										backpatch($5.truelist, $6);
																										backpatch($8.nextlist, $4);
																										backpatch($8.continuelist, $4);
																										$$.nextlist = $5.falselist;
																										gencode(GOTO_IR, $4);
																										backpatch($8.breaklist, nextinstr);
																										$$.breaklist = NULL;
																										$$.continuelist = NULL;
																										$$.gotolist = $8.gotolist;
																									}
	| FOR '(' expression_statement N logic_expression_statement N expression ')' M N statement		{
																										printf("iteration_statement: FOR '(' expression_statement expression_statement expression ')' statement\n");
																										backpatch($5.truelist, $10);		/* Completar saltos */
																										backpatch($11.nextlist, $6);		/* Completar saltos */
																										backpatch($11.continuelist, $6);	/* Completar saltos */
																										backpatch($9.nextlist, $4);			/* Completar saltos */
																										$$.nextlist = $5.falselist;			/* Propagar saltos */
																										gencode(GOTO_IR, $6);				/* Insertar salto a */
																										backpatch($11.breaklist, nextinstr);
																										$$.breaklist = NULL;
																										$$.continuelist = NULL;
																										$$.gotolist = $11.gotolist;
																									}
	;

jump_statement
	: GOTO IDENTIFIER ';'			{
										printf("jump_statement: GOTO IDENTIFIER ';'\n");
										$$.continuelist = NULL;
										$$.breaklist = NULL;
										$$.nextlist = NULL;
										$$.caselist = NULL;
										$$.gotolist = makelist(new string($2), nextinstr);
										gencode(GOTO_IR);
									}
	| CONTINUE ';'					{
										printf("jump_statement: CONTINUE ';'\n");
										$$.breaklist = NULL;
										$$.nextlist = NULL;
										$$.caselist = NULL;
										$$.gotolist = NULL;
										$$.continuelist = makelist(nextinstr);
										gencode(GOTO_IR);
									}
	| BREAK ';'						{
										printf("jump_statement: BREAK ';'\n");
										$$.nextlist = NULL;
										$$.continuelist = NULL;
										$$.caselist = NULL;
										$$.gotolist = NULL;
										$$.breaklist = makelist(nextinstr);
										gencode(GOTO_IR);
									}
	| RETURN ';'					{
										printf("jump_statement: RETURN ';'\n");
										gencode(RET_IR);
										$$.breaklist = NULL;
										$$.nextlist = NULL;
										$$.continuelist = NULL;
										$$.caselist = NULL;
										$$.gotolist = NULL;
									}
	| RETURN expression ';'			{
										printf("jump_statement: RETURN expression ';'\n");
										gencode(RET_IR, $2.var, nullptr, nullptr);
										$$.breaklist = NULL;
										$$.nextlist = NULL;
										$$.continuelist = NULL;
										$$.caselist = NULL;
										$$.gotolist = NULL;
									}
	;

translation_unit
	: external_declaration							{printf("translation_unit: external_declaration\n");}
	| translation_unit external_declaration			{printf("translation_unit: translation_unit external_declaration\n");}
	;

external_declaration
	: function_definition							{printf("external_declaration: function_definition\n");}
	| declaration									{printf("external_declaration: declaration\n");}
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement		{printf("function_definition: declaration_specifiers declarator declaration_list compound_statement\n");}
	| declaration_specifiers declarator 										{
																					int typ = get_type($1) | $2->typ;
																					curr_func = install ($2->name, typ);
																					gencode(PROC_IR, curr_func);
																					localsyms = new symboltable();
																					enter_scope();
																					installarg($2->arglist);
																					/* Iniciar nueva tabla de etiquetas */
																					lab_table.clear();
																					setargs();
																				}
	
	  compound_statement														{
		  																			printf("function_definition: declaration_specifiers declarator compound_statement\n");
																					//printlocalvars();
																					exit_scope();	  
																					curr_func->func_desc.sym_table = localsyms;
																					gencode(ENDPROC_IR, curr_func);
																					patch_gotos($4.gotolist);
																				}
	
	| declarator declaration_list compound_statement							{printf("function_definition: declarator declaration_list compound_statement\n");}
	| declarator 																{
																					int typ = INTVAL | $1->typ;
																					curr_func = install ($1->name, typ);
																					gencode(PROC_IR, curr_func);
																					localsyms = new symboltable();
																					enter_scope();
																					installarg($1->arglist);
																					/* Iniciar nueva tabla de etiquetas */
																					lab_table.clear();
																					setargs();
																				}
	  compound_statement														{
		  																			printf("function_definition: declarator compound_statement\n");
																					//printlocalvars();
																					exit_scope();	  
																					curr_func->func_desc.sym_table = localsyms;
																					gencode(ENDPROC_IR, curr_func);
																					patch_gotos($3.gotolist);
																				}
	;

%%

int main(int argc, char *argv[])
{
	string fname; /* Para guardar nombre de archivo compilandose */
	/*Crear tabla de simbolos globales*/
	sym_table = new symboltable();
	cout << "Compilador de C";
	cout << "Proyecto final\n\n";
	if(argc>1)
	{
		yyin =fopen(argv[1], "r");
		fname = argv[1];
	}
	else
	{
		cout << "Uso incorrecto: " << argv[0] << " <filename>\n";
		return(0);
	}
	yyparse();
	printvars();
	printf("\nCodigo intermedio:\n");
	print_icode();
	print_code(fname);
	return 0;
}