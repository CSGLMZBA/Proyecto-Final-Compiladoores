/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "ansic.y"

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


#line 131 "ansic.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    CONSTANT = 259,                /* CONSTANT  */
    STRING_LITERAL = 260,          /* STRING_LITERAL  */
    SIZEOF = 261,                  /* SIZEOF  */
    PTR_OP = 262,                  /* PTR_OP  */
    INC_OP = 263,                  /* INC_OP  */
    DEC_OP = 264,                  /* DEC_OP  */
    LEFT_OP = 265,                 /* LEFT_OP  */
    RIGHT_OP = 266,                /* RIGHT_OP  */
    LE_OP = 267,                   /* LE_OP  */
    GE_OP = 268,                   /* GE_OP  */
    EQ_OP = 269,                   /* EQ_OP  */
    NE_OP = 270,                   /* NE_OP  */
    AND_OP = 271,                  /* AND_OP  */
    OR_OP = 272,                   /* OR_OP  */
    MUL_ASSIGN = 273,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 274,              /* DIV_ASSIGN  */
    MOD_ASSIGN = 275,              /* MOD_ASSIGN  */
    ADD_ASSIGN = 276,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 277,              /* SUB_ASSIGN  */
    LEFT_ASSIGN = 278,             /* LEFT_ASSIGN  */
    RIGHT_ASSIGN = 279,            /* RIGHT_ASSIGN  */
    AND_ASSIGN = 280,              /* AND_ASSIGN  */
    XOR_ASSIGN = 281,              /* XOR_ASSIGN  */
    OR_ASSIGN = 282,               /* OR_ASSIGN  */
    TYPE_NAME = 283,               /* TYPE_NAME  */
    TYPEDEF = 284,                 /* TYPEDEF  */
    EXTERN = 285,                  /* EXTERN  */
    STATIC = 286,                  /* STATIC  */
    AUTO = 287,                    /* AUTO  */
    REGISTER = 288,                /* REGISTER  */
    CHAR = 289,                    /* CHAR  */
    SHORT = 290,                   /* SHORT  */
    INT = 291,                     /* INT  */
    LONG = 292,                    /* LONG  */
    SIGNED = 293,                  /* SIGNED  */
    UNSIGNED = 294,                /* UNSIGNED  */
    FLOAT = 295,                   /* FLOAT  */
    DOUBLE = 296,                  /* DOUBLE  */
    CONST = 297,                   /* CONST  */
    VOLATILE = 298,                /* VOLATILE  */
    VOID = 299,                    /* VOID  */
    STRUCT = 300,                  /* STRUCT  */
    UNION = 301,                   /* UNION  */
    ENUM = 302,                    /* ENUM  */
    ELLIPSIS = 303,                /* ELLIPSIS  */
    CASE = 304,                    /* CASE  */
    DEFAULT = 305,                 /* DEFAULT  */
    IF = 306,                      /* IF  */
    ELSE = 307,                    /* ELSE  */
    SWITCH = 308,                  /* SWITCH  */
    WHILE = 309,                   /* WHILE  */
    DO = 310,                      /* DO  */
    FOR = 311,                     /* FOR  */
    GOTO = 312,                    /* GOTO  */
    CONTINUE = 313,                /* CONTINUE  */
    BREAK = 314,                   /* BREAK  */
    RETURN = 315,                  /* RETURN  */
    NO_ELSE = 316                  /* NO_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 61 "ansic.y"

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

#line 278 "ansic.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_CONSTANT = 4,                   /* CONSTANT  */
  YYSYMBOL_STRING_LITERAL = 5,             /* STRING_LITERAL  */
  YYSYMBOL_SIZEOF = 6,                     /* SIZEOF  */
  YYSYMBOL_PTR_OP = 7,                     /* PTR_OP  */
  YYSYMBOL_INC_OP = 8,                     /* INC_OP  */
  YYSYMBOL_DEC_OP = 9,                     /* DEC_OP  */
  YYSYMBOL_LEFT_OP = 10,                   /* LEFT_OP  */
  YYSYMBOL_RIGHT_OP = 11,                  /* RIGHT_OP  */
  YYSYMBOL_LE_OP = 12,                     /* LE_OP  */
  YYSYMBOL_GE_OP = 13,                     /* GE_OP  */
  YYSYMBOL_EQ_OP = 14,                     /* EQ_OP  */
  YYSYMBOL_NE_OP = 15,                     /* NE_OP  */
  YYSYMBOL_AND_OP = 16,                    /* AND_OP  */
  YYSYMBOL_OR_OP = 17,                     /* OR_OP  */
  YYSYMBOL_MUL_ASSIGN = 18,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 19,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 20,                /* MOD_ASSIGN  */
  YYSYMBOL_ADD_ASSIGN = 21,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 22,                /* SUB_ASSIGN  */
  YYSYMBOL_LEFT_ASSIGN = 23,               /* LEFT_ASSIGN  */
  YYSYMBOL_RIGHT_ASSIGN = 24,              /* RIGHT_ASSIGN  */
  YYSYMBOL_AND_ASSIGN = 25,                /* AND_ASSIGN  */
  YYSYMBOL_XOR_ASSIGN = 26,                /* XOR_ASSIGN  */
  YYSYMBOL_OR_ASSIGN = 27,                 /* OR_ASSIGN  */
  YYSYMBOL_TYPE_NAME = 28,                 /* TYPE_NAME  */
  YYSYMBOL_TYPEDEF = 29,                   /* TYPEDEF  */
  YYSYMBOL_EXTERN = 30,                    /* EXTERN  */
  YYSYMBOL_STATIC = 31,                    /* STATIC  */
  YYSYMBOL_AUTO = 32,                      /* AUTO  */
  YYSYMBOL_REGISTER = 33,                  /* REGISTER  */
  YYSYMBOL_CHAR = 34,                      /* CHAR  */
  YYSYMBOL_SHORT = 35,                     /* SHORT  */
  YYSYMBOL_INT = 36,                       /* INT  */
  YYSYMBOL_LONG = 37,                      /* LONG  */
  YYSYMBOL_SIGNED = 38,                    /* SIGNED  */
  YYSYMBOL_UNSIGNED = 39,                  /* UNSIGNED  */
  YYSYMBOL_FLOAT = 40,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 41,                    /* DOUBLE  */
  YYSYMBOL_CONST = 42,                     /* CONST  */
  YYSYMBOL_VOLATILE = 43,                  /* VOLATILE  */
  YYSYMBOL_VOID = 44,                      /* VOID  */
  YYSYMBOL_STRUCT = 45,                    /* STRUCT  */
  YYSYMBOL_UNION = 46,                     /* UNION  */
  YYSYMBOL_ENUM = 47,                      /* ENUM  */
  YYSYMBOL_ELLIPSIS = 48,                  /* ELLIPSIS  */
  YYSYMBOL_CASE = 49,                      /* CASE  */
  YYSYMBOL_DEFAULT = 50,                   /* DEFAULT  */
  YYSYMBOL_IF = 51,                        /* IF  */
  YYSYMBOL_ELSE = 52,                      /* ELSE  */
  YYSYMBOL_SWITCH = 53,                    /* SWITCH  */
  YYSYMBOL_WHILE = 54,                     /* WHILE  */
  YYSYMBOL_DO = 55,                        /* DO  */
  YYSYMBOL_FOR = 56,                       /* FOR  */
  YYSYMBOL_GOTO = 57,                      /* GOTO  */
  YYSYMBOL_CONTINUE = 58,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 59,                     /* BREAK  */
  YYSYMBOL_RETURN = 60,                    /* RETURN  */
  YYSYMBOL_NO_ELSE = 61,                   /* NO_ELSE  */
  YYSYMBOL_62_ = 62,                       /* '('  */
  YYSYMBOL_63_ = 63,                       /* ')'  */
  YYSYMBOL_64_ = 64,                       /* '['  */
  YYSYMBOL_65_ = 65,                       /* ']'  */
  YYSYMBOL_66_ = 66,                       /* '.'  */
  YYSYMBOL_67_ = 67,                       /* ','  */
  YYSYMBOL_68_ = 68,                       /* '&'  */
  YYSYMBOL_69_ = 69,                       /* '*'  */
  YYSYMBOL_70_ = 70,                       /* '+'  */
  YYSYMBOL_71_ = 71,                       /* '-'  */
  YYSYMBOL_72_ = 72,                       /* '~'  */
  YYSYMBOL_73_ = 73,                       /* '!'  */
  YYSYMBOL_74_ = 74,                       /* '/'  */
  YYSYMBOL_75_ = 75,                       /* '%'  */
  YYSYMBOL_76_ = 76,                       /* '<'  */
  YYSYMBOL_77_ = 77,                       /* '>'  */
  YYSYMBOL_78_ = 78,                       /* '^'  */
  YYSYMBOL_79_ = 79,                       /* '|'  */
  YYSYMBOL_80_ = 80,                       /* '?'  */
  YYSYMBOL_81_ = 81,                       /* ':'  */
  YYSYMBOL_82_ = 82,                       /* '='  */
  YYSYMBOL_83_ = 83,                       /* ';'  */
  YYSYMBOL_84_ = 84,                       /* '{'  */
  YYSYMBOL_85_ = 85,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 86,                  /* $accept  */
  YYSYMBOL_primary_expression = 87,        /* primary_expression  */
  YYSYMBOL_postfix_expression = 88,        /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 89,  /* argument_expression_list  */
  YYSYMBOL_unary_expression = 90,          /* unary_expression  */
  YYSYMBOL_unary_operator = 91,            /* unary_operator  */
  YYSYMBOL_cast_expression = 92,           /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 93, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 94,       /* additive_expression  */
  YYSYMBOL_shift_expression = 95,          /* shift_expression  */
  YYSYMBOL_relational_expression = 96,     /* relational_expression  */
  YYSYMBOL_equality_expression = 97,       /* equality_expression  */
  YYSYMBOL_and_expression = 98,            /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 99,   /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 100,  /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 101,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 102,    /* logical_or_expression  */
  YYSYMBOL_M = 103,                        /* M  */
  YYSYMBOL_conditional_expression = 104,   /* conditional_expression  */
  YYSYMBOL_105_1 = 105,                    /* $@1  */
  YYSYMBOL_assignment_expression = 106,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 107,      /* assignment_operator  */
  YYSYMBOL_expression = 108,               /* expression  */
  YYSYMBOL_constant_expression = 109,      /* constant_expression  */
  YYSYMBOL_declaration = 110,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 111,   /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 112,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 113,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 114,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 115,           /* type_specifier  */
  YYSYMBOL_struct_or_union_specifier = 116, /* struct_or_union_specifier  */
  YYSYMBOL_struct_or_union = 117,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 118,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 119,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 120, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 121,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 122,        /* struct_declarator  */
  YYSYMBOL_enum_specifier = 123,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 124,          /* enumerator_list  */
  YYSYMBOL_enumerator = 125,               /* enumerator  */
  YYSYMBOL_type_qualifier = 126,           /* type_qualifier  */
  YYSYMBOL_declarator = 127,               /* declarator  */
  YYSYMBOL_direct_declarator = 128,        /* direct_declarator  */
  YYSYMBOL_pointer = 129,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 130,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 131,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 132,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 133,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 134,          /* identifier_list  */
  YYSYMBOL_type_name = 135,                /* type_name  */
  YYSYMBOL_abstract_declarator = 136,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 137, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 138,              /* initializer  */
  YYSYMBOL_initializer_list = 139,         /* initializer_list  */
  YYSYMBOL_P = 140,                        /* P  */
  YYSYMBOL_statement = 141,                /* statement  */
  YYSYMBOL_142_2 = 142,                    /* $@2  */
  YYSYMBOL_N = 143,                        /* N  */
  YYSYMBOL_labeled_statement = 144,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 145,       /* compound_statement  */
  YYSYMBOL_declaration_list = 146,         /* declaration_list  */
  YYSYMBOL_statement_list = 147,           /* statement_list  */
  YYSYMBOL_expression_statement = 148,     /* expression_statement  */
  YYSYMBOL_logic_expression = 149,         /* logic_expression  */
  YYSYMBOL_selection_statement = 150,      /* selection_statement  */
  YYSYMBOL_logic_expression_statement = 151, /* logic_expression_statement  */
  YYSYMBOL_iteration_statement = 152,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 153,           /* jump_statement  */
  YYSYMBOL_translation_unit = 154,         /* translation_unit  */
  YYSYMBOL_external_declaration = 155,     /* external_declaration  */
  YYSYMBOL_function_definition = 156,      /* function_definition  */
  YYSYMBOL_157_3 = 157,                    /* $@3  */
  YYSYMBOL_158_4 = 158                     /* $@4  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  60
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1240

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  86
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  73
/* YYNRULES -- Number of rules.  */
#define YYNRULES  221
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  378

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   316


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    73,     2,     2,     2,    75,    68,     2,
      62,    63,    69,    70,    67,    71,    66,    74,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    81,    83,
      76,    82,    77,    80,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    64,     2,    65,    78,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    84,    79,    85,    72,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   167,   167,   182,   217,   238,   245,   249,   290,   299,
     316,   317,   318,   338,   361,   371,   381,   385,   399,   413,
     463,   477,   494,   498,   502,   506,   510,   514,   521,   536,
     567,   571,   580,   589,   601,   605,   614,   626,   630,   631,
     635,   639,   647,   655,   663,   674,   678,   686,   697,   701,
     713,   717,   729,   733,   745,   749,   761,   765,   774,   779,
     783,   783,   803,   807,  1055,  1059,  1063,  1067,  1071,  1075,
    1079,  1083,  1087,  1091,  1095,  1102,  1106,  1113,  1120,  1121,
    1154,  1160,  1165,  1171,  1176,  1182,  1190,  1197,  1205,  1209,
    1218,  1222,  1226,  1230,  1234,  1241,  1245,  1249,  1253,  1257,
    1261,  1265,  1269,  1273,  1277,  1281,  1285,  1292,  1293,  1294,
    1298,  1299,  1303,  1304,  1308,  1312,  1317,  1323,  1328,  1337,
    1338,  1342,  1343,  1344,  1348,  1349,  1350,  1354,  1355,  1359,
    1360,  1364,  1368,  1375,  1381,  1402,  1411,  1415,  1427,  1435,
    1442,  1443,  1452,  1457,  1462,  1467,  1476,  1480,  1487,  1491,
    1495,  1503,  1513,  1521,  1522,  1526,  1531,  1539,  1543,  1547,
    1548,  1549,  1553,  1554,  1555,  1556,  1557,  1558,  1559,  1560,
    1561,  1565,  1569,  1570,  1574,  1575,  1578,  1582,  1587,  1587,
    1596,  1604,  1609,  1614,  1621,  1628,  1637,  1648,  1658,  1665,
    1669,  1676,  1683,  1684,  1688,  1692,  1705,  1710,  1716,  1733,
    1741,  1750,  1791,  1808,  1820,  1831,  1843,  1859,  1868,  1877,
    1886,  1895,  1907,  1908,  1912,  1913,  1917,  1918,  1918,  1939,
    1940,  1940
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "CONSTANT", "STRING_LITERAL", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP",
  "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP",
  "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN",
  "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN",
  "OR_ASSIGN", "TYPE_NAME", "TYPEDEF", "EXTERN", "STATIC", "AUTO",
  "REGISTER", "CHAR", "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED",
  "FLOAT", "DOUBLE", "CONST", "VOLATILE", "VOID", "STRUCT", "UNION",
  "ENUM", "ELLIPSIS", "CASE", "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE",
  "DO", "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN", "NO_ELSE", "'('",
  "')'", "'['", "']'", "'.'", "','", "'&'", "'*'", "'+'", "'-'", "'~'",
  "'!'", "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "':'", "'='",
  "';'", "'{'", "'}'", "$accept", "primary_expression",
  "postfix_expression", "argument_expression_list", "unary_expression",
  "unary_operator", "cast_expression", "multiplicative_expression",
  "additive_expression", "shift_expression", "relational_expression",
  "equality_expression", "and_expression", "exclusive_or_expression",
  "inclusive_or_expression", "logical_and_expression",
  "logical_or_expression", "M", "conditional_expression", "$@1",
  "assignment_expression", "assignment_operator", "expression",
  "constant_expression", "declaration", "declaration_specifiers",
  "init_declarator_list", "init_declarator", "storage_class_specifier",
  "type_specifier", "struct_or_union_specifier", "struct_or_union",
  "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "P", "statement", "$@2", "N", "labeled_statement",
  "compound_statement", "declaration_list", "statement_list",
  "expression_statement", "logic_expression", "selection_statement",
  "logic_expression_statement", "iteration_statement", "jump_statement",
  "translation_unit", "external_declaration", "function_definition", "$@3",
  "$@4", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-281)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-218)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     864,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,
    -281,    15,    40,     4,  -281,    31,  1193,  1193,  -281,    23,
    -281,  1193,  1193,   -12,    39,   774,  -281,  -281,   -62,    12,
     -10,  -281,  -281,     4,  -281,   -34,  -281,  1017,  -281,  -281,
     -19,   991,  -281,  -281,    31,  1037,    -1,   909,   579,   -12,
    -281,  -281,    12,    -7,   -37,  -281,  -281,  -281,  -281,    40,
    -281,   437,  1037,    -1,   991,   991,   939,  -281,   126,   991,
       8,   293,  -281,  -281,  -281,  -281,  -281,    58,    62,    68,
    -281,   105,  -281,  -281,  -281,   674,   700,   700,   558,  -281,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,   420,  -281,   721,
    -281,    49,    95,   183,   121,   187,    -8,    20,    81,   229,
      -3,  -281,   118,   -22,   721,    12,  -281,  -281,   437,   805,
    -281,  -281,  -281,  -281,  -281,   959,  -281,  -281,  -281,   721,
      96,  -281,   123,  -281,   176,   721,   185,   213,   215,  -281,
    -281,   216,   276,   198,   199,   485,  -281,  -281,  -281,   158,
    -281,  -281,  -281,   364,   200,  -281,  -281,  -281,  -281,   819,
     603,  -281,    22,  -281,    53,  -281,  1172,  -281,   280,   558,
    -281,   721,  -281,  -281,   156,   127,   221,   283,  -281,  -281,
     244,   721,   285,  -281,   721,   721,   721,   721,   721,   721,
     721,   721,   721,   721,   721,   721,   721,   721,   721,   721,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,    -9,  -281,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,
     721,  -281,  -281,   126,  -281,   721,  -281,   208,  -281,   721,
     721,   230,   469,   508,   210,  -281,  -281,  -281,   159,   721,
    -281,    -1,  -281,   206,  -281,   469,  -281,   232,   237,  -281,
     238,    53,  1136,   629,  -281,  -281,  -281,   241,  -281,  1094,
      64,  -281,   721,  -281,  -281,   167,  -281,    92,  -281,  -281,
    -281,  -281,    49,    49,    95,    95,   183,   183,   183,   183,
     121,   121,   187,    -8,    20,   721,   721,   721,   382,  -281,
    -281,  -281,  -281,   469,  -281,   469,   243,   242,   188,   721,
     257,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,
    -281,  -281,   255,  -281,   254,  -281,  -281,  -281,   721,  -281,
      81,   229,   -26,  -281,  -281,  -281,   469,  -281,  -281,  -281,
     278,  -281,   508,  -281,  -281,  -281,  -281,  -281,   469,   469,
    -281,   292,  -281,  -281,  -281,   304,  -281,   469,   721,   650,
    -281,  -281,  -281,   282,   469,   193,   721,  -281,   274,  -281,
    -281,  -281,   469,  -281,  -281,  -281,   469,  -281
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   135,   106,    90,    91,    92,    93,    94,    96,    97,
      98,    99,   102,   103,   100,   101,   131,   132,    95,   110,
     111,     0,     0,   142,   215,     0,    80,    82,   104,     0,
     105,    84,   220,   134,     0,     0,   212,   214,   126,     0,
       0,   146,   144,   143,    78,     0,    86,    88,    81,    83,
     109,     0,    85,   192,     0,     0,     0,     0,     0,   133,
       1,   213,     0,   129,     0,   127,   136,   147,   145,     0,
      79,     0,     0,     0,     0,   116,     0,   112,     0,   118,
      88,   176,   193,   219,   221,   155,   141,   154,     0,   148,
     150,     0,     2,     3,     4,     0,     0,     0,     0,   138,
      22,    23,    24,    25,    26,    27,     6,    16,    28,     0,
      30,    34,    37,    40,    45,    48,    50,    52,    54,    56,
      59,    77,     0,     0,     0,     0,   124,    87,     0,    28,
      62,   171,    89,   216,   218,     0,   115,   108,   113,     0,
       0,   119,   121,   117,     2,     0,     0,     0,     0,   184,
     184,     0,     0,     0,     0,     0,   196,   188,    75,     0,
     178,   194,   177,   176,   184,   180,   181,   182,   183,     0,
       0,   152,   159,   153,   160,   139,     0,   140,     0,     0,
      20,     0,    17,    18,     0,   157,     0,     0,    12,    13,
       0,     0,     0,    19,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     184,   184,   184,   137,   125,   130,   128,   174,     0,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    64,
       0,   107,   122,     0,   114,     0,   184,     0,   184,     0,
       0,     0,   176,     0,     0,   208,   209,   210,     0,     0,
     197,     0,   190,   184,   189,   176,   167,     0,     0,   163,
       0,   161,     0,     0,   149,   151,   156,     0,     5,     0,
     159,   158,     0,    11,     8,     0,    14,     0,    10,    31,
      32,    33,    35,    36,    38,    39,    43,    44,    41,    42,
      46,    47,    49,    51,    53,     0,     0,     0,     0,   172,
      63,   120,   123,   176,   184,   176,   198,     0,     0,     0,
       0,   184,   207,   211,    76,   179,   191,   195,   168,   162,
     164,   169,     0,   165,     0,    21,    29,     9,     0,     7,
      55,    57,     0,   173,   175,   185,   176,   187,   184,    58,
       0,   184,     0,   170,   166,    15,    60,   186,   176,   176,
     184,     0,   202,   184,    58,   199,   201,   176,     0,     0,
     184,    58,   203,     0,   176,     0,     0,   184,     0,   205,
      58,    61,   176,   204,   184,   200,   176,   206
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -281,  -281,  -281,  -281,   -58,  -281,   -99,    35,    44,    61,
      63,   151,   152,   150,    76,    78,  -281,  -143,   -57,  -281,
     -69,  -281,   -87,   -60,    19,     5,  -281,   306,  -281,   111,
    -281,  -281,   303,   -32,   -63,  -281,   146,  -281,   318,   256,
     141,     2,   -17,   -15,  -281,   -54,  -281,   207,  -281,   203,
     -74,  -165,  -122,  -281,  -281,  -136,  -281,   -80,  -281,   -52,
     -24,   226,  -234,  -280,  -281,  -281,  -281,  -281,  -281,   349,
    -281,  -281,  -281
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,   106,   107,   275,   129,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   349,   130,   354,
     158,   230,   159,   122,    53,    54,    45,    46,    26,    27,
      28,    29,    76,    77,    78,   140,   141,    30,    64,    65,
      31,    32,    33,    34,    43,   257,    89,    90,    91,   186,
     258,   174,   132,   218,   160,   161,   251,   255,   162,    83,
      55,   164,   165,   307,   166,   353,   167,   168,    35,    36,
      37,    73,    56
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     108,   121,   131,    88,    84,    25,   217,   261,    42,   311,
     193,   184,   136,   173,   211,    63,   143,    59,    38,    24,
     133,   134,    62,    72,    40,     1,    50,    47,    68,   340,
     125,    48,    49,    69,     1,   185,    52,   180,   182,   183,
      25,   249,     1,     1,   138,   125,    16,    17,   126,    70,
      57,   108,    58,    66,    24,   346,    80,   163,   298,   131,
     207,     1,    87,   214,   215,    74,   108,   121,   248,   241,
     242,    80,   172,    23,    82,   124,   299,   212,   363,   232,
     142,   108,   121,    81,   169,   237,   170,   108,   121,   171,
      71,    82,   184,    22,   184,   279,   280,   281,   208,    39,
      23,    22,    22,   138,   277,   261,   310,    51,   352,    23,
     260,   271,   108,   121,    44,   262,   185,   263,   194,   317,
     169,   276,   170,   195,   196,   175,   269,    23,   170,     1,
     295,   296,   297,   201,   202,   176,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   306,   308,   172,    59,   303,   329,   305,   249,
     209,   300,    75,   233,    41,   197,   198,   335,   177,   337,
     270,    40,   178,   326,    87,   302,   334,   108,   121,   234,
     314,    87,    82,   213,    67,    75,    75,    75,    22,   269,
      75,   170,    79,   199,   200,    23,    23,   203,   204,   315,
     347,   205,   206,   324,   235,   108,   121,   139,   322,    75,
     332,   360,   355,   356,   108,    79,    79,    79,   367,   268,
      79,   362,   306,   249,   336,   249,   249,   374,   369,   131,
     327,   342,   282,   283,   328,   142,   375,   108,   108,    79,
     377,   250,   313,   284,   285,   210,    75,    92,    93,    94,
      95,   339,    96,    97,   270,   249,   370,   236,   348,   345,
     249,   351,   286,   287,   288,   289,   238,    87,   290,   291,
     357,   306,   365,   359,    87,   239,    79,   240,   243,   244,
     366,   245,   246,   266,   272,   254,   273,   372,   278,   304,
      75,   316,   309,   312,   376,   318,   144,    93,    94,    95,
     319,    96,    97,   320,   325,   338,    98,   274,   108,   371,
     249,   341,   100,   101,   102,   103,   104,   105,   343,   344,
      79,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,   350,   145,   146,   147,   368,   148,   149,   150,   151,
     152,   153,   154,   155,   358,    98,   361,   373,   292,   294,
     293,   100,   101,   102,   103,   104,   105,   144,    93,    94,
      95,   330,    96,    97,   331,   127,   156,   135,   157,   301,
     123,   216,   267,   265,    61,    92,    93,    94,    95,   253,
      96,    97,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     0,   145,   146,   147,     0,   148,   149,   150,
     151,   152,   153,   154,   155,     0,    98,   187,   188,   189,
       0,     0,   100,   101,   102,   103,   104,   105,     0,     0,
      92,    93,    94,    95,    98,    96,    97,   156,     0,   252,
     100,   101,   102,   103,   104,   105,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   128,   333,     0,     0,
       0,     0,   144,    93,    94,    95,     0,    96,    97,     0,
       0,     0,   190,     0,   191,     0,   192,     0,    92,    93,
      94,    95,     0,    96,    97,     0,     0,     0,     0,    98,
       0,     0,     0,     0,     0,   100,   101,   102,   103,   104,
     105,    92,    93,    94,    95,     0,    96,    97,   145,   146,
     147,   128,   148,   149,   150,   151,   152,   153,   154,   155,
       0,    98,     0,     0,     0,     0,     0,   100,   101,   102,
     103,   104,   105,     0,     0,     0,     0,    98,     0,     0,
       0,     0,   156,   100,   101,   102,   103,   104,   105,     0,
       0,    92,    93,    94,    95,     0,    96,    97,   247,     0,
      98,     0,     0,     0,     0,     0,   100,   101,   102,   103,
     104,   105,    92,    93,    94,    95,     2,    96,    97,     0,
       0,   156,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    92,    93,    94,    95,
       0,    96,    97,     0,     0,     0,     0,     0,     0,     0,
      98,     0,     0,     0,     0,     0,   100,   101,   102,   103,
     104,   105,    92,    93,    94,    95,     0,    96,    97,     0,
       0,    98,     0,     0,    99,     0,     0,   100,   101,   102,
     103,   104,   105,    92,    93,    94,    95,     0,    96,    97,
       0,     0,     0,     0,     0,    98,     0,     0,   259,     0,
       0,   100,   101,   102,   103,   104,   105,    92,    93,    94,
      95,     0,    96,    97,     0,     0,     0,     0,     0,     0,
       0,    98,     0,     0,   323,     0,     0,   100,   101,   102,
     103,   104,   105,    92,    93,    94,    95,     0,    96,    97,
       0,     0,    98,   364,     0,     0,     0,     0,   100,   101,
     102,   103,   104,   105,    92,    93,    94,    95,     0,    96,
      97,     0,     0,     0,     0,     0,   179,     0,     0,     0,
       0,     0,   100,   101,   102,   103,   104,   105,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   181,     0,     0,     0,     0,     0,   100,   101,
     102,   103,   104,   105,    60,     0,     0,     1,     0,     0,
       0,     0,     0,    98,     0,     0,     0,     0,     0,   100,
     101,   102,   103,   104,   105,     0,     0,     0,     0,     0,
       0,     0,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     1,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,     0,     0,     0,    22,     0,     0,     0,
       0,     0,     0,    23,     0,     0,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     1,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   169,   256,   170,     0,     0,     0,   229,    23,     0,
       0,     0,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    85,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    22,     0,     0,     0,
       0,     0,     0,    23,     0,     0,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     2,     0,     0,
       0,     0,    86,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     2,     0,     0,
       0,     0,     0,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     2,
       0,     0,     0,     0,   137,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     0,
       0,     0,     0,     0,   231,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    71,
       0,  -217,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    81,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   269,   256,   170,     0,
       0,     0,     0,    23,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   321,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
     264,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21
};

static const yytype_int16 yycheck[] =
{
      58,    58,    71,    57,    56,     0,   128,   172,    23,   243,
     109,    98,    75,    87,    17,     3,    79,    34,     3,     0,
      72,    73,    84,    47,    22,     3,     3,    25,    43,   309,
      67,    26,    27,    67,     3,    98,    31,    95,    96,    97,
      35,    67,     3,     3,    76,    67,    42,    43,    85,    83,
      62,   109,    64,    63,    35,    81,    54,    81,    67,   128,
      68,     3,    57,    85,   124,    84,   124,   124,   155,   149,
     150,    69,    87,    69,    55,    82,    85,    80,   358,   139,
      78,   139,   139,    84,    62,   145,    64,   145,   145,    87,
      82,    72,   179,    62,   181,   194,   195,   196,    78,    84,
      69,    62,    62,   135,   191,   270,   242,    84,   342,    69,
     170,   185,   170,   170,    83,    62,   179,    64,    69,   255,
      62,   190,    64,    74,    75,    63,    62,    69,    64,     3,
     210,   211,   212,    12,    13,    67,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   239,   240,   169,   172,   236,    65,   238,    67,
      79,   230,    51,    67,    23,    70,    71,   303,    63,   305,
     185,   169,    67,   272,   169,   235,   298,   235,   235,    83,
     249,   176,   163,    65,    43,    74,    75,    76,    62,    62,
      79,    64,    51,    10,    11,    69,    69,    76,    77,   251,
     336,    14,    15,   263,    81,   263,   263,    81,   262,    98,
     297,   354,   348,   349,   272,    74,    75,    76,   361,    63,
      79,   357,   309,    67,   304,    67,    67,   370,   364,   298,
      63,   311,   197,   198,    67,   233,   372,   295,   296,    98,
     376,    83,    83,   199,   200,    16,   135,     3,     4,     5,
       6,    63,     8,     9,   269,    67,    63,    81,   338,   328,
      67,   341,   201,   202,   203,   204,    81,   262,   205,   206,
     350,   358,   359,   353,   269,    62,   135,    62,    62,     3,
     360,    83,    83,     3,    63,    85,     3,   367,     3,    81,
     179,    85,    62,    83,   374,    63,     3,     4,     5,     6,
      63,     8,     9,    65,    63,    63,    62,    63,   366,   366,
      67,    54,    68,    69,    70,    71,    72,    73,    63,    65,
     179,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    63,    49,    50,    51,    63,    53,    54,    55,    56,
      57,    58,    59,    60,    62,    62,    52,    83,   207,   209,
     208,    68,    69,    70,    71,    72,    73,     3,     4,     5,
       6,   295,     8,     9,   296,    69,    83,    74,    85,   233,
      62,   125,   179,   176,    35,     3,     4,     5,     6,   163,
       8,     9,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    49,    50,    51,    -1,    53,    54,    55,
      56,    57,    58,    59,    60,    -1,    62,     7,     8,     9,
      -1,    -1,    68,    69,    70,    71,    72,    73,    -1,    -1,
       3,     4,     5,     6,    62,     8,     9,    83,    -1,    85,
      68,    69,    70,    71,    72,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    -1,    62,    -1,    64,    -1,    66,    -1,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    68,    69,    70,    71,    72,
      73,     3,     4,     5,     6,    -1,     8,     9,    49,    50,
      51,    84,    53,    54,    55,    56,    57,    58,    59,    60,
      -1,    62,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,
      71,    72,    73,    -1,    -1,    -1,    -1,    62,    -1,    -1,
      -1,    -1,    83,    68,    69,    70,    71,    72,    73,    -1,
      -1,     3,     4,     5,     6,    -1,     8,     9,    83,    -1,
      62,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,    71,
      72,    73,     3,     4,     5,     6,    28,     8,     9,    -1,
      -1,    83,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,    71,
      72,    73,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    62,    -1,    -1,    65,    -1,    -1,    68,    69,    70,
      71,    72,    73,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    65,    -1,
      -1,    68,    69,    70,    71,    72,    73,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    -1,    -1,    65,    -1,    -1,    68,    69,    70,
      71,    72,    73,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    62,    63,    -1,    -1,    -1,    -1,    68,    69,
      70,    71,    72,    73,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    68,    69,    70,    71,    72,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    68,    69,
      70,    71,    72,    73,     0,    -1,    -1,     3,    -1,    -1,
      -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    68,
      69,    70,    71,    72,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,     3,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     3,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    63,    64,    -1,    -1,    -1,    82,    69,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,
      -1,    -1,    63,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    28,    -1,    -1,
      -1,    -1,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      -1,    -1,    -1,    -1,    85,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      -1,    -1,    -1,    -1,    85,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    64,    -1,
      -1,    -1,    -1,    69,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    62,    69,   110,   111,   114,   115,   116,   117,
     123,   126,   127,   128,   129,   154,   155,   156,     3,    84,
     127,   126,   129,   130,    83,   112,   113,   127,   111,   111,
       3,    84,   111,   110,   111,   146,   158,    62,    64,   128,
       0,   155,    84,     3,   124,   125,    63,   126,   129,    67,
      83,    82,   146,   157,    84,   115,   118,   119,   120,   126,
     127,    84,   110,   145,   145,     3,    63,   111,   131,   132,
     133,   134,     3,     4,     5,     6,     8,     9,    62,    65,
      68,    69,    70,    71,    72,    73,    87,    88,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   104,   109,   124,    82,    67,    85,   113,    84,    90,
     104,   106,   138,   145,   145,   118,   120,    85,   119,    81,
     121,   122,   127,   120,     3,    49,    50,    51,    53,    54,
      55,    56,    57,    58,    59,    60,    83,    85,   106,   108,
     140,   141,   144,   146,   147,   148,   150,   152,   153,    62,
      64,   127,   129,   136,   137,    63,    67,    63,    67,    62,
      90,    62,    90,    90,   108,   120,   135,     7,     8,     9,
      62,    64,    66,    92,    69,    74,    75,    70,    71,    10,
      11,    12,    13,    76,    77,    14,    15,    68,    78,    79,
      16,    17,    80,    65,    85,   109,   125,   138,   139,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    82,
     107,    85,   109,    67,    83,    81,    81,   109,    81,    62,
      62,   143,   143,    62,     3,    83,    83,    83,   108,    67,
      83,   142,    85,   147,    85,   143,    63,   131,   136,    65,
     109,   137,    62,    64,    48,   133,     3,   135,    63,    62,
     129,   136,    63,     3,    63,    89,   106,   108,     3,    92,
      92,    92,    93,    93,    94,    94,    95,    95,    95,    95,
      96,    96,    97,    98,    99,   143,   143,   143,    67,    85,
     106,   122,   109,   143,    81,   143,   108,   149,   108,    62,
     141,   148,    83,    83,   106,   145,    85,   141,    63,    63,
      65,    63,   131,    65,   109,    63,    92,    63,    67,    65,
     100,   101,   108,    85,   138,   141,   143,   141,    63,    63,
     149,    54,   143,    63,    65,   106,    81,   141,   143,   103,
      63,   143,   148,   151,   105,   141,   141,   143,    62,   143,
     103,    52,   141,   149,    63,   108,   143,   103,    63,   141,
      63,   104,   143,    83,   103,   141,   143,   141
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    86,    87,    87,    87,    87,    88,    88,    88,    88,
      88,    88,    88,    88,    89,    89,    90,    90,    90,    90,
      90,    90,    91,    91,    91,    91,    91,    91,    92,    92,
      93,    93,    93,    93,    94,    94,    94,    95,    95,    95,
      96,    96,    96,    96,    96,    97,    97,    97,    98,    98,
      99,    99,   100,   100,   101,   101,   102,   102,   103,   104,
     105,   104,   106,   106,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   108,   108,   109,   110,   110,
     111,   111,   111,   111,   111,   111,   112,   112,   113,   113,
     114,   114,   114,   114,   114,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   116,   116,   116,
     117,   117,   118,   118,   119,   120,   120,   120,   120,   121,
     121,   122,   122,   122,   123,   123,   123,   124,   124,   125,
     125,   126,   126,   127,   127,   128,   128,   128,   128,   128,
     128,   128,   129,   129,   129,   129,   130,   130,   131,   131,
     132,   132,   133,   133,   133,   134,   134,   135,   135,   136,
     136,   136,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   138,   138,   138,   139,   139,   140,   141,   142,   141,
     141,   141,   141,   141,   143,   144,   144,   144,   145,   145,
     145,   145,   146,   146,   147,   147,   148,   148,   149,   150,
     150,   150,   151,   152,   152,   152,   152,   153,   153,   153,
     153,   153,   154,   154,   155,   155,   156,   157,   156,   156,
     158,   156
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       3,     3,     2,     2,     1,     3,     1,     2,     2,     2,
       2,     4,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       1,     3,     1,     3,     1,     4,     1,     4,     0,     1,
       0,     9,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     2,     3,
       1,     2,     1,     2,     1,     2,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     4,     2,
       1,     1,     1,     2,     3,     2,     1,     2,     1,     1,
       3,     1,     2,     3,     4,     5,     2,     1,     3,     1,
       3,     1,     1,     2,     1,     1,     3,     4,     3,     4,
       4,     3,     1,     2,     2,     3,     1,     2,     1,     3,
       1,     3,     2,     2,     1,     1,     3,     1,     2,     1,
       1,     2,     3,     2,     3,     3,     4,     2,     3,     3,
       4,     1,     3,     4,     1,     3,     0,     1,     0,     3,
       1,     1,     1,     1,     0,     4,     5,     4,     2,     3,
       3,     4,     1,     2,     1,     3,     1,     2,     1,     6,
      10,     6,     1,     7,     9,     8,    11,     3,     2,     2,
       2,     3,     1,     2,     1,     1,     4,     0,     4,     3,
       0,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* primary_expression: IDENTIFIER  */
#line 167 "ansic.y"
                                                {
									string *name = new string((yyvsp[0].token.name)); /* El nombre es el atributo id del token IDENTIFIER */
									symrec *s = getsym(name);
									if(s == NULL)
									{
										message("Variable %s", (yyvsp[0].token.name));
										yyerror("not declared!");
									}
									printf("primary_expression: IDENTIFIER");
									cout << "<" << *name << ">" << "\n";
									(yyval.sym).var = s; /* La variable de la tabla de simbolos que se encontro con getsym() */
									(yyval.sym).typ = s->typ; /* el tipo se obtuvo de la tabla de simbolos */
									(yyval.sym).dimlist = s->dimlist;
									(yyval.sym).plevel = 0;
								}
#line 1894 "ansic.tab.c"
    break;

  case 3: /* primary_expression: CONSTANT  */
#line 182 "ansic.y"
                                                        {
									symrec *s;
									std::string *name;
									printf("primary_expression: CONSTANT");
									switch((yyvsp[0].token.type))
									{
										case DOUBLEVAL:
											cout << "<(double)" << (yyvsp[0].token.dval) << ">" << "\n";
											name = newtemp(); /* Crear nueva variable temporal */
											s = putsym(name, DOUBLEVAL | CONST_SPEC);
											(yyval.sym).val.doubleval = (yyvsp[0].token.dval);
											*(double *)(datablock+s->offset) = (yyvsp[0].token.dval);
											(yyval.sym).typ = s->typ;
											(yyval.sym).var = s;
											break;
										case INTVAL:
											cout << "<(int)" << (yyvsp[0].token.ival) << ">" << "\n";
											name = newtemp(); /* Crear nueva variable temporal */
											s = putsym(name, INTVAL | CONST_SPEC);
											(yyval.sym).val.intval = (yyvsp[0].token.ival);
											*(int *)(datablock+s->offset) = (yyvsp[0].token.ival);
											(yyval.sym).typ = s->typ;
											(yyval.sym).var = s;
											break;
										case CHARVAL:
											cout << "<(char)" << (yyvsp[0].token.cval) << ">" << "\n";
											name = newtemp(); /* Crear nueva variable temporal */
											s = putsym(name, CHARVAL | CONST_SPEC);
											(yyval.sym).val.charval = (yyvsp[0].token.cval);
											*(char *)(datablock+s->offset) = (yyvsp[0].token.cval);
											(yyval.sym).typ = s->typ;
											(yyval.sym).var = s;
											break;
									}
								}
#line 1934 "ansic.tab.c"
    break;

  case 4: /* primary_expression: STRING_LITERAL  */
#line 217 "ansic.y"
                                                {
									symrec *s;
									std::string *name;
									string *str = new string((yyvsp[0].token.str));
									printf("primary_expression: STRING_LITERAL");
									cout << "<\"" << *str << ">\"" << "\n";
									/* Crear variable temporal para guardar cadena */
									name = newtemp();
									/* Agrefa variable temporal a tabla de simbolos */
									s = putsym(name, STRVAL | CONST_SPEC);
									/* DETERMINA TAMAÑO DE CADENA */
									s->size + strlen((yyvsp[0].token.str))+1;
									/* Copia cadena a bloque de datos datablock */
									memcpy(datablock+s->offset, (yyvsp[0].token.str), s->size);
									/* Incrementar valor de posicion libre en bloque datos */
									data_location(s->size);
									/* Propagar atributos de variables temporal al nodo padre primary_expression */
									(yyval.sym).name = name;
									(yyval.sym).typ = s->typ;
									(yyval.sym).var = s;
								}
#line 1960 "ansic.tab.c"
    break;

  case 5: /* primary_expression: '(' expression ')'  */
#line 238 "ansic.y"
                                        {
									printf("primary_expression: '(' expression ')'\n");
									(yyval.sym) = (yyvsp[-1].sym);
								}
#line 1969 "ansic.tab.c"
    break;

  case 6: /* postfix_expression: primary_expression  */
#line 245 "ansic.y"
                                                                                                        {
																	printf("postfix_expression: primary_expression\n");
																	(yyval.sym) = (yyvsp[0].sym);
																}
#line 1978 "ansic.tab.c"
    break;

  case 7: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 249 "ansic.y"
                                                                                        {
																	printf("postfix_expression: postfix_expression '[' expression ']'\n");
																	(yyval.sym) = (yyvsp[-3].sym);
																	if((yyvsp[-3].sym).var == NULL)
																		yyerror("Error: Array name must be specified");
																	if(!isintegral((yyvsp[-1].sym).typ))
																		yyerror("Array subscript mus be integral!\n");
																	if((yyvsp[-3].sym).plevel > 0)
																	{
																		string *name = newtemp(); /* para sizeof(type) */
																		symrec *s0 = putsym(name, INTVAL | CONST_SPEC);
																		*(int *) (datablock+s0->offset) = getsizeof((yyval.sym).typ);
																		name = newtemp(); /* para dimension N */
																		symrec *s1 = putsym(name, INTVAL | CONST_SPEC);
																		*(int *) (datablock+s1->offset) = getrdim((yyval.sym).dimlist, (yyvsp[-3].sym).plevel - 1);
																		name = newtemp(); /* para resultado de j*sizeof (type) */
																		symrec *s2 = putsym(name, INTVAL | VAR_SPEC);
																		gencode(MULT_IR, (yyvsp[-1].sym).var, s0, s2);
																		name = newtemp(); /* para offset_ant * N */
																		symrec *s3 = putsym(name, INTVAL | VAR_SPEC);
																		gencode(MULT_IR, (yyval.sym).var2, s1, s3);
																		name = newtemp(); /* para calcular offset */
																		symrec *s4 = putsym(name, INTVAL | VAR_SPEC);
																		gencode(ADD_IR, s3, s2, s4);
																		(yyval.sym).var2 = s4;
																	}
																	else
																	{
																		string *name = newtemp();
																		symrec *s1 = putsym(name, INTVAL | CONST_SPEC);
																		*(int *)(datablock+s1->offset) = getsizeof((yyval.sym).typ);
																		name = newtemp();
																		symrec *s2 = putsym(name, INTVAL | VAR_SPEC);
																		gencode(MULT_IR, (yyvsp[-1].sym).var, s1, s2);
																		(yyval.sym).var2 = s2;
																	}
																	//message ("$$.var = %p\n", $$.var);
																	//message ("$$.var2 = %p\n", $$.var2);
																	(yyval.sym).typ |= ARRAY_SPEC;
																	(yyval.sym).plevel++;	
																}
#line 2024 "ansic.tab.c"
    break;

  case 8: /* postfix_expression: postfix_expression '(' ')'  */
#line 290 "ansic.y"
                                                                                                {
																	symrec *s;
																	std::string *name = newtemp();
																	printf("postfix_expression: postfix_expression '(' ')'\n");
																	s = putsym(name, (yyvsp[-2].sym).typ & 0x1F);
																	(yyval.sym).typ = s->typ;
																	gencode(CALL_IR, (yyvsp[-2].sym).var, nullptr, s);
																	(yyval.sym).var = s;
																}
#line 2038 "ansic.tab.c"
    break;

  case 9: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 299 "ansic.y"
                                                                        {
																	printf("postfix_expression: postfix_expression '(' argument_expression_list ')'\n");
																	symrec *s, *s2, *s3;
																	std::list<VAR_DATA *>::reverse_iterator it;
																	std::string *name = newtemp();
																	s = putsym(name, (yyvsp[-3].sym).typ & 0x1F);
																	(yyval.sym).typ = s->typ;
																	for(it = (yyvsp[-1].sym).arglist->rbegin(); it != (yyvsp[-1].sym).arglist->rend(); it++)
																	{
																		gencode(PARAM_IR, (*it)->var, nullptr, nullptr);
																	}
																	s3 = new symrec();
																	s3 -> name = "";
																	s3 -> offset = (yyvsp[-1].sym).arglist->size();
																	gencode(CALL_IR, (yyvsp[-3].sym).var, s3, s);
																	(yyval.sym).var = s;	
																}
#line 2060 "ansic.tab.c"
    break;

  case 10: /* postfix_expression: postfix_expression '.' IDENTIFIER  */
#line 316 "ansic.y"
                                                                                                {printf("postfix_expression: postfix_expression '.' IDENTIFIER\n");}
#line 2066 "ansic.tab.c"
    break;

  case 11: /* postfix_expression: postfix_expression PTR_OP IDENTIFIER  */
#line 317 "ansic.y"
                                                                                        {printf("postfix_expression: postfix_expression PTR_OP IDENTIFIER\n");}
#line 2072 "ansic.tab.c"
    break;

  case 12: /* postfix_expression: postfix_expression INC_OP  */
#line 318 "ansic.y"
                                                                                                        {
																	printf("postfix_expression: postfix_expression INC_OP	\n");
																	if((yyvsp[-1].sym).typ & VAR_SPEC)
																	{
																		/* Crear variables temporal para guardar valor de postfix_expression antes de incremento */
																		std::string *name = newtemp();
																		symrec *s;
																		/* Agregar variable temporal a tabla de simbolos */
																		s = putsym(name, (yyvsp[-1].sym).typ);
																		/* Generar instruccion de codigo intermedio para asignacion */
																		gencode(STORE_IR, (yyvsp[-1].sym).var, nullptr, s);
																		gencode(INC_IR, (yyvsp[-1].sym).var, nullptr, (yyvsp[-1].sym).var);
																		(yyval.sym).name = name;
																		(yyval.sym).typ = (yyvsp[-1].sym).typ;
																		(yyval.sym).var = s;
																	}
																	else
																		yyerror("Error: Operand of increment operator must be an variable\n");

																}
#line 2097 "ansic.tab.c"
    break;

  case 13: /* postfix_expression: postfix_expression DEC_OP  */
#line 338 "ansic.y"
                                                                                                        {
																	printf("postfix_expression: postfix_expression DEC_OP\n");
																	if((yyvsp[-1].sym).typ & VAR_SPEC)
																	{
																		/* Crear variables temporal para guardar valor de postfix_expression antes de incremento */
																		std::string *name = newtemp();
																		symrec *s;
																		/* Agregar variable temporal a tabla de simbolos */
																		s = putsym(name, (yyvsp[-1].sym).typ);
																		/* Generar instruccion de codigo intermedio para asignacion */
																		gencode(STORE_IR, (yyvsp[-1].sym).var, nullptr, s);
																		gencode(DEC_IR, (yyvsp[-1].sym).var, nullptr, (yyvsp[-1].sym).var);
																		(yyval.sym).name = name;
																		(yyval.sym).typ = (yyvsp[-1].sym).typ;
																		(yyval.sym).var = s;
																		
																	}
																	else
																		yyerror("Error: Operand of increment operator must be an variable\n");
																}
#line 2122 "ansic.tab.c"
    break;

  case 14: /* argument_expression_list: assignment_expression  */
#line 361 "ansic.y"
                                                                                                                {
																		printf("argument_expression_list: assignment_expression\n");
																		std::list<VAR_DATA * > *newlist = new std::list<VAR_DATA * >();
																		VAR_DATA * newstruc = new VAR_DATA();
																		*newstruc = (yyvsp[0].sym);
																		newlist->push_back(newstruc);
																		(yyval.sym).name = new std::string();
																		(yyval.sym).typ = 0;
																		(yyval.sym).arglist = newlist;
																	}
#line 2137 "ansic.tab.c"
    break;

  case 15: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 371 "ansic.y"
                                                                                {
																		printf("argument_expression_list: argument_expression_list ',' assignment_expression\n");
																		VAR_DATA * newstruc = new VAR_DATA();
																		*newstruc = (yyvsp[0].sym);
																		(yyval.sym) = (yyvsp[-2].sym);
																		(yyval.sym).arglist->push_back(newstruc);
																	}
#line 2149 "ansic.tab.c"
    break;

  case 16: /* unary_expression: postfix_expression  */
#line 381 "ansic.y"
                                                                {
												printf("unary_expression: postfix_expression\n");
												(yyval.sym) = (yyvsp[0].sym);	
											}
#line 2158 "ansic.tab.c"
    break;

  case 17: /* unary_expression: INC_OP unary_expression  */
#line 385 "ansic.y"
                                                                {
												printf("unary_expression: INC_OP unary_expression\n");
												if((yyvsp[0].sym).typ & VAR_SPEC)
												{
													/* Generar instruccion de codigo intermedio para incremento */
													gencode(INC_IR, (yyvsp[0].sym).var, nullptr, (yyvsp[0].sym).var);
													/* Propagar atributos de variable temporal al nodo padre postfix_expression */
													(yyval.sym).name = (yyvsp[0].sym).name;
													(yyval.sym).typ = (yyvsp[0].sym).typ;
													(yyval.sym).var = (yyvsp[0].sym).var;
												}
												else
													yyerror("Error: Operand of increment operator must be an variable name\n");
											}
#line 2177 "ansic.tab.c"
    break;

  case 18: /* unary_expression: DEC_OP unary_expression  */
#line 399 "ansic.y"
                                                                {
												printf("unary_expression: DEC_OP unary_expression\n");
												if((yyvsp[0].sym).typ & VAR_SPEC)
												{
													/* Generar instruccion de codigo intermedio para incremento */
													gencode(DEC_IR, (yyvsp[0].sym).var, nullptr, (yyvsp[0].sym).var);
													/* Propagar atributos de variable temporal al nodo padre postfix_expression */
													(yyval.sym).name = (yyvsp[0].sym).name;
													(yyval.sym).typ = (yyvsp[0].sym).typ;
													(yyval.sym).var = (yyvsp[0].sym).var;
												}
												else
													yyerror("Error: Operand of increment operator must be an variable name\n");
											}
#line 2196 "ansic.tab.c"
    break;

  case 19: /* unary_expression: unary_operator cast_expression  */
#line 413 "ansic.y"
                                                        {
												std::string *name;
												symrec *s;
												printf("unary_expression: unary_operator cast_expression\n");
												/* Generar instruccion de codigo intermedio */
												switch((yyvsp[-1].op))
												{
													case PLUS_OP:
														name = (yyvsp[0].sym).name;
														s = (yyvsp[0].sym).var;
														(yyval.sym).typ = (yyvsp[0].sym).typ;
														break;
													case ADDR_OP:
														name = newtemp();
														s = putsym(name, INTVAL);
														gencode(ADDRESS_IR, (yyvsp[0].sym).var, nullptr, s);
														(yyval.sym).typ = INTVAL;
														break;
													case DEREF_OP:
														name = newtemp();
														if(!ispointer((yyvsp[0].sym).typ))
															yyerror("Error: Operand must be a pointer\n");
														s = putsym(name, (yyvsp[0].sym).typ & ~POINTER_SPEC);
														gencode(DEREF_IR, (yyvsp[0].sym).var, nullptr, s);
														(yyval.sym).typ = (yyvsp[0].sym).typ;
														break;
													case MINUS_OP:
														name = newtemp();
														s = putsym(name, (yyvsp[0].sym).typ);
														gencode(MINUS_IR, (yyvsp[0].sym).var, nullptr, s);
														(yyval.sym).typ = (yyvsp[0].sym).typ;
														break;
													case TWOCOMP_OP:
														name = newtemp();
														s = putsym(name, INTVAL);
														gencode(TWOCOMP_IR, (yyvsp[0].sym).var, nullptr, s);
														(yyval.sym).typ = INTVAL;
														break;
													case NOT_OP:
														name = newtemp();
														/*s = putsym(name, INTVAL);
														gencode(NOT_IR, $2.var, nullptr, s);*/
														(yyval.sym).truelist = (yyvsp[0].sym).falselist;
														(yyval.sym).falselist = (yyvsp[0].sym).truelist;
														(yyval.sym).typ = INTVAL;
														break;
												}
												(yyval.sym).name = name;
												(yyval.sym).var = s;	
											}
#line 2251 "ansic.tab.c"
    break;

  case 20: /* unary_expression: SIZEOF unary_expression  */
#line 463 "ansic.y"
                                                                {
												printf("unary_expression: SIZEOF unary_expression\n");
												/* Crear variable temporal para guardar valor tamaño de unary_expression*/
												std::string *name = newtemp();
												symrec *s;
												/* Agregar variable temporal a tabla de simbolos */
												s = putsym(name, INTVAL | CONST_SPEC);
												/* Copiar tamaño de unary_espression en bloques de datos datablack */
												*(int *)(datablock+s->offset) = getsizeof((yyvsp[0].sym).typ);
												/* Propagar atributos de postfix_expression al nodo padre unary_expression */
												(yyval.sym).name = name;
												(yyval.sym).typ = INTVAL | CONST_SPEC;
												(yyval.sym).var = s;
											}
#line 2270 "ansic.tab.c"
    break;

  case 21: /* unary_expression: SIZEOF '(' type_name ')'  */
#line 477 "ansic.y"
                                                                {
												printf("unary_expression: SIZEOF '(' type_name ')'\n");
												/* Crear variable temporal para guardar valor tamaño de unary_expression*/
												std::string *name = newtemp();
												symrec *s;
												/* Agregar variable temporal a tabla de simbolos */
												s = putsym(name, INTVAL | CONST_SPEC);
												/* Copiar tamaño de unary_espression en bloques de datos datablack */
												*(int *)(datablock+s->offset) = getsizeof((yyvsp[-1].typ));
												/* Propagar atributos de postfix_expression al nodo padre unary_expression */
												(yyval.sym).name = name;
												(yyval.sym).typ = INTVAL | CONST_SPEC;
												(yyval.sym).var = s;
											}
#line 2289 "ansic.tab.c"
    break;

  case 22: /* unary_operator: '&'  */
#line 494 "ansic.y"
                                                                                {
												printf("unary_operator: '&'\n");
												(yyval.op) = ADDR_OP;
											}
#line 2298 "ansic.tab.c"
    break;

  case 23: /* unary_operator: '*'  */
#line 498 "ansic.y"
                                                                                {
												printf("unary_operator: '*'\n");
												(yyval.op) = DEREF_OP;
											}
#line 2307 "ansic.tab.c"
    break;

  case 24: /* unary_operator: '+'  */
#line 502 "ansic.y"
                                                                                {
												printf("unary_operator: '+'\n");
												(yyval.op) = PLUS_OP;
											}
#line 2316 "ansic.tab.c"
    break;

  case 25: /* unary_operator: '-'  */
#line 506 "ansic.y"
                                                                                {
												printf("unary_operator: '-'\n");
												(yyval.op) = MINUS_OP;
											}
#line 2325 "ansic.tab.c"
    break;

  case 26: /* unary_operator: '~'  */
#line 510 "ansic.y"
                                                                                {
												printf("unary_operator: '~'\n");
												(yyval.op) = TWOCOMP_OP;
											}
#line 2334 "ansic.tab.c"
    break;

  case 27: /* unary_operator: '!'  */
#line 514 "ansic.y"
                                                                                {
												printf("unary_operator: '!'\n");
												(yyval.op) = NOT_OP;
											}
#line 2343 "ansic.tab.c"
    break;

  case 28: /* cast_expression: unary_expression  */
#line 521 "ansic.y"
                                                                        {
												printf("cast_expression: unary_expression\n");
												(yyval.sym) = (yyvsp[0].sym);	
												if(isarray((yyvsp[0].sym).typ))
												{
													std::string *name = newtemp();
													symrec *s;
													s = putsym(name, (yyvsp[0].sym).typ & ~ARRAY_SPEC);
													gencode(LOADA_IR, (yyvsp[0].sym).var, (yyvsp[0].sym).var2, s);
													(yyval.sym).name = name;
													//cout << "yar =" << *name << endl;
													(yyval.sym).typ = s->typ;
													(yyval.sym).var = s;
												}
											}
#line 2363 "ansic.tab.c"
    break;

  case 29: /* cast_expression: '(' type_name ')' cast_expression  */
#line 536 "ansic.y"
                                                        {
												printf("cast_expression: '(' type_name ')' cast_expression\n");
												std::string *name = newtemp(); /* Crear nueva variable temporal para resultados */
												symrec *s;
												int typ = (yyvsp[-2].typ) & 0x1F;
												switch(typ)
												{
													case CHARVAL:
														s=putsym(name, CHARVAL | VAR_SPEC);
														gencode(CALL_IR, (yyvsp[0].sym).var, NULL, s);
														break;
													case INTVAL:
														s=putsym(name, INTVAL | VAR_SPEC);
														gencode(INT_IR, (yyvsp[0].sym).var, NULL, s);
														break;
													case FVAL:
														s=putsym(name, FVAL | VAR_SPEC);
														gencode(FLOAT_IR, (yyvsp[0].sym).var, NULL, s);
														break;
													/*case DOUBLEVAL
														s=putsym(name, DOUBLEVAL | VAR_SPEC);
														gencode(DOUBLEVAL_IR, $4.var, NULL, s);
														break;*/
												}
												(yyval.sym).name = name;
												(yyval.sym).typ = s->typ;
												(yyval.sym).var = s;	
											}
#line 2396 "ansic.tab.c"
    break;

  case 30: /* multiplicative_expression: cast_expression  */
#line 567 "ansic.y"
                                                                                                        {
																printf("multiplicative_expression: cast_expression\n");
																(yyval.sym) = (yyvsp[0].sym);	
															}
#line 2405 "ansic.tab.c"
    break;

  case 31: /* multiplicative_expression: multiplicative_expression '*' cast_expression  */
#line 571 "ansic.y"
                                                                        {
																printf("multiplicative_expression: multiplicative_expression '*' cast_expression\n");
																std::string *name = newtemp(); /* Crear nueva variable temporal para resultado*/
																symrec *s;
																s = putsym(name, gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & ~CONST_SPEC | VAR_SPEC);/* Agregar variable temporal a tabla de simbolos */
																gencode(MULT_IR, (yyvsp[-2].sym).var, (yyvsp[0].sym).var, s);/*Genera godigo intermedio de resta */
																(yyval.sym).name = name;
																(yyval.sym).var = s;	
															}
#line 2419 "ansic.tab.c"
    break;

  case 32: /* multiplicative_expression: multiplicative_expression '/' cast_expression  */
#line 580 "ansic.y"
                                                                        {
																printf("multiplicative_expression: multiplicative_expression '/' cast_expression\n");
																std::string *name = newtemp(); /* Crear nueva variable temporal para resultado*/
																symrec *s;
																s = putsym(name, gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & ~CONST_SPEC | VAR_SPEC);/* Agregar variable temporal a tabla de simbolos */
																gencode(DIV_IR, (yyvsp[-2].sym).var, (yyvsp[0].sym).var, s);/*Genera godigo intermedio de resta */
																(yyval.sym).name = name;
																(yyval.sym).var = s;
															}
#line 2433 "ansic.tab.c"
    break;

  case 33: /* multiplicative_expression: multiplicative_expression '%' cast_expression  */
#line 589 "ansic.y"
                                                                        {
																printf("multiplicative_expression: multiplicative_expression '%%' cast_expression\n");
																std::string *name = newtemp(); /* Crear nueva variable temporal para resultado*/
																symrec *s;
																s = putsym(name, gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & ~CONST_SPEC | VAR_SPEC);/* Agregar variable temporal a tabla de simbolos */
																gencode(MOD_IR, (yyvsp[-2].sym).var, (yyvsp[0].sym).var, s);/*Genera godigo intermedio de resta */
																(yyval.sym).name = name;
																(yyval.sym).var = s;
															}
#line 2447 "ansic.tab.c"
    break;

  case 34: /* additive_expression: multiplicative_expression  */
#line 601 "ansic.y"
                                                                                                {
																printf("additive_expression: multiplicative_expression	\n");
																(yyval.sym) = (yyvsp[0].sym);	
															}
#line 2456 "ansic.tab.c"
    break;

  case 35: /* additive_expression: additive_expression '+' multiplicative_expression  */
#line 605 "ansic.y"
                                                                        {
																printf("additive_expression: additive_expression '+' multiplicative_expression\n");
																std::string *name = newtemp(); /* Crear nueva variable temporar para resultado */
																symrec *s;
																s = putsym(name, gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & ~CONST_SPEC | VAR_SPEC);
																gencode(ADD_IR, (yyvsp[-2].sym).var, (yyvsp[0].sym).var, s);
																(yyval.sym).name = name;
																(yyval.sym).var = s;
															}
#line 2470 "ansic.tab.c"
    break;

  case 36: /* additive_expression: additive_expression '-' multiplicative_expression  */
#line 614 "ansic.y"
                                                                        {
																printf("additive_expression: additive_expression '-' multiplicative_expression\n");
																std::string *name = newtemp(); /* Crear nueva variable temporar para resultado */
																symrec *s;
																s = putsym(name, gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & ~CONST_SPEC | VAR_SPEC);
																gencode(SUB_IR, (yyvsp[-2].sym).var, (yyvsp[0].sym).var, s);
																(yyval.sym).name = name;
																(yyval.sym).var = s;
															}
#line 2484 "ansic.tab.c"
    break;

  case 37: /* shift_expression: additive_expression  */
#line 626 "ansic.y"
                                                                                                {
																printf("shift_expression: additive_expression\n");
																(yyval.sym) = (yyvsp[0].sym);	
															}
#line 2493 "ansic.tab.c"
    break;

  case 38: /* shift_expression: shift_expression LEFT_OP additive_expression  */
#line 630 "ansic.y"
                                                                        {printf("shift_expression: shift_expression LEFT_OP additive_expression\n");}
#line 2499 "ansic.tab.c"
    break;

  case 39: /* shift_expression: shift_expression RIGHT_OP additive_expression  */
#line 631 "ansic.y"
                                                                        {printf("shift_expression: shift_expression RIGHT_OP additive_expression\n");}
#line 2505 "ansic.tab.c"
    break;

  case 40: /* relational_expression: shift_expression  */
#line 635 "ansic.y"
                                                                                                        {
																printf("relational_expression: shift_expression\n");
																(yyval.sym) = (yyvsp[0].sym);	
															}
#line 2514 "ansic.tab.c"
    break;

  case 41: /* relational_expression: relational_expression '<' shift_expression  */
#line 639 "ansic.y"
                                                                        {
																printf("relational_expression: relational_expression '<' shift_expression\n");
																symrec *s1 = (yyvsp[-2].sym).var, *s2 = (yyvsp[0].sym).var;
																(yyval.sym).truelist = makelist(nextinstr);
																gencode(IF_LT_IR, s1, s2, nullptr);
																(yyval.sym).falselist = makelist (nextinstr);
																gencode(GOTO_IR);
															}
#line 2527 "ansic.tab.c"
    break;

  case 42: /* relational_expression: relational_expression '>' shift_expression  */
#line 647 "ansic.y"
                                                                        {
																printf("relational_expression: relational_expression '>' shift_expression\n");
																symrec *s1 = (yyvsp[-2].sym).var, *s2 = (yyvsp[0].sym).var;
																(yyval.sym).truelist = makelist(nextinstr);
																gencode(IF_GT_IR, s1, s2, nullptr);
																(yyval.sym).falselist = makelist (nextinstr);
																gencode(GOTO_IR);
															}
#line 2540 "ansic.tab.c"
    break;

  case 43: /* relational_expression: relational_expression LE_OP shift_expression  */
#line 655 "ansic.y"
                                                                        {
																printf("relational_expression: relational_expression LE_OP shift_expression\n");
																symrec *s1 = (yyvsp[-2].sym).var, *s2 = (yyvsp[0].sym).var;
																(yyval.sym).truelist = makelist(nextinstr);
																gencode(IF_LE_IR, s1, s2, nullptr);
																(yyval.sym).falselist = makelist (nextinstr);
																gencode(GOTO_IR);
															}
#line 2553 "ansic.tab.c"
    break;

  case 44: /* relational_expression: relational_expression GE_OP shift_expression  */
#line 663 "ansic.y"
                                                                        {
																printf("relational_expression: relational_expression GE_OP shift_expression\n");
																symrec *s1 = (yyvsp[-2].sym).var, *s2 = (yyvsp[0].sym).var;
																(yyval.sym).truelist = makelist(nextinstr);
																gencode(IF_GE_IR, s1, s2, nullptr);
																(yyval.sym).falselist = makelist (nextinstr);
																gencode(GOTO_IR);
															}
#line 2566 "ansic.tab.c"
    break;

  case 45: /* equality_expression: relational_expression  */
#line 674 "ansic.y"
                                                                                                {
																printf("equality_expression: relational_expression	\n");
																(yyval.sym) = (yyvsp[0].sym);
															}
#line 2575 "ansic.tab.c"
    break;

  case 46: /* equality_expression: equality_expression EQ_OP relational_expression  */
#line 678 "ansic.y"
                                                                        {
																printf("equality_expression: equality_expression EQ_OP relational_expression\n");
																symrec *s1 = (yyvsp[-2].sym).var, *s2 = (yyvsp[0].sym).var;
																(yyval.sym).truelist = makelist(nextinstr);
																gencode(IF_EQ_IR, s1, s2, nullptr);
																(yyval.sym).falselist = makelist (nextinstr);
																gencode(GOTO_IR);
															}
#line 2588 "ansic.tab.c"
    break;

  case 47: /* equality_expression: equality_expression NE_OP relational_expression  */
#line 686 "ansic.y"
                                                                        {
																printf("equality_expression: equality_expression NE_OP relational_expression\n");
																symrec *s1 = (yyvsp[-2].sym).var, *s2 = (yyvsp[0].sym).var;
																(yyval.sym).truelist = makelist(nextinstr);
																gencode(IF_NE_IR, s1, s2, nullptr);
																(yyval.sym).falselist = makelist (nextinstr);
																gencode(GOTO_IR);
															}
#line 2601 "ansic.tab.c"
    break;

  case 48: /* and_expression: equality_expression  */
#line 697 "ansic.y"
                                                                                                {
																printf("and_expression: equality_expression\n");
																(yyval.sym) = (yyvsp[0].sym);
															}
#line 2610 "ansic.tab.c"
    break;

  case 49: /* and_expression: and_expression '&' equality_expression  */
#line 701 "ansic.y"
                                                                                {
																printf("and_expression: and_expression '&' equality_expression\n");
																std::string *name = newtemp(); /* Crear nueva variable temporal para resultados */
																symrec *s;
																s = putsym(name, gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & ~CONST_SPEC | VAR_SPEC);
																gencode(AND_IR, (yyvsp[-2].sym).var, (yyvsp[0].sym).var, s);
																(yyval.sym).name = name;
																(yyval.sym).var = s;
															}
#line 2624 "ansic.tab.c"
    break;

  case 50: /* exclusive_or_expression: and_expression  */
#line 713 "ansic.y"
                                                                                                        {
																printf("exclusive_or_expression: and_expression\n");
																(yyval.sym) = (yyvsp[0].sym);	
															}
#line 2633 "ansic.tab.c"
    break;

  case 51: /* exclusive_or_expression: exclusive_or_expression '^' and_expression  */
#line 717 "ansic.y"
                                                                        {
																printf("exclusive_or_expression: exclusive_or_expression '^' and_expression\n");
																std::string *name = newtemp(); /* Crear nueva variable temporal para resultados */
																symrec *s;
																s = putsym(name, gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & ~CONST_SPEC | VAR_SPEC);
																gencode(XOR_IR, (yyvsp[-2].sym).var, (yyvsp[0].sym).var, s);
																(yyval.sym).name = name;
																(yyval.sym).var = s;
															}
#line 2647 "ansic.tab.c"
    break;

  case 52: /* inclusive_or_expression: exclusive_or_expression  */
#line 729 "ansic.y"
                                                                                                {
																printf("inclusive_or_expression: exclusive_or_expression\n");
																(yyval.sym) = (yyvsp[0].sym);	
															}
#line 2656 "ansic.tab.c"
    break;

  case 53: /* inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression  */
#line 733 "ansic.y"
                                                                {
																printf("inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression\n");
																std::string *name = newtemp(); /* Crear nueva variable temporal para resultados */
																symrec *s;
																s = putsym(name, gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & ~CONST_SPEC | VAR_SPEC);
																gencode(OR_IR, (yyvsp[-2].sym).var, (yyvsp[0].sym).var, s);
																(yyval.sym).name = name;
																(yyval.sym).var = s;
															}
#line 2670 "ansic.tab.c"
    break;

  case 54: /* logical_and_expression: inclusive_or_expression  */
#line 745 "ansic.y"
                                                                                                {
																printf("logical_and_expression: inclusive_or_expression	\n");
																(yyval.sym) = (yyvsp[0].sym);	
															}
#line 2679 "ansic.tab.c"
    break;

  case 55: /* logical_and_expression: logical_and_expression AND_OP N inclusive_or_expression  */
#line 749 "ansic.y"
                                                                        {
																	printf("logical_and_expression: logical_and_expression AND_OP inclusive_or_expression\n");
																	backpatch((yyvsp[-3].sym).truelist, (yyvsp[-1].instr));
																	(yyval.sym).truelist = (yyvsp[0].sym).truelist;
																	(yyval.sym).falselist = (yyvsp[-3].sym).falselist;
																	(yyval.sym).falselist->merge(*((yyvsp[0].sym).falselist));
																	(yyval.sym).typ = INTVAL;
																}
#line 2692 "ansic.tab.c"
    break;

  case 56: /* logical_or_expression: logical_and_expression  */
#line 761 "ansic.y"
                                                                                                {
																printf("logical_or_expression: logical_and_expression	\n");
																(yyval.sym) = (yyvsp[0].sym);	
															}
#line 2701 "ansic.tab.c"
    break;

  case 57: /* logical_or_expression: logical_or_expression OR_OP N logical_and_expression  */
#line 765 "ansic.y"
                                                                {
																printf("logical_or_expression: logical_or_expression OR_OP logical_and_expression\n");
																backpatch((yyvsp[-3].sym).falselist, (yyvsp[-1].instr));
																(yyval.sym).falselist = (yyvsp[0].sym).falselist;
																(yyval.sym).truelist = (yyvsp[-3].sym).truelist;
																(yyval.sym).truelist->merge(*((yyvsp[0].sym).truelist));
																(yyval.sym).typ = INTVAL;
															}
#line 2714 "ansic.tab.c"
    break;

  case 58: /* M: %empty  */
#line 774 "ansic.y"
                                                                                                                { /* Agrega direccion de siguiente instruccion de IR en atributo nextlist y generar instruccion de salto pendiente*/
																(yyval.lists).nextlist = makelist(nextinstr);
																gencode(GOTO_IR);
															}
#line 2723 "ansic.tab.c"
    break;

  case 59: /* conditional_expression: logical_or_expression  */
#line 779 "ansic.y"
                                                                                                                                {
																				printf("conditional_expression: logical_or_expression	\n");
																				(yyval.sym) = (yyvsp[0].sym);
																			}
#line 2732 "ansic.tab.c"
    break;

  case 60: /* $@1: %empty  */
#line 783 "ansic.y"
                                                                                                        {
																				string *name = newtemp();
																				symrec *s = putsym(name, (yyvsp[-1].sym).typ & ~CONST_SPEC | VAR_SPEC);
																				gencode(STORE_IR, (yyvsp[-1].sym).var, NULL, s);
																				(yyvsp[-1].sym).var = s;
																			}
#line 2743 "ansic.tab.c"
    break;

  case 61: /* conditional_expression: logical_or_expression '?' N expression ':' $@1 M N conditional_expression  */
#line 790 "ansic.y"
                                                                                                                                {
																				//printf("conditional_expression: logical_or_expression '?' expression ':' conditional_expression\n");
																				gencode(STORE_IR, (yyvsp[0].sym).var, NULL, (yyvsp[-5].sym).var);
																				(yyval.sym).var = (yyvsp[-5].sym).var;
																				backpatch((yyvsp[-8].sym).truelist, (yyvsp[-6].instr));
																				backpatch((yyvsp[-8].sym).falselist, (yyvsp[-1].instr));
																				backpatch((yyvsp[-2].lists).nextlist, nextinstr);
																				(yyval.sym).truelist = nullptr;
																				(yyval.sym).falselist = nullptr;	
																			}
#line 2758 "ansic.tab.c"
    break;

  case 62: /* assignment_expression: conditional_expression  */
#line 803 "ansic.y"
                                                                                                                {
																		printf("assignment_expression: conditional_expression\n");
																		(yyval.sym) = (yyvsp[0].sym);
																	}
#line 2767 "ansic.tab.c"
    break;

  case 63: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 807 "ansic.y"
                                                                        {
																		printf("assignment_expression: unary_expression assignment_operator assignment_expression\n");
																		/* Verificar si hay saltos pendientes en assignment_expression
																			si los hay, asignar el valor logico 0 o 1.
																		*/
																		if((yyvsp[0].sym).truelist || (yyvsp[0].sym).falselist)
																		{
																			std::string *name = newtemp(); /* Nueva variable temporal */
																			symrec *s1, *s0;
																			s0 = putsym(name, INTVAL | CONST_SPEC);
																			*(int *)(datablock+s0->offset) = 0;
																			name = newtemp();
																			s1 = putsym(name, INTVAL | CONST_SPEC);
																			*(int *)(datablock+s1->offset) = 1;
																			name = newtemp();
																			(yyvsp[0].sym).var = putsym(name, INTVAL | CONST_SPEC);
																			(yyvsp[0].sym).typ = INTVAL | VAR_SPEC;
																			(yyvsp[0].sym).name = name;
																			backpatch((yyvsp[0].sym).truelist, nextinstr);
																			gencode(STORE_IR, s1, nullptr, (yyvsp[0].sym).var);
																			gencode(GOTO_IR, nullptr, nullptr, nextinstr+2);
																			backpatch((yyvsp[0].sym).falselist, nextinstr);
																			gencode(STORE_IR, s0, nullptr, (yyvsp[0].sym).var);
																		}	
																		/* Comparar el atributo de assignment_operator ($2) */
																		switch((yyvsp[-1].asop))
																		{
																			case EQ_ASSIGN_OP:
																				if(!isarray((yyvsp[-2].sym).typ))
																					gencode(STORE_IR, (yyvsp[0].sym).var, nullptr, (yyvsp[-2].sym).var);
																				else
																					gencode(STORE_IR, (yyvsp[0].sym).var, (yyvsp[-2].sym).var2, (yyvsp[-2].sym).var);
																				break;
																			case MUL_ASSIGN_OP:
																				if(!isarray((yyvsp[-2].sym).typ))
																				{
																					std::string *name = newtemp(); /* Crear nueva variable temporal para resultado*/
																					symrec *s;
																					s = putsym(name, gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & ~CONST_SPEC | VAR_SPEC);
																					gencode(MULT_IR, (yyvsp[-2].sym).var, (yyvsp[0].sym).var, s);
																					gencode(STORE_IR, s, nullptr, (yyvsp[-2].sym).var);
																				}
																				else
																				{
																					std::string *name = newtemp();
																					std::string *name1 = newtemp(); /* Crear nueva variable temporal para resultado*/
																					symrec *s , *result;
																					s = putsym(name, (yyvsp[-2].sym).typ & ~ARRAY_SPEC | VAR_SPEC);
																					result = putsym(name1, gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & ~ARRAY_SPEC | VAR_SPEC);
																					gencode(LOADA_IR, (yyvsp[-2].sym).var, (yyvsp[-2].sym).var2, s);
																					gencode(MULT_IR, s, (yyvsp[0].sym).var, result);
																					gencode(STORE_IR, result, (yyvsp[-2].sym).var2, (yyvsp[-2].sym).var);
																				}
																				break;
																			case DIV_ASSIGN_OP:
																				if(!isarray((yyvsp[-2].sym).typ))
																				{
																					std::string *name = newtemp(); /* Crear nueva variable temporal para resultados */
																					symrec *s;
																					s = putsym(name, gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & ~CONST_SPEC | VAR_SPEC);
																					gencode(DIV_IR, (yyvsp[-2].sym).var, (yyvsp[0].sym).var, s);
																					gencode(STORE_IR, s, nullptr, (yyvsp[-2].sym).var);
																				}
																				else
																				{
																					std::string *name = newtemp();
																					std::string *name1 = newtemp(); /* Crear nueva variable temporal para resultado*/
																					symrec *s , *result;
																					s = putsym(name, (yyvsp[-2].sym).typ & ~ARRAY_SPEC | VAR_SPEC);
																					result = putsym(name1, gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & ~ARRAY_SPEC | VAR_SPEC);
																					gencode(LOADA_IR, (yyvsp[-2].sym).var, (yyvsp[-2].sym).var2, s);
																					gencode(DIV_IR, s, (yyvsp[0].sym).var, result);
																					gencode(STORE_IR, result, (yyvsp[-2].sym).var2, (yyvsp[-2].sym).var);
																				}
																				break;
																			case MOD_ASSIGN_OP:
																				if(!isarray((yyvsp[-2].sym).typ))
																				{
																					std::string *name = newtemp(); /* Crear nueva variable temporal para resultados */
																					symrec *s;
																					s = putsym(name, gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & ~CONST_SPEC | VAR_SPEC);
																					gencode(MOD_IR, (yyvsp[-2].sym).var, (yyvsp[0].sym).var, s);
																					gencode(STORE_IR, s, nullptr, (yyvsp[-2].sym).var);
																				}
																				else
																				{
																					std::string *name = newtemp();
																					std::string *name1 = newtemp(); /* Crear nueva variable temporal para resultado*/
																					symrec *s , *result;
																					s = putsym(name, (yyvsp[-2].sym).typ & ~ARRAY_SPEC | VAR_SPEC);
																					result = putsym(name1, gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & ~ARRAY_SPEC | VAR_SPEC);
																					gencode(LOADA_IR, (yyvsp[-2].sym).var, (yyvsp[-2].sym).var2, s);
																					gencode(MOD_IR, s, (yyvsp[0].sym).var, result);
																					gencode(STORE_IR, result, (yyvsp[-2].sym).var2, (yyvsp[-2].sym).var);
																				}
																				break;
																			case ADD_ASSIGN_OP:
																				if(!isarray((yyvsp[-2].sym).typ))
																				{
																					std::string *name = newtemp(); /* Crear nueva variable temporal para resultados */
																					symrec *s;
																					s = putsym(name, gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & ~CONST_SPEC | VAR_SPEC);
																					gencode(ADD_IR, (yyvsp[-2].sym).var, (yyvsp[0].sym).var, s);
																					gencode(STORE_IR, s, nullptr, (yyvsp[-2].sym).var);
																				}
																				else
																				{
																					std::string *name = newtemp();
																					std::string *name1 = newtemp(); /* Crear nueva variable temporal para resultado*/
																					symrec *s , *result;
																					s = putsym(name, (yyvsp[-2].sym).typ & ~ARRAY_SPEC | VAR_SPEC);
																					result = putsym(name1, gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & ~ARRAY_SPEC | VAR_SPEC);
																					gencode(LOADA_IR, (yyvsp[-2].sym).var, (yyvsp[-2].sym).var2, s);
																					gencode(ADD_IR, s, (yyvsp[0].sym).var, result);
																					gencode(STORE_IR, result, (yyvsp[-2].sym).var2, (yyvsp[-2].sym).var);
																				}
																				break;
																			case SUB_ASSIGN_OP:
																				if(!isarray((yyvsp[-2].sym).typ))
																				{
																					std::string *name = newtemp(); /* Crear nueva variable temporal para resultados */
																					symrec *s;
																					s = putsym(name, gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & ~CONST_SPEC | VAR_SPEC);
																					gencode(SUB_IR, (yyvsp[-2].sym).var, (yyvsp[0].sym).var, s);
																					gencode(STORE_IR, s, nullptr, (yyvsp[-2].sym).var);
																				}
																				else
																				{
																					std::string *name = newtemp();
																					std::string *name1 = newtemp(); /* Crear nueva variable temporal para resultado*/
																					symrec *s , *result;
																					s = putsym(name, (yyvsp[-2].sym).typ & ~ARRAY_SPEC | VAR_SPEC);
																					result = putsym(name1, gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & ~ARRAY_SPEC | VAR_SPEC);
																					gencode(LOADA_IR, (yyvsp[-2].sym).var, (yyvsp[-2].sym).var2, s);
																					gencode(SUB_IR, s, (yyvsp[0].sym).var, result);
																					gencode(STORE_IR, result, (yyvsp[-2].sym).var2, (yyvsp[-2].sym).var);
																				}
																				break;
																			case LEFT_ASSIGN_OP:
																				if(!isarray((yyvsp[-2].sym).typ))
																				{
																					std::string *name = newtemp(); /* Crear nueva variable temporal para resultados */
																					symrec *s;
																					s = putsym(name, gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & ~CONST_SPEC | VAR_SPEC);
																					gencode(LSHIFT_IR, (yyvsp[-2].sym).var, (yyvsp[0].sym).var, s);
																					gencode(STORE_IR, s, nullptr, (yyvsp[-2].sym).var);
																				}
																				else
																				{
																					std::string *name = newtemp();
																					std::string *name1 = newtemp(); /* Crear nueva variable temporal para resultado*/
																					symrec *s , *result;
																					s = putsym(name, (yyvsp[-2].sym).typ & ~ARRAY_SPEC | VAR_SPEC);
																					result = putsym(name1, gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & ~ARRAY_SPEC | VAR_SPEC);
																					gencode(LOADA_IR, (yyvsp[-2].sym).var, (yyvsp[-2].sym).var2, s);
																					gencode(LSHIFT_IR, s, (yyvsp[0].sym).var, result);
																					gencode(STORE_IR, result, (yyvsp[-2].sym).var2, (yyvsp[-2].sym).var);
																				}
																				break;
																			case RIGHT_ASSIGN_OP:
																				if(!isarray((yyvsp[-2].sym).typ))
																				{
																					std::string *name = newtemp(); /* Crear nueva variable temporal para resultados */
																					symrec *s;
																					s = putsym(name, gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & ~CONST_SPEC | VAR_SPEC);
																					gencode(RSHIFT_IR, (yyvsp[-2].sym).var, (yyvsp[0].sym).var, s);
																					gencode(STORE_IR, s, nullptr, (yyvsp[-2].sym).var);
																				}
																				else
																				{
																					std::string *name = newtemp();
																					std::string *name1 = newtemp(); /* Crear nueva variable temporal para resultado*/
																					symrec *s , *result;
																					s = putsym(name, (yyvsp[-2].sym).typ & ~ARRAY_SPEC | VAR_SPEC);
																					result = putsym(name1, gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & ~ARRAY_SPEC | VAR_SPEC);
																					gencode(LOADA_IR, (yyvsp[-2].sym).var, (yyvsp[-2].sym).var2, s);
																					gencode(LSHIFT_IR, s, (yyvsp[0].sym).var, result);
																					gencode(STORE_IR, result, (yyvsp[-2].sym).var2, (yyvsp[-2].sym).var);
																				}
																				break;
																			case AND_ASSIGN_OP:
																				if(!isarray((yyvsp[-2].sym).typ))
																				{
																					std::string *name = newtemp(); /* Crear nueva variable temporal para resultados */
																					symrec *s;
																					s = putsym(name, gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & ~CONST_SPEC | VAR_SPEC);
																					gencode(AND_IR, (yyvsp[-2].sym).var, (yyvsp[0].sym).var, s);
																					gencode(STORE_IR, s, nullptr, (yyvsp[-2].sym).var);
																				}
																				else
																				{
																					std::string *name = newtemp();
																					std::string *name1 = newtemp(); /* Crear nueva variable temporal para resultado*/
																					symrec *s , *result;
																					s = putsym(name, (yyvsp[-2].sym).typ & ~ARRAY_SPEC | VAR_SPEC);
																					result = putsym(name1, gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & ~ARRAY_SPEC | VAR_SPEC);
																					gencode(LOADA_IR, (yyvsp[-2].sym).var, (yyvsp[-2].sym).var2, s);
																					gencode(AND_IR, s, (yyvsp[0].sym).var, result);
																					gencode(STORE_IR, result, (yyvsp[-2].sym).var2, (yyvsp[-2].sym).var);
																				}
																				break;
																			case XOR_ASSIGN_OP:
																				if(!isarray((yyvsp[-2].sym).typ))
																				{
																					std::string *name = newtemp(); /* Crear nueva variable temporal para resultados */
																					symrec *s;
																					s = putsym(name, gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & ~CONST_SPEC | VAR_SPEC);
																					gencode(XOR_IR, (yyvsp[-2].sym).var, (yyvsp[0].sym).var, s);
																					gencode(STORE_IR, s, nullptr, (yyvsp[-2].sym).var);
																				}
																				else
																				{
																					std::string *name = newtemp();
																					std::string *name1 = newtemp(); /* Crear nueva variable temporal para resultado*/
																					symrec *s , *result;
																					s = putsym(name, (yyvsp[-2].sym).typ & ~ARRAY_SPEC | VAR_SPEC);
																					result = putsym(name1, gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & ~ARRAY_SPEC | VAR_SPEC);
																					gencode(LOADA_IR, (yyvsp[-2].sym).var, (yyvsp[-2].sym).var2, s);
																					gencode(XOR_IR, s, (yyvsp[0].sym).var, result);
																					gencode(STORE_IR, result, (yyvsp[-2].sym).var2, (yyvsp[-2].sym).var);
																				}
																				break;
																			case OR_ASSIGN_OP:
																				if(!isarray((yyvsp[-2].sym).typ))
																				{
																					std::string *name = newtemp(); /* Crear nueva variable temporal para resultados */
																					symrec *s;
																					s = putsym(name, gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & ~CONST_SPEC | VAR_SPEC);
																					gencode(OR_IR, (yyvsp[-2].sym).var, (yyvsp[0].sym).var, s);
																					gencode(STORE_IR, s, nullptr, (yyvsp[-2].sym).var);
																				}
																				else
																				{
																					std::string *name = newtemp();
																					std::string *name1 = newtemp(); /* Crear nueva variable temporal para resultado*/
																					symrec *s , *result;
																					s = putsym(name, (yyvsp[-2].sym).typ & ~ARRAY_SPEC | VAR_SPEC);
																					result = putsym(name1, gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & ~ARRAY_SPEC | VAR_SPEC);
																					gencode(LOADA_IR, (yyvsp[-2].sym).var, (yyvsp[-2].sym).var2, s);
																					gencode(OR_IR, s, (yyvsp[0].sym).var, result);
																					gencode(STORE_IR, result, (yyvsp[-2].sym).var2, (yyvsp[-2].sym).var);
																				}
																				break;
																		}	
																	}
#line 3017 "ansic.tab.c"
    break;

  case 64: /* assignment_operator: '='  */
#line 1055 "ansic.y"
                                                {
								printf("assignment_operator: '='\n");
								(yyval.asop) = EQ_ASSIGN_OP;
							}
#line 3026 "ansic.tab.c"
    break;

  case 65: /* assignment_operator: MUL_ASSIGN  */
#line 1059 "ansic.y"
                                        {
								printf("assignment_operator: MUL_ASSIGN\n");
								(yyval.asop) = MUL_ASSIGN_OP;
							}
#line 3035 "ansic.tab.c"
    break;

  case 66: /* assignment_operator: DIV_ASSIGN  */
#line 1063 "ansic.y"
                                        {	
								printf("assignment_operator: DIV_ASSIGN\n");
								(yyval.asop) = DIV_ASSIGN_OP;
							}
#line 3044 "ansic.tab.c"
    break;

  case 67: /* assignment_operator: MOD_ASSIGN  */
#line 1067 "ansic.y"
                                        {
								printf("assignment_operator: MOD_ASSIGN\n");
								(yyval.asop) = MOD_ASSIGN_OP;
							}
#line 3053 "ansic.tab.c"
    break;

  case 68: /* assignment_operator: ADD_ASSIGN  */
#line 1071 "ansic.y"
                                        {
								printf("assignment_operator: ADD_ASSIGN\n");
								(yyval.asop) = ADD_ASSIGN_OP;
							}
#line 3062 "ansic.tab.c"
    break;

  case 69: /* assignment_operator: SUB_ASSIGN  */
#line 1075 "ansic.y"
                                        {
								printf("assignment_operator: SUB_ASSIGN\n");
								(yyval.asop) = SUB_ASSIGN_OP;
							}
#line 3071 "ansic.tab.c"
    break;

  case 70: /* assignment_operator: LEFT_ASSIGN  */
#line 1079 "ansic.y"
                                        {
								printf("assignment_operator: LEFT_ASSIGN\n");
								(yyval.asop) = LEFT_ASSIGN_OP;
							}
#line 3080 "ansic.tab.c"
    break;

  case 71: /* assignment_operator: RIGHT_ASSIGN  */
#line 1083 "ansic.y"
                                        {
								printf("assignment_operator: RIGHT_ASSIGN\n");
								(yyval.asop) = RIGHT_ASSIGN_OP;
							}
#line 3089 "ansic.tab.c"
    break;

  case 72: /* assignment_operator: AND_ASSIGN  */
#line 1087 "ansic.y"
                                        {
								printf("assignment_operator: AND_ASSIGN\n");
								(yyval.asop) = AND_ASSIGN_OP;
							}
#line 3098 "ansic.tab.c"
    break;

  case 73: /* assignment_operator: XOR_ASSIGN  */
#line 1091 "ansic.y"
                                        {
								printf("assignment_operator: XOR_ASSIGN\n");
								(yyval.asop) = XOR_ASSIGN_OP;
							}
#line 3107 "ansic.tab.c"
    break;

  case 74: /* assignment_operator: OR_ASSIGN  */
#line 1095 "ansic.y"
                                                {
								printf("assignment_operator: OR_ASSIGN	\n");
								(yyval.asop) = OR_ASSIGN_OP;
							}
#line 3116 "ansic.tab.c"
    break;

  case 75: /* expression: assignment_expression  */
#line 1102 "ansic.y"
                                                                        {
													printf("expression: assignment_expression\n");
													(yyval.sym) = (yyvsp[0].sym);
												}
#line 3125 "ansic.tab.c"
    break;

  case 76: /* expression: expression ',' assignment_expression  */
#line 1106 "ansic.y"
                                                        {
													printf("expression: expression ',' assignment_expression\n");
													(yyval.sym) = (yyvsp[-2].sym);
												}
#line 3134 "ansic.tab.c"
    break;

  case 77: /* constant_expression: conditional_expression  */
#line 1113 "ansic.y"
                                                                        {
													printf("assignment_operator: conditional_expression\n");
													(yyval.sym) = (yyvsp[0].sym);	
												}
#line 3143 "ansic.tab.c"
    break;

  case 78: /* declaration: declaration_specifiers ';'  */
#line 1120 "ansic.y"
                                                                                        {printf("declaration: declaration_specifiers ';'\n");}
#line 3149 "ansic.tab.c"
    break;

  case 79: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 1121 "ansic.y"
                                                                        {
																int typ;
																printf("declaration: declaration_specifiers init_declarator_list ';'\n");
																std::list<VAR_DATA *>::iterator it;
																typ = get_type((yyvsp[-2].sqlist));
																//cout << "Declaring variables: "<<endl;
																for(it = (yyvsp[-1].idlist)->begin(); it != (yyvsp[-1].idlist) -> end(); it++)
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
#line 3184 "ansic.tab.c"
    break;

  case 80: /* declaration_specifiers: storage_class_specifier  */
#line 1154 "ansic.y"
                                                                                                {
																list<int> *newlist = new list<int>; 
																printf("declaration_specifiers: storage_class_specifier\n");
																newlist->push_back((yyvsp[0].scsp));
																(yyval.sqlist)=newlist;
															}
#line 3195 "ansic.tab.c"
    break;

  case 81: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 1160 "ansic.y"
                                                                        {	
																printf("declaration_specifiers: storage_class_specifier declaration_specifiers\n");
																(yyval.sqlist) = (yyvsp[0].sqlist);
																(yyval.sqlist)->push_back((yyvsp[-1].scsp));
															}
#line 3205 "ansic.tab.c"
    break;

  case 82: /* declaration_specifiers: type_specifier  */
#line 1165 "ansic.y"
                                                                                                        {
																list<int> *newlist = new list<int>;
																printf("declaration_specifiers: type_specifier\n");
																newlist->push_back((yyvsp[0].typsp));
																(yyval.sqlist)=newlist;
															}
#line 3216 "ansic.tab.c"
    break;

  case 83: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 1171 "ansic.y"
                                                                                {
																printf("declaration_specifiers: type_specifier declaration_specifiers\n");
																(yyval.sqlist) = (yyvsp[0].sqlist);
																(yyval.sqlist)->push_back((yyvsp[-1].typsp));
															}
#line 3226 "ansic.tab.c"
    break;

  case 84: /* declaration_specifiers: type_qualifier  */
#line 1176 "ansic.y"
                                                                                                        {
																list<int> *newlist = new list<int>;
																printf("declaration_specifiers: type_qualifier\n");
																newlist->push_back((yyvsp[0].qual));
																(yyval.sqlist)=newlist;
															}
#line 3237 "ansic.tab.c"
    break;

  case 85: /* declaration_specifiers: type_qualifier declaration_specifiers  */
#line 1182 "ansic.y"
                                                                                {
																printf("declaration_specifiers: type_qualifier declaration_specifiers\n");
																(yyval.sqlist) = (yyvsp[0].sqlist);
																(yyval.sqlist)->push_back((yyvsp[-1].qual));
															}
#line 3247 "ansic.tab.c"
    break;

  case 86: /* init_declarator_list: init_declarator  */
#line 1190 "ansic.y"
                                                                                        {
														std::list<VAR_DATA *> *newlist = new std::list<VAR_DATA *>;
														VAR_DATA *newstruc = (yyvsp[0].id_data);
														printf("init_declarator_list: init_declarator	\n");
														newlist->push_back(newstruc);
														(yyval.idlist) = newlist;
													}
#line 3259 "ansic.tab.c"
    break;

  case 87: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 1197 "ansic.y"
                                                                {
														printf("init_declarator_list: init_declarator_list ',' init_declarator\n");
														(yyval.idlist)=(yyvsp[-2].idlist);
														(yyval.idlist)->push_back((yyvsp[0].id_data));
													}
#line 3269 "ansic.tab.c"
    break;

  case 88: /* init_declarator: declarator  */
#line 1205 "ansic.y"
                                                                {
											printf("init_declarator: declarator\n");
											(yyval.id_data) = (yyvsp[0].id_data);
										}
#line 3278 "ansic.tab.c"
    break;

  case 89: /* init_declarator: declarator '=' initializer  */
#line 1209 "ansic.y"
                                                {
											printf("init_declarator: declarator '=' initializer\n");
											(yyval.id_data) = (yyvsp[-2].id_data);
											(yyval.id_data)->init = 1;
											(yyval.id_data)->var = (yyvsp[0].sym).var;
										}
#line 3289 "ansic.tab.c"
    break;

  case 90: /* storage_class_specifier: TYPEDEF  */
#line 1218 "ansic.y"
                                                        {
									printf("storage_class_specifier: TYPEDEF\n");
									(yyval.scsp)=TYPEDEF_SPEC;
								}
#line 3298 "ansic.tab.c"
    break;

  case 91: /* storage_class_specifier: EXTERN  */
#line 1222 "ansic.y"
                                                        {
									printf("storage_class_specifier: EXTERN\n");
									(yyval.scsp)= EXTERN_SPEC;
								}
#line 3307 "ansic.tab.c"
    break;

  case 92: /* storage_class_specifier: STATIC  */
#line 1226 "ansic.y"
                                                        {
									printf("storage_class_specifier: STATIC\n");
									(yyval.scsp) = STATIC_SPEC;
								}
#line 3316 "ansic.tab.c"
    break;

  case 93: /* storage_class_specifier: AUTO  */
#line 1230 "ansic.y"
                                                        {	
									printf("storage_class_specifier: AUTO\n");
									(yyval.scsp) = AUTO_SPEC;
								}
#line 3325 "ansic.tab.c"
    break;

  case 94: /* storage_class_specifier: REGISTER  */
#line 1234 "ansic.y"
                                                        {
									printf("storage_class_specifier: REGISTER\n");
									(yyval.scsp) = REGISTER_SPEC;
								}
#line 3334 "ansic.tab.c"
    break;

  case 95: /* type_specifier: VOID  */
#line 1241 "ansic.y"
                                                                {
										printf("type_specifier: VOID\n");
										(yyval.typsp) = VOID_SPEC;
									}
#line 3343 "ansic.tab.c"
    break;

  case 96: /* type_specifier: CHAR  */
#line 1245 "ansic.y"
                                                                {
										printf("type_specifier: CHAR\n");
										(yyval.typsp) = CHAR_SPEC;
									}
#line 3352 "ansic.tab.c"
    break;

  case 97: /* type_specifier: SHORT  */
#line 1249 "ansic.y"
                                                                {
										printf("type_specifier: SHORT\n");
										(yyval.typsp) = SHORT_SPEC;
									}
#line 3361 "ansic.tab.c"
    break;

  case 98: /* type_specifier: INT  */
#line 1253 "ansic.y"
                                                                {
										printf("type_specifier: INT\n");
										(yyval.typsp) = INT_SPEC;
									}
#line 3370 "ansic.tab.c"
    break;

  case 99: /* type_specifier: LONG  */
#line 1257 "ansic.y"
                                                                {
										printf("type_specifier: LONG\n");
										(yyval.typsp) = LONG_SPEC;
									}
#line 3379 "ansic.tab.c"
    break;

  case 100: /* type_specifier: FLOAT  */
#line 1261 "ansic.y"
                                                                {
										printf("type_specifier: FLOAT\n");
										(yyval.typsp) = FLOAT_SPEC;
									}
#line 3388 "ansic.tab.c"
    break;

  case 101: /* type_specifier: DOUBLE  */
#line 1265 "ansic.y"
                                                                {
										printf("type_specifier: DOUBLE\n");
										(yyval.typsp) = DOUBLE_SPEC;
									}
#line 3397 "ansic.tab.c"
    break;

  case 102: /* type_specifier: SIGNED  */
#line 1269 "ansic.y"
                                                                {
										printf("type_specifier: SIGNED\n");
										(yyval.typsp) = SIGNED_SPEC;
									}
#line 3406 "ansic.tab.c"
    break;

  case 103: /* type_specifier: UNSIGNED  */
#line 1273 "ansic.y"
                                                                {
										printf("type_specifier: UNSIGNED\n");
										(yyval.typsp) = UNSIGNED_SPEC;
									}
#line 3415 "ansic.tab.c"
    break;

  case 104: /* type_specifier: struct_or_union_specifier  */
#line 1277 "ansic.y"
                                                {
										printf("type_specifier: struct_or_union_specifier\n");
										
									}
#line 3424 "ansic.tab.c"
    break;

  case 105: /* type_specifier: enum_specifier  */
#line 1281 "ansic.y"
                                                        {
										printf("type_specifier: enum_specifier\n");
										(yyval.typsp) = ENUM_SPEC;
									}
#line 3433 "ansic.tab.c"
    break;

  case 106: /* type_specifier: TYPE_NAME  */
#line 1285 "ansic.y"
                                                                {
										printf("type_specifier: TYPE_NAME\n");
										(yyval.typsp) = TYPENAME_SPEC;
									}
#line 3442 "ansic.tab.c"
    break;

  case 107: /* struct_or_union_specifier: struct_or_union IDENTIFIER '{' struct_declaration_list '}'  */
#line 1292 "ansic.y"
                                                                        {printf("struct_or_union_specifier: struct_or_union IDENTIFIER '{' struct_declaration_list '}'\n");}
#line 3448 "ansic.tab.c"
    break;

  case 108: /* struct_or_union_specifier: struct_or_union '{' struct_declaration_list '}'  */
#line 1293 "ansic.y"
                                                                                        {printf("struct_or_union_specifier: struct_or_union '{' struct_declaration_list '}'	\n");}
#line 3454 "ansic.tab.c"
    break;

  case 109: /* struct_or_union_specifier: struct_or_union IDENTIFIER  */
#line 1294 "ansic.y"
                                                                                                        {printf("struct_or_union_specifier: struct_or_union IDENTIFIER\n");}
#line 3460 "ansic.tab.c"
    break;

  case 110: /* struct_or_union: STRUCT  */
#line 1298 "ansic.y"
                                                                                                                                {printf("struct_or_union_specifier: STRUCT\n");}
#line 3466 "ansic.tab.c"
    break;

  case 111: /* struct_or_union: UNION  */
#line 1299 "ansic.y"
                                                                                                                                {printf("struct_or_union_specifier: UNION\n");}
#line 3472 "ansic.tab.c"
    break;

  case 112: /* struct_declaration_list: struct_declaration  */
#line 1303 "ansic.y"
                                                                                                                {printf("struct_declaration_list: struct_declaration\n");}
#line 3478 "ansic.tab.c"
    break;

  case 113: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 1304 "ansic.y"
                                                                                        {printf("struct_declaration_list: struct_declaration_list struct_declaration\n");}
#line 3484 "ansic.tab.c"
    break;

  case 114: /* struct_declaration: specifier_qualifier_list struct_declarator_list ';'  */
#line 1308 "ansic.y"
                                                                                {printf("struct_declaration: specifier_qualifier_list struct_declarator_list ';'\n");}
#line 3490 "ansic.tab.c"
    break;

  case 115: /* specifier_qualifier_list: type_specifier specifier_qualifier_list  */
#line 1312 "ansic.y"
                                                                                                {
																		printf("specifier_qualifier_list: type_specifier specifier_qualifier_list\n");
																		(yyval.sqlist)=(yyvsp[0].sqlist);
																		(yyval.sqlist)->push_back((yyvsp[-1].typsp));
																	}
#line 3500 "ansic.tab.c"
    break;

  case 116: /* specifier_qualifier_list: type_specifier  */
#line 1317 "ansic.y"
                                                                                                                        {
																		printf("specifier_qualifier_list: type_specifier\n");
																		std::list<int> *newlist = new std::list<int>;
																		newlist->push_back((yyvsp[0].typsp));
																		(yyval.sqlist) = newlist;
																	}
#line 3511 "ansic.tab.c"
    break;

  case 117: /* specifier_qualifier_list: type_qualifier specifier_qualifier_list  */
#line 1323 "ansic.y"
                                                                                                {
																		printf("specifier_qualifier_list: type_qualifier specifier_qualifier_list\n");
																		(yyval.sqlist) = (yyvsp[0].sqlist);
																		(yyval.sqlist)->push_back((yyvsp[-1].qual));
																	}
#line 3521 "ansic.tab.c"
    break;

  case 118: /* specifier_qualifier_list: type_qualifier  */
#line 1328 "ansic.y"
                                                                                                                        {
																		printf("specifier_qualifier_list: type_qualifier\n");
																		std::list<int> *newlist = new std::list<int>;
																		newlist->push_back((yyvsp[0].qual));
																		(yyval.sqlist) = newlist;
																	}
#line 3532 "ansic.tab.c"
    break;

  case 119: /* struct_declarator_list: struct_declarator  */
#line 1337 "ansic.y"
                                                                                                                        {printf("struct_declarator_list: struct_declarator\n");}
#line 3538 "ansic.tab.c"
    break;

  case 120: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 1338 "ansic.y"
                                                                                        {printf("struct_declarator_list: struct_declarator_list ',' struct_declarator\n");}
#line 3544 "ansic.tab.c"
    break;

  case 121: /* struct_declarator: declarator  */
#line 1342 "ansic.y"
                                                                                {printf("struct_declarator: declarator\n");}
#line 3550 "ansic.tab.c"
    break;

  case 122: /* struct_declarator: ':' constant_expression  */
#line 1343 "ansic.y"
                                                                        {printf("struct_declarator: ':' constant_expression\n");}
#line 3556 "ansic.tab.c"
    break;

  case 123: /* struct_declarator: declarator ':' constant_expression  */
#line 1344 "ansic.y"
                                                        {printf("struct_declarator: declarator ':' constant_expression\n");}
#line 3562 "ansic.tab.c"
    break;

  case 124: /* enum_specifier: ENUM '{' enumerator_list '}'  */
#line 1348 "ansic.y"
                                                                {printf("enum_specifier: ENUM '{' enumerator_list '}'	\n");}
#line 3568 "ansic.tab.c"
    break;

  case 125: /* enum_specifier: ENUM IDENTIFIER '{' enumerator_list '}'  */
#line 1349 "ansic.y"
                                                        {printf("enum_specifier: ENUM IDENTIFIER '{' enumerator_list '}'\n");}
#line 3574 "ansic.tab.c"
    break;

  case 126: /* enum_specifier: ENUM IDENTIFIER  */
#line 1350 "ansic.y"
                                                                                {printf("enum_specifier: ENUM IDENTIFIER\n");}
#line 3580 "ansic.tab.c"
    break;

  case 127: /* enumerator_list: enumerator  */
#line 1354 "ansic.y"
                                                                                {printf("enumerator_list: enumerator\n");}
#line 3586 "ansic.tab.c"
    break;

  case 128: /* enumerator_list: enumerator_list ',' enumerator  */
#line 1355 "ansic.y"
                                                                {printf("enumerator_list: enumerator_list ',' enumerator\n");}
#line 3592 "ansic.tab.c"
    break;

  case 129: /* enumerator: IDENTIFIER  */
#line 1359 "ansic.y"
                                                                                {printf("enumerator: IDENTIFIER\n");}
#line 3598 "ansic.tab.c"
    break;

  case 130: /* enumerator: IDENTIFIER '=' constant_expression  */
#line 1360 "ansic.y"
                                                        {printf("enumerator: IDENTIFIER '=' constant_expression\n");}
#line 3604 "ansic.tab.c"
    break;

  case 131: /* type_qualifier: CONST  */
#line 1364 "ansic.y"
                                {
						printf("type_qualifier: CONST\n");
						(yyval.qual) = CONST_SPEC; 
					}
#line 3613 "ansic.tab.c"
    break;

  case 132: /* type_qualifier: VOLATILE  */
#line 1368 "ansic.y"
                                {
						printf("type_qualifier: VOLATILE\n");
						(yyval.qual) = VOLATILE_SPEC;
					}
#line 3622 "ansic.tab.c"
    break;

  case 133: /* declarator: pointer direct_declarator  */
#line 1375 "ansic.y"
                                                        {
											printf("declarator: pointer direct_declarator\n");
											(yyval.id_data) = (yyvsp[0].id_data);
											(yyval.id_data)->plevel = (yyvsp[-1].pstruc).level;
											(yyval.id_data)->typ |= POINTER_SPEC | (yyvsp[-1].pstruc).typq;	
										}
#line 3633 "ansic.tab.c"
    break;

  case 134: /* declarator: direct_declarator  */
#line 1381 "ansic.y"
                                                                {
											printf("declarator: direct_declarator\n");
											(yyval.id_data) = (yyvsp[0].id_data);
											if(isarray((yyval.id_data)->typ))
											{
												/* Arreglos sin dimensiones son punteros */
												if(allzero((yyval.id_data)->dimlist))
												{
													(yyval.id_data)->typ &= ~ARRAY_SPEC;
													(yyval.id_data)->typ |= POINTER_SPEC;
												}
												else
												{
													if(product((yyval.id_data)->dimlist)==0)
														yyerror("Array dimensions must be specified!");
												}
											}
										}
#line 3656 "ansic.tab.c"
    break;

  case 135: /* direct_declarator: IDENTIFIER  */
#line 1402 "ansic.y"
                                                                                                {
															string *name = new string((yyvsp[0].token.name)); /* El nombre es el atributo id del token IDENTIFIER */
															printf("direct_declarator: IDENTIFIER");
															cout << "<" << *name << ">" << "\n";
															VAR_DATA *newsym = new VAR_DATA();
															newsym->name = new string((yyvsp[0].token.name));
															newsym->dimlist = nullptr;
															(yyval.id_data) = newsym;
														}
#line 3670 "ansic.tab.c"
    break;

  case 136: /* direct_declarator: '(' declarator ')'  */
#line 1411 "ansic.y"
                                                                                        {
															printf("direct_declarator: '(' declarator ')'\n");

														}
#line 3679 "ansic.tab.c"
    break;

  case 137: /* direct_declarator: direct_declarator '[' constant_expression ']'  */
#line 1415 "ansic.y"
                                                                {
															printf("direct_declarator: direct_declarator '[' constant_expression ']'\n");
															if(!isintegral((yyvsp[-1].sym).typ))
																yyerror("Array dimension must be integral!");
															if(!isconstant((yyvsp[-1].sym).typ))
																yyerror("Array dimension must be constant!");
															(yyval.id_data) = (yyvsp[-3].id_data);
															if((yyval.id_data)->dimlist == nullptr)
																(yyval.id_data)->dimlist = new list<int >;
															(yyval.id_data)->dimlist->push_back((yyvsp[-1].sym).val.intval);
															(yyval.id_data)->typ |= ARRAY_SPEC;	
														}
#line 3696 "ansic.tab.c"
    break;

  case 138: /* direct_declarator: direct_declarator '[' ']'  */
#line 1427 "ansic.y"
                                                                                        {
															printf("direct_declarator: direct_declarator '[' ']'\n");
															(yyval.id_data) = (yyvsp[-2].id_data);
															if((yyval.id_data)->dimlist == nullptr)
																(yyval.id_data)->dimlist = new list<int >;
															(yyval.id_data)->dimlist->push_back(0);
															(yyval.id_data)->typ |= ARRAY_SPEC;	
														}
#line 3709 "ansic.tab.c"
    break;

  case 139: /* direct_declarator: direct_declarator '(' parameter_type_list ')'  */
#line 1435 "ansic.y"
                                                                {
															printf("direct_declarator: direct_declarator '(' parameter_type_list ')'\n");
															(yyval.id_data) = (yyvsp[-3].id_data);
															(yyval.id_data)->typ |= FUNC_SPEC;
															(yyval.id_data)->arglist = (yyvsp[-1].idlist);
															(yyval.id_data)->init = 0;
														}
#line 3721 "ansic.tab.c"
    break;

  case 140: /* direct_declarator: direct_declarator '(' identifier_list ')'  */
#line 1442 "ansic.y"
                                                                        {printf("direct_declarator: direct_declarator '(' identifier_list ')'	\n");}
#line 3727 "ansic.tab.c"
    break;

  case 141: /* direct_declarator: direct_declarator '(' ')'  */
#line 1443 "ansic.y"
                                                                                        {
															printf("direct_declarator: direct_declarator '(' ')'	\n");
															(yyval.id_data) = (yyvsp[-2].id_data);
															(yyval.id_data)->typ |= FUNC_SPEC;
															(yyval.id_data)->init = 0;
														}
#line 3738 "ansic.tab.c"
    break;

  case 142: /* pointer: '*'  */
#line 1452 "ansic.y"
                                                                                {
												printf("pointer: '*'\n");
												(yyval.pstruc).typq = 0;
												(yyval.pstruc).level = 1;
											}
#line 3748 "ansic.tab.c"
    break;

  case 143: /* pointer: '*' type_qualifier_list  */
#line 1457 "ansic.y"
                                                                {
												printf("pointer: '*' type_qualifier_list\n");
												(yyval.pstruc).typq = (yyvsp[0].qual);
												(yyval.pstruc).level = 1;	
											}
#line 3758 "ansic.tab.c"
    break;

  case 144: /* pointer: '*' pointer  */
#line 1462 "ansic.y"
                                                                        {
												printf("pointer: '*' pointer\n");
												(yyval.pstruc) = (yyvsp[0].pstruc);
												(yyval.pstruc).level++;	
											}
#line 3768 "ansic.tab.c"
    break;

  case 145: /* pointer: '*' type_qualifier_list pointer  */
#line 1467 "ansic.y"
                                                        {
												printf("pointer: '*' type_qualifier_list pointer\n");
												(yyval.pstruc) = (yyvsp[0].pstruc);
												(yyval.pstruc).typq = (yyvsp[-1].qual);
												(yyval.pstruc).level++;
											}
#line 3779 "ansic.tab.c"
    break;

  case 146: /* type_qualifier_list: type_qualifier  */
#line 1476 "ansic.y"
                                                                        {
												printf("type_qualifier_list: type_qualifier\n");
												(yyval.qual) = (yyvsp[0].qual);
											}
#line 3788 "ansic.tab.c"
    break;

  case 147: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 1480 "ansic.y"
                                                {printf("type_qualifier_list: type_qualifier_list type_qualifier\n");
												(yyval.qual) = (yyvsp[-1].qual);
												(yyval.qual) |= (yyvsp[0].qual);
											}
#line 3797 "ansic.tab.c"
    break;

  case 148: /* parameter_type_list: parameter_list  */
#line 1487 "ansic.y"
                                                                                {
													printf("parameter_type_list: parameter_list\n");
													(yyval.idlist) = (yyvsp[0].idlist);	
												}
#line 3806 "ansic.tab.c"
    break;

  case 149: /* parameter_type_list: parameter_list ',' ELLIPSIS  */
#line 1491 "ansic.y"
                                                                {printf("parameter_type_list: parameter_list ',' ELLIPSIS\n");}
#line 3812 "ansic.tab.c"
    break;

  case 150: /* parameter_list: parameter_declaration  */
#line 1495 "ansic.y"
                                                                                {
														printf("parameter_list: parameter_declaration\n");
														std::list<VAR_DATA *> *newlist = new std::list<VAR_DATA *>;
														VAR_DATA *newstruc = new VAR_DATA();
														*newstruc = (yyvsp[0].sym);
														newlist->push_back(newstruc);
														(yyval.idlist) = newlist;
													}
#line 3825 "ansic.tab.c"
    break;

  case 151: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 1503 "ansic.y"
                                                                {	
														printf("parameter_list: parameter_list ',' parameter_declaration\n");
														(yyval.idlist) = (yyvsp[-2].idlist);
														VAR_DATA *newstruc = new VAR_DATA();
														*newstruc = (yyvsp[0].sym);
														(yyval.idlist)->push_back(newstruc);
													}
#line 3837 "ansic.tab.c"
    break;

  case 152: /* parameter_declaration: declaration_specifiers declarator  */
#line 1513 "ansic.y"
                                                                                {
															printf("parameter_declaration: declaration_specifiers declarator\n");
															(yyval.sym).name = (yyvsp[0].id_data)->name;
															if(!isarray((yyvsp[0].id_data)->typ))
																(yyval.sym).typ = get_type((yyvsp[-1].sqlist));
															else
																(yyval.sym).typ = get_type((yyvsp[-1].sqlist)) | ARRAY_SPEC;
														}
#line 3850 "ansic.tab.c"
    break;

  case 153: /* parameter_declaration: declaration_specifiers abstract_declarator  */
#line 1521 "ansic.y"
                                                                {printf("parameter_declaration: declaration_specifiers abstract_declarator\n");}
#line 3856 "ansic.tab.c"
    break;

  case 154: /* parameter_declaration: declaration_specifiers  */
#line 1522 "ansic.y"
                                                                                        {printf("parameter_declaration: declaration_specifiers\n");}
#line 3862 "ansic.tab.c"
    break;

  case 155: /* identifier_list: IDENTIFIER  */
#line 1526 "ansic.y"
                                                                                {
													string *name = new string((yyvsp[0].token.name)); /* El nombre es el atributo id del token IDENTIFIER */
													printf("identifier_list: IDENTIFIER");
													cout << "<" << *name << ">" << "\n";	
												}
#line 3872 "ansic.tab.c"
    break;

  case 156: /* identifier_list: identifier_list ',' IDENTIFIER  */
#line 1531 "ansic.y"
                                                                {
													string *name = new string((yyvsp[0].token.name)); /* El nombre es el atributo id del token IDENTIFIER */
													printf("identifier_list: identifier_list ',' IDENTIFIER");
													cout << "<" << *name << ">" << "\n";
												}
#line 3882 "ansic.tab.c"
    break;

  case 157: /* type_name: specifier_qualifier_list  */
#line 1539 "ansic.y"
                                                                                        {
															printf("type_name: specifier_qualifier_list\n");
															(yyval.typ) = get_type((yyvsp[0].sqlist));	
														}
#line 3891 "ansic.tab.c"
    break;

  case 158: /* type_name: specifier_qualifier_list abstract_declarator  */
#line 1543 "ansic.y"
                                                                {printf("type_name: specifier_qualifier_list abstract_declarator\n");}
#line 3897 "ansic.tab.c"
    break;

  case 159: /* abstract_declarator: pointer  */
#line 1547 "ansic.y"
                                                                                        {printf("abstract_declarator: pointer\n");}
#line 3903 "ansic.tab.c"
    break;

  case 160: /* abstract_declarator: direct_abstract_declarator  */
#line 1548 "ansic.y"
                                                                {printf("abstract_declarator: direct_abstract_declarator\n");}
#line 3909 "ansic.tab.c"
    break;

  case 161: /* abstract_declarator: pointer direct_abstract_declarator  */
#line 1549 "ansic.y"
                                                        {printf("abstract_declarator: pointer direct_abstract_declarator\n");}
#line 3915 "ansic.tab.c"
    break;

  case 162: /* direct_abstract_declarator: '(' abstract_declarator ')'  */
#line 1553 "ansic.y"
                                                                                                        {printf("direct_abstract_declarator: '(' abstract_declarator ')'\n");}
#line 3921 "ansic.tab.c"
    break;

  case 163: /* direct_abstract_declarator: '[' ']'  */
#line 1554 "ansic.y"
                                                                                                                                {printf("direct_abstract_declarator: '[' ']'\n");}
#line 3927 "ansic.tab.c"
    break;

  case 164: /* direct_abstract_declarator: '[' constant_expression ']'  */
#line 1555 "ansic.y"
                                                                                                        {printf("direct_abstract_declarator: '[' constant_expression ']'\n");}
#line 3933 "ansic.tab.c"
    break;

  case 165: /* direct_abstract_declarator: direct_abstract_declarator '[' ']'  */
#line 1556 "ansic.y"
                                                                                                {printf("direct_abstract_declarator: direct_abstract_declarator '[' ']' \n");}
#line 3939 "ansic.tab.c"
    break;

  case 166: /* direct_abstract_declarator: direct_abstract_declarator '[' constant_expression ']'  */
#line 1557 "ansic.y"
                                                                                {printf("direct_abstract_declarator: direct_abstract_declarator '[' constant_expression ']'\n");}
#line 3945 "ansic.tab.c"
    break;

  case 167: /* direct_abstract_declarator: '(' ')'  */
#line 1558 "ansic.y"
                                                                                                                                {printf("direct_abstract_declarator: '(' ')'\n");}
#line 3951 "ansic.tab.c"
    break;

  case 168: /* direct_abstract_declarator: '(' parameter_type_list ')'  */
#line 1559 "ansic.y"
                                                                                                        {printf("direct_abstract_declarator: '(' parameter_type_list ')'\n");}
#line 3957 "ansic.tab.c"
    break;

  case 169: /* direct_abstract_declarator: direct_abstract_declarator '(' ')'  */
#line 1560 "ansic.y"
                                                                                                {printf("direct_abstract_declarator: direct_abstract_declarator '(' ')'\n");}
#line 3963 "ansic.tab.c"
    break;

  case 170: /* direct_abstract_declarator: direct_abstract_declarator '(' parameter_type_list ')'  */
#line 1561 "ansic.y"
                                                                                {printf("direct_abstract_declarator: direct_abstract_declarator '(' parameter_type_list ')'\n");}
#line 3969 "ansic.tab.c"
    break;

  case 171: /* initializer: assignment_expression  */
#line 1565 "ansic.y"
                                                                {
												printf("initializer: assignment_expression\n");
												(yyval.sym) = (yyvsp[0].sym);	
											}
#line 3978 "ansic.tab.c"
    break;

  case 172: /* initializer: '{' initializer_list '}'  */
#line 1569 "ansic.y"
                                                                {printf("initializer: '{' initializer_list '}'\n");}
#line 3984 "ansic.tab.c"
    break;

  case 173: /* initializer: '{' initializer_list ',' '}'  */
#line 1570 "ansic.y"
                                                        {printf("initializer: '{' initializer_list ',' '}'\n");}
#line 3990 "ansic.tab.c"
    break;

  case 174: /* initializer_list: initializer  */
#line 1574 "ansic.y"
                                                                        {printf("initializer_list: initializer\n");}
#line 3996 "ansic.tab.c"
    break;

  case 175: /* initializer_list: initializer_list ',' initializer  */
#line 1575 "ansic.y"
                                                        {printf("initializer_list: initializer_list ',' initializer\n");}
#line 4002 "ansic.tab.c"
    break;

  case 177: /* statement: labeled_statement  */
#line 1582 "ansic.y"
                                                {
									printf("statement: labeled_statement\n");
									(yyval.lists) = (yyvsp[0].lists);
									(yyval.lists).nextlist = NULL;
								}
#line 4012 "ansic.tab.c"
    break;

  case 178: /* $@2: %empty  */
#line 1587 "ansic.y"
                                                        {
									enter_scope();
								}
#line 4020 "ansic.tab.c"
    break;

  case 179: /* statement: P $@2 compound_statement  */
#line 1590 "ansic.y"
                                        {
		  							printf("statement: compound_statement\n");
									//printlocalvars();
									exit_scope();
									(yyval.lists) = (yyvsp[0].lists);
								}
#line 4031 "ansic.tab.c"
    break;

  case 180: /* statement: expression_statement  */
#line 1596 "ansic.y"
                                        {
									printf("statement: expression_statement\n");
									(yyval.lists).nextlist = NULL;
									(yyval.lists).breaklist = NULL;
									(yyval.lists).continuelist = NULL;
									(yyval.lists).gotolist = NULL;
									(yyval.lists).caselist = NULL;	
								}
#line 4044 "ansic.tab.c"
    break;

  case 181: /* statement: selection_statement  */
#line 1604 "ansic.y"
                                        {
									printf("statement: selection_statement\n");
									(yyval.lists) = (yyvsp[0].lists);
									(yyval.lists).caselist = NULL;
								}
#line 4054 "ansic.tab.c"
    break;

  case 182: /* statement: iteration_statement  */
#line 1609 "ansic.y"
                                        {
									printf("statement: iteration_statement\n");
									(yyval.lists) = (yyvsp[0].lists);
									(yyval.lists).caselist = NULL;
								}
#line 4064 "ansic.tab.c"
    break;

  case 183: /* statement: jump_statement  */
#line 1614 "ansic.y"
                                                {
									printf("statement: jump_statement\n");
									(yyval.lists) = (yyvsp[0].lists);
									(yyval.lists).caselist = NULL;
								}
#line 4074 "ansic.tab.c"
    break;

  case 184: /* N: %empty  */
#line 1621 "ansic.y"
                                                {	
									/* Retornar direccion de siguiente instruccion de IR */
									(yyval.instr) = nextinstr;
								}
#line 4083 "ansic.tab.c"
    break;

  case 185: /* labeled_statement: IDENTIFIER ':' N statement  */
#line 1628 "ansic.y"
                                                                        {
														printf("labeled_statement: IDENTIFIER ':' statement\n");
														putlab(new string((yyvsp[-3].token.name)), (yyvsp[-1].instr));
														(yyval.lists).nextlist = NULL;
														(yyval.lists).breaklist = NULL;
														(yyval.lists).continuelist = NULL;
														(yyval.lists).gotolist = NULL;
														(yyval.lists).caselist = NULL;
													}
#line 4097 "ansic.tab.c"
    break;

  case 186: /* labeled_statement: CASE constant_expression ':' N statement  */
#line 1637 "ansic.y"
                                                                {
														printf("labeled_statement: CASE constant_expression ':' statement\n");
														(yyval.lists).breaklist = (yyvsp[0].lists).breaklist;
														(yyval.lists).continuelist = (yyvsp[0].lists).continuelist;
														(yyval.lists).gotolist = (yyvsp[0].lists).gotolist;
														if(!isconstant((yyvsp[-3].sym).typ))
															yyerror("Error: CASE espression must be constant\n");
														if(!isintegral((yyvsp[-3].sym).typ))
															yyerror("Error: CASE espression must be integral constant\n");
														(yyval.lists).caselist = makecaselist((yyvsp[-3].sym).val, (yyvsp[-3].sym).typ, (yyvsp[-1].instr));
													}
#line 4113 "ansic.tab.c"
    break;

  case 187: /* labeled_statement: DEFAULT ':' N statement  */
#line 1648 "ansic.y"
                                                                                {
														printf("labeled_statement: DEFAULT ':' statement\n");
														(yyval.lists).breaklist = (yyvsp[0].lists).breaklist;
														(yyval.lists).continuelist = (yyvsp[0].lists).continuelist;
														(yyval.lists).gotolist = (yyvsp[0].lists).gotolist;
														(yyval.lists).caselist = makecaselist((yyvsp[-1].instr));
													}
#line 4125 "ansic.tab.c"
    break;

  case 188: /* compound_statement: '{' '}'  */
#line 1658 "ansic.y"
                                                                                                {
														printf("compound_statement: '{' '}'\n");
														(yyval.lists).breaklist = NULL;
														(yyval.lists).continuelist = NULL;
														(yyval.lists).gotolist = NULL;
														(yyval.lists).nextlist = NULL;
													}
#line 4137 "ansic.tab.c"
    break;

  case 189: /* compound_statement: '{' statement_list '}'  */
#line 1665 "ansic.y"
                                                                                {
														printf("compound_statement: '{' statement_list '}'\n");
														(yyval.lists) = (yyvsp[-1].lists);
													}
#line 4146 "ansic.tab.c"
    break;

  case 190: /* compound_statement: '{' declaration_list '}'  */
#line 1669 "ansic.y"
                                                                                {
														printf("compound_statement: '{' declaration_list '}'\n");
														(yyval.lists).breaklist = NULL;
														(yyval.lists).continuelist = NULL;
														(yyval.lists).gotolist = NULL;
														(yyval.lists).nextlist = NULL;
													}
#line 4158 "ansic.tab.c"
    break;

  case 191: /* compound_statement: '{' declaration_list statement_list '}'  */
#line 1676 "ansic.y"
                                                                {
														printf("compound_statement: '{' declaration_list statement_list '}'\n");
														(yyval.lists) = (yyvsp[-1].lists);
													}
#line 4167 "ansic.tab.c"
    break;

  case 192: /* declaration_list: declaration  */
#line 1683 "ansic.y"
                                                                                        {printf("declaration_list: declaration\n");}
#line 4173 "ansic.tab.c"
    break;

  case 193: /* declaration_list: declaration_list declaration  */
#line 1684 "ansic.y"
                                                                        {printf("declaration_list: declaration_list declaration\n");}
#line 4179 "ansic.tab.c"
    break;

  case 194: /* statement_list: statement  */
#line 1688 "ansic.y"
                                                                                                {
														printf("statement_list: statement\n");
														(yyval.lists) = (yyvsp[0].lists);
													}
#line 4188 "ansic.tab.c"
    break;

  case 195: /* statement_list: statement_list N statement  */
#line 1692 "ansic.y"
                                                                        {
														printf("statement_list: statement_list statement\n");
														backpatch((yyvsp[-2].lists).nextlist, (yyvsp[-1].instr));
														(yyval.lists) = (yyvsp[-2].lists);
														(yyval.lists).nextlist = (yyvsp[0].lists).nextlist;
														(yyval.lists).breaklist = merge((yyvsp[-2].lists).breaklist, (yyvsp[0].lists).breaklist);
														(yyval.lists).continuelist = merge((yyvsp[-2].lists).continuelist, (yyvsp[0].lists).continuelist);
														(yyval.lists).gotolist = merge((yyvsp[-2].lists).gotolist, (yyvsp[0].lists).gotolist);
														(yyval.lists).caselist = merge((yyvsp[-2].lists).caselist, (yyvsp[0].lists).caselist);
													}
#line 4203 "ansic.tab.c"
    break;

  case 196: /* expression_statement: ';'  */
#line 1705 "ansic.y"
                                                                                                {
														printf("expression_statement: ';'\n");
														(yyval.sym).truelist = nullptr;
														(yyval.sym).falselist = nullptr;
													}
#line 4213 "ansic.tab.c"
    break;

  case 197: /* expression_statement: expression ';'  */
#line 1710 "ansic.y"
                                                                                        {
														printf("expression_statement: expression ';'\n");
														(yyval.sym) = (yyvsp[-1].sym);
													}
#line 4222 "ansic.tab.c"
    break;

  case 198: /* logic_expression: expression  */
#line 1716 "ansic.y"
                                                                        {
														(yyval.sym) = (yyvsp[0].sym);
														/* Verificar si expression es compracion u operacion logica*/
														if((yyvsp[0].sym).truelist == nullptr || (yyvsp[0].sym).falselist == nullptr)
														{
															std::string *name = newtemp(); /* Nueva variable temporal */
															symrec *s0;
															s0 = putsym(name, INTVAL | CONST_SPEC);
															* (int *)(datablock+s0->offset) = 0;
															(yyval.sym).truelist = makelist(nextinstr);
															gencode(IF_NE_IR, (yyvsp[0].sym).var, s0, nullptr);
															(yyval.sym).falselist = makelist(nextinstr);
															gencode(GOTO_IR);
														}
													}
#line 4242 "ansic.tab.c"
    break;

  case 199: /* selection_statement: IF '(' logic_expression ')' N statement  */
#line 1733 "ansic.y"
                                                                                {
																		printf("selection_statement: IF '(' expression ')' statement\n");
																		backpatch((yyvsp[-3].sym).truelist, (yyvsp[-1].instr));
																		(yyval.lists).nextlist = merge((yyvsp[-3].sym).falselist, (yyvsp[0].lists).nextlist);
																		(yyval.lists).breaklist = (yyvsp[0].lists).breaklist;
																		(yyval.lists).continuelist = (yyvsp[0].lists).continuelist;
																		(yyval.lists).gotolist = (yyvsp[0].lists).gotolist;
																	}
#line 4255 "ansic.tab.c"
    break;

  case 200: /* selection_statement: IF '(' logic_expression ')' N statement ELSE M N statement  */
#line 1741 "ansic.y"
                                                                        {
																		printf("selection_statement: IF '(' expression ')' statement ELSE statement\n");
																		backpatch((yyvsp[-7].sym).truelist, (yyvsp[-5].instr));
																		backpatch((yyvsp[-7].sym).falselist, (yyvsp[-1].instr));
																		(yyval.lists).nextlist = merge((yyvsp[-4].lists).nextlist, (yyvsp[-2].lists).nextlist, (yyvsp[0].lists).nextlist);
																		(yyval.lists).breaklist = merge((yyvsp[-4].lists).breaklist, (yyvsp[0].lists).breaklist);
																		(yyval.lists).continuelist = merge((yyvsp[-4].lists).continuelist, (yyvsp[0].lists).continuelist);
																		(yyval.lists).gotolist = merge((yyvsp[-4].lists).gotolist, (yyvsp[0].lists).gotolist);
																	}
#line 4269 "ansic.tab.c"
    break;

  case 201: /* selection_statement: SWITCH '(' expression ')' M statement  */
#line 1750 "ansic.y"
                                                                                                {
																		printf("selection_statement: SWITCH '(' expression ')' statement\n");
																		if(!isintegral((yyvsp[-3].sym).typ))
																			yyerror("Error: switch expression must be integral\n");
																		(yyvsp[0].lists).breaklist = merge ((yyvsp[0].lists).breaklist, makelist(nextinstr));
																		gencode(GOTO_IR); /* Saltar al final del switch */
																		/* Completar salto denerado en regla de M */
																		backpatch((yyvsp[-1].lists).nextlist, nextinstr);
																		std::list<CASE_DATA *>::iterator it;
																		if((yyvsp[0].lists).caselist != NULL)
																		{
																			for(it = (yyvsp[0].lists).caselist->begin(); it != (yyvsp[0].lists).caselist->end(); it++)
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
																					symrec *s1 = (yyvsp[-3].sym).var;
																					* (int *)((char *)datablock+s->offset) = (*it)->val.intval;
																					if(isconstant((yyvsp[-3].sym).typ))
																					{
																						name = newtemp();
																						s1 = putsym(name, INTVAL | CONST_SPEC);
																						*(int *)((char *)datablock+s->offset) = (yyvsp[-3].sym).val.intval;
																					}
																					gencode(IF_EQ_IR, s1, s, addr);
																				}
																			}
																		}
																		backpatch((yyvsp[0].lists).breaklist, nextinstr);
																		(yyval.lists).breaklist = NULL;
																		(yyval.lists).continuelist = (yyvsp[0].lists).continuelist;
																		(yyval.lists).gotolist = (yyvsp[0].lists).gotolist;
																		(yyval.lists).nextlist = NULL;
																	}
#line 4314 "ansic.tab.c"
    break;

  case 202: /* logic_expression_statement: expression_statement  */
#line 1791 "ansic.y"
                                                                                                                                                        {
																										(yyval.sym)=(yyvsp[0].sym);
																										/* Verificar si espression es comparacion u operacion logica */
																										if((yyvsp[0].sym).truelist == nullptr || (yyvsp[0].sym).falselist == nullptr)
																										{
																											std::string *name = newtemp();
																											symrec *s0;
																											s0 = putsym(name, INTVAL | CONST_SPEC);
																											* (int *)(datablock+s0->offset) = 0;
																											(yyval.sym).truelist = makelist(nextinstr);
																											gencode(IF_NE_IR, (yyvsp[0].sym).var, s0, nullptr);
																											(yyval.sym).falselist = makelist(nextinstr);
																											gencode(GOTO_IR);
																										}
																									}
#line 4334 "ansic.tab.c"
    break;

  case 203: /* iteration_statement: WHILE N '(' logic_expression ')' N statement  */
#line 1808 "ansic.y"
                                                                                                                                                        {
																										printf("iteration_statement: WHILE '(' expression ')' statement\n");
																										backpatch((yyvsp[0].lists).nextlist, (yyvsp[-5].instr));
																										backpatch((yyvsp[0].lists).continuelist, (yyvsp[-5].instr));
																										backpatch((yyvsp[-3].sym).truelist, (yyvsp[-1].instr));
																										(yyval.lists).nextlist = (yyvsp[-3].sym).falselist;
																										gencode(GOTO_IR, (yyvsp[-5].instr));
																										backpatch((yyvsp[0].lists).breaklist, nextinstr);
																										(yyval.lists).breaklist = NULL;
																										(yyval.lists).continuelist = NULL;
																										(yyval.lists).gotolist = (yyvsp[0].lists).gotolist;
																									}
#line 4351 "ansic.tab.c"
    break;

  case 204: /* iteration_statement: DO N statement WHILE N '(' logic_expression ')' ';'  */
#line 1820 "ansic.y"
                                                                                                                                                {
																										printf("iteration_statement: DO statement WHILE '(' expression ')' ';'\n");
																										backpatch((yyvsp[-2].sym).truelist, (yyvsp[-7].instr));
																										backpatch((yyvsp[-6].lists).nextlist, (yyvsp[-4].instr));
																										backpatch((yyvsp[-6].lists).continuelist, (yyvsp[-4].instr));
																										backpatch((yyvsp[-6].lists).breaklist, nextinstr);
																										(yyval.lists).breaklist = NULL;
																										(yyval.lists).continuelist = NULL;
																										(yyval.lists).nextlist = (yyvsp[-2].sym).falselist;
																										(yyval.lists).gotolist = (yyvsp[-6].lists).gotolist;
																									}
#line 4367 "ansic.tab.c"
    break;

  case 205: /* iteration_statement: FOR '(' expression_statement N logic_expression_statement N ')' statement  */
#line 1831 "ansic.y"
                                                                                                                                {
																										printf("iteration_statement: FOR '(' expression_statement expression_statement ')' statement\n");
																										backpatch((yyvsp[-3].sym).truelist, (yyvsp[-2].instr));
																										backpatch((yyvsp[0].lists).nextlist, (yyvsp[-4].instr));
																										backpatch((yyvsp[0].lists).continuelist, (yyvsp[-4].instr));
																										(yyval.lists).nextlist = (yyvsp[-3].sym).falselist;
																										gencode(GOTO_IR, (yyvsp[-4].instr));
																										backpatch((yyvsp[0].lists).breaklist, nextinstr);
																										(yyval.lists).breaklist = NULL;
																										(yyval.lists).continuelist = NULL;
																										(yyval.lists).gotolist = (yyvsp[0].lists).gotolist;
																									}
#line 4384 "ansic.tab.c"
    break;

  case 206: /* iteration_statement: FOR '(' expression_statement N logic_expression_statement N expression ')' M N statement  */
#line 1843 "ansic.y"
                                                                                                                {
																										printf("iteration_statement: FOR '(' expression_statement expression_statement expression ')' statement\n");
																										backpatch((yyvsp[-6].sym).truelist, (yyvsp[-1].instr));		/* Completar saltos */
																										backpatch((yyvsp[0].lists).nextlist, (yyvsp[-5].instr));		/* Completar saltos */
																										backpatch((yyvsp[0].lists).continuelist, (yyvsp[-5].instr));	/* Completar saltos */
																										backpatch((yyvsp[-2].lists).nextlist, (yyvsp[-7].instr));			/* Completar saltos */
																										(yyval.lists).nextlist = (yyvsp[-6].sym).falselist;			/* Propagar saltos */
																										gencode(GOTO_IR, (yyvsp[-5].instr));				/* Insertar salto a */
																										backpatch((yyvsp[0].lists).breaklist, nextinstr);
																										(yyval.lists).breaklist = NULL;
																										(yyval.lists).continuelist = NULL;
																										(yyval.lists).gotolist = (yyvsp[0].lists).gotolist;
																									}
#line 4402 "ansic.tab.c"
    break;

  case 207: /* jump_statement: GOTO IDENTIFIER ';'  */
#line 1859 "ansic.y"
                                                {
										printf("jump_statement: GOTO IDENTIFIER ';'\n");
										(yyval.lists).continuelist = NULL;
										(yyval.lists).breaklist = NULL;
										(yyval.lists).nextlist = NULL;
										(yyval.lists).caselist = NULL;
										(yyval.lists).gotolist = makelist(new string((yyvsp[-1].token.name)), nextinstr);
										gencode(GOTO_IR);
									}
#line 4416 "ansic.tab.c"
    break;

  case 208: /* jump_statement: CONTINUE ';'  */
#line 1868 "ansic.y"
                                                        {
										printf("jump_statement: CONTINUE ';'\n");
										(yyval.lists).breaklist = NULL;
										(yyval.lists).nextlist = NULL;
										(yyval.lists).caselist = NULL;
										(yyval.lists).gotolist = NULL;
										(yyval.lists).continuelist = makelist(nextinstr);
										gencode(GOTO_IR);
									}
#line 4430 "ansic.tab.c"
    break;

  case 209: /* jump_statement: BREAK ';'  */
#line 1877 "ansic.y"
                                                                {
										printf("jump_statement: BREAK ';'\n");
										(yyval.lists).nextlist = NULL;
										(yyval.lists).continuelist = NULL;
										(yyval.lists).caselist = NULL;
										(yyval.lists).gotolist = NULL;
										(yyval.lists).breaklist = makelist(nextinstr);
										gencode(GOTO_IR);
									}
#line 4444 "ansic.tab.c"
    break;

  case 210: /* jump_statement: RETURN ';'  */
#line 1886 "ansic.y"
                                                        {
										printf("jump_statement: RETURN ';'\n");
										gencode(RET_IR);
										(yyval.lists).breaklist = NULL;
										(yyval.lists).nextlist = NULL;
										(yyval.lists).continuelist = NULL;
										(yyval.lists).caselist = NULL;
										(yyval.lists).gotolist = NULL;
									}
#line 4458 "ansic.tab.c"
    break;

  case 211: /* jump_statement: RETURN expression ';'  */
#line 1895 "ansic.y"
                                                {
										printf("jump_statement: RETURN expression ';'\n");
										gencode(RET_IR, (yyvsp[-1].sym).var, nullptr, nullptr);
										(yyval.lists).breaklist = NULL;
										(yyval.lists).nextlist = NULL;
										(yyval.lists).continuelist = NULL;
										(yyval.lists).caselist = NULL;
										(yyval.lists).gotolist = NULL;
									}
#line 4472 "ansic.tab.c"
    break;

  case 212: /* translation_unit: external_declaration  */
#line 1907 "ansic.y"
                                                                                {printf("translation_unit: external_declaration\n");}
#line 4478 "ansic.tab.c"
    break;

  case 213: /* translation_unit: translation_unit external_declaration  */
#line 1908 "ansic.y"
                                                                {printf("translation_unit: translation_unit external_declaration\n");}
#line 4484 "ansic.tab.c"
    break;

  case 214: /* external_declaration: function_definition  */
#line 1912 "ansic.y"
                                                                                {printf("external_declaration: function_definition\n");}
#line 4490 "ansic.tab.c"
    break;

  case 215: /* external_declaration: declaration  */
#line 1913 "ansic.y"
                                                                                        {printf("external_declaration: declaration\n");}
#line 4496 "ansic.tab.c"
    break;

  case 216: /* function_definition: declaration_specifiers declarator declaration_list compound_statement  */
#line 1917 "ansic.y"
                                                                                        {printf("function_definition: declaration_specifiers declarator declaration_list compound_statement\n");}
#line 4502 "ansic.tab.c"
    break;

  case 217: /* $@3: %empty  */
#line 1918 "ansic.y"
                                                                                                                        {
																					int typ = get_type((yyvsp[-1].sqlist)) | (yyvsp[0].id_data)->typ;
																					curr_func = install ((yyvsp[0].id_data)->name, typ);
																					gencode(PROC_IR, curr_func);
																					localsyms = new symboltable();
																					enter_scope();
																					installarg((yyvsp[0].id_data)->arglist);
																					/* Iniciar nueva tabla de etiquetas */
																					lab_table.clear();
																					setargs();
																				}
#line 4518 "ansic.tab.c"
    break;

  case 218: /* function_definition: declaration_specifiers declarator $@3 compound_statement  */
#line 1930 "ansic.y"
                                                                                                                                        {
		  																			printf("function_definition: declaration_specifiers declarator compound_statement\n");
																					//printlocalvars();
																					exit_scope();	  
																					curr_func->func_desc.sym_table = localsyms;
																					gencode(ENDPROC_IR, curr_func);
																					patch_gotos((yyvsp[0].lists).gotolist);
																				}
#line 4531 "ansic.tab.c"
    break;

  case 219: /* function_definition: declarator declaration_list compound_statement  */
#line 1939 "ansic.y"
                                                                                                                {printf("function_definition: declarator declaration_list compound_statement\n");}
#line 4537 "ansic.tab.c"
    break;

  case 220: /* $@4: %empty  */
#line 1940 "ansic.y"
                                                                                                                                                {
																					int typ = INTVAL | (yyvsp[0].id_data)->typ;
																					curr_func = install ((yyvsp[0].id_data)->name, typ);
																					gencode(PROC_IR, curr_func);
																					localsyms = new symboltable();
																					enter_scope();
																					installarg((yyvsp[0].id_data)->arglist);
																					/* Iniciar nueva tabla de etiquetas */
																					lab_table.clear();
																					setargs();
																				}
#line 4553 "ansic.tab.c"
    break;

  case 221: /* function_definition: declarator $@4 compound_statement  */
#line 1951 "ansic.y"
                                                                                                                                        {
		  																			printf("function_definition: declarator compound_statement\n");
																					//printlocalvars();
																					exit_scope();	  
																					curr_func->func_desc.sym_table = localsyms;
																					gencode(ENDPROC_IR, curr_func);
																					patch_gotos((yyvsp[0].lists).gotolist);
																				}
#line 4566 "ansic.tab.c"
    break;


#line 4570 "ansic.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1961 "ansic.y"


int main(int argc, char *argv[])
{
	string fname; /* Para guardar nombre de archivo compilandose */
	/*Crear tabla de simbolos globales*/
	sym_table = new symboltable();
	cout << "Compilador de C version 1.0\n";
	cout << "EQUIPO:5\nHinojosa Ruiz Zianya Samanta\nCoronilla Hernandez Emmanuel\nArriaga Saldaña Jonathan Esau\n\n";
	if(argc>1)
	{
		yyin =fopen(argv[1], "r");
		fname = argv[1];
	}
	else
	{
		cout << "Uso: " << argv[0] << " <filename>\n";
		return(0);
	}
	yyparse();
	printvars();
	printf("\nCodigo intermedio:\n");
	print_icode();
	print_code(fname);
	return 0;
}
