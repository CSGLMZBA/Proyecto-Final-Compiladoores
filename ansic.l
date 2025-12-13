%{
#include <iostream>
#include <string>
#include <list>
#include <cstring>
#include <stdio.h>
#include <ctype.h>
#include "symdefs.h"
#include "ansic.tab.h"


void count();
void comment();
void yyerror(const char *);

//YYSTYPE yylval;
int lineno = 0;
int column = 0;

char *buffer = NULL;
int buffer_size = 0;

#define hextoint(x) (isdigit((x)) ? (x) - '0' : ((x) - 'A') + 10)

%}

D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*
hex			[0-9a-fA-F]{1,2}
oct			[0-7]{1,3}

%option noyywrap
%x INSTRING INCHAR

%%
"/*"			        { comment(); }
^#.*					{}
"auto"			        { count(); return(AUTO); }
"break"			        { count(); return(BREAK); }
"case"			        { count(); return(CASE); }
"char"			        { count(); return(CHAR); }
"const"			        { count(); return(CONST); }
"continue"		        { count(); return(CONTINUE); }
"default"		        { count(); return(DEFAULT); }
"do"			        { count(); return(DO); }
"double"		        { count(); return(DOUBLE); }
"else"			        { count(); return(ELSE); }
"enum"			        { count(); return(ENUM); }
"extern"		        { count(); return(EXTERN); }
"float"			        { count(); return(FLOAT); }
"for"			        { count(); return(FOR); }
"goto"			        { count(); return(GOTO); }
"if"			        { count(); return(IF); }
"int"			        { count(); return(INT); }
"long"			        { count(); return(LONG); }
"register"		        { count(); return(REGISTER); }
"return"		        { count(); return(RETURN); }
"short"			        { count(); return(SHORT); }
"signed"		        { count(); return(SIGNED); }
"sizeof"		        { count(); return(SIZEOF); }
"static"		        { count(); return(STATIC); }
"struct"		        { count(); return(STRUCT); }
"switch"		        { count(); return(SWITCH); }
"typedef"		        { count(); return(TYPEDEF); }
"union"			        { count(); return(UNION); }
"unsigned"		        { count(); return(UNSIGNED); }
"void"			        { count(); return(VOID); }
"volatile"		        { count(); return(VOLATILE); }
"while"			        { count(); return(WHILE); }

{L}({L}|{D})*		    { count(); yylval.token.name = strdup(yytext); return(IDENTIFIER); }

0[xX]{H}+{IS}?		    { count(); yylval.token.ival = strtol(yytext, NULL, 16); yylval.token.type = INTVAL; return(CONSTANT); }
0{D}+{IS}?		        { count(); yylval.token.ival = strtol(yytext, NULL, 8); yylval.token.type = INTVAL; return(CONSTANT); }
{D}+{IS}?		        { count(); yylval.token.ival = atol(yytext); yylval.token.type = INTVAL; return(CONSTANT); }
L?'					    { 
							count();
							buffer = (char *) malloc(1);
							buffer_size = 1;
							buffer[0]=0;
							BEGIN(INCHAR);
						}
L?\"					{
							count();
							buffer = (char *) malloc(1);
							buffer_size = 1;
							strcpy(buffer,"");
							BEGIN(INSTRING);
						}
<INCHAR,INSTRING>\n		{
							count();
							yyerror("Unterminated character or string literal");
							free(buffer);
							BEGIN(INITIAL);
						}
<INCHAR,INSTRING><<EOF>>	{
								count();
								yyerror("EOF in character or string literal");
								free(buffer);
								BEGIN(INITIAL);
							}
<INCHAR,INSTRING>[^\\\n"']	{
								count();
								buffer = (char *) realloc(buffer, buffer_size + yyleng + 1);
								buffer_size += yyleng;
								strcat(buffer, yytext);
								if(YY_START == INCHAR && buffer_size >2)
									yyerror("Ilegal length of character literal");
							}
<INSTRING>\\\n				{
								count();
								/* Ignore this */}							
<INCHAR,INSTRING>\\{hex}	{
								count();
								int temp = 0, loop = 0;
								for(loop = yyleng-2; loop>0; loop--)
								{
									temp <<= 4;
									temp += hextoint(toupper(yytext[yyleng-loop]));
								}
								buffer = (char *) realloc(buffer, buffer_size + 1);
								buffer[buffer_size-1] = temp;
								buffer[buffer_size] = '\0';
								buffer_size += 1;
								if(YY_START == INCHAR && buffer_size >2)
									yyerror("Ilegal length of character constant");
							}				
<INCHAR,INSTRING>\\{oct}	{
								count();
								int temp = 0, loop = 0;
								for(loop = yyleng-1; loop>0; loop--)
								{
									temp <<= 3;
									temp += (yytext[yyleng-loop] - '0');
								}
								buffer = (char *) realloc(buffer, buffer_size + 1);
								buffer[buffer_size-1] = temp;
								buffer[buffer_size] = '\0';
								buffer_size += 1;
								if(YY_START == INCHAR && buffer_size >2)
									yyerror("Ilegal length of character constant");
							}
<INCHAR,INSTRING>\\[^\n]	{
								count();
								buffer =(char *) realloc (buffer, buffer_size + 1);
								switch(yytext[yyleng-1])
								{
									case 'b' : buffer[buffer_size-1] = '\b'; break;
									case 't' : buffer[buffer_size-1] = '\t'; break;
									case 'n' : buffer[buffer_size-1] = '\n'; break;
									case 'v' : buffer[buffer_size-1] = '\v'; break;
									case 'f' : buffer[buffer_size-1] = '\f'; break;
									case 'r' : buffer[buffer_size-1] = '\r'; break;
									default  : buffer[buffer_size-1] = yytext[yyleng-1];
								}
								buffer[buffer_size] = '\0';
								buffer_size += 1;
								if(YY_START == INCHAR && buffer_size >2)
									yyerror("Ilegal length of character constant");
							}
<INCHAR,INSTRING>'		{
							count();
							if(YY_START==INCHAR)
							{
								yylval.token.cval = buffer[0];
								if(buffer_size > 2)
									yyerror("Ilegal length of character constant");
								yylval.token.type = CHARVAL;
								free(buffer);
								BEGIN(INITIAL);
								return(CONSTANT);
							}
							buffer = (char *) realloc(buffer, buffer_size+yyleng+1);
							buffer_size += yyleng;
							strcat(buffer, yytext);
						}
<INSTRING,INCHAR>\"		{
							count();
							if(YY_START==INSTRING)
							{
								yylval.token.str = buffer;
								/*free(buffer);*/
								BEGIN(INITIAL);
								return(STRING_LITERAL);
							}
							buffer = (char *) realloc(buffer, buffer_size+yyleng+1);
							buffer_size += yyleng;
							strcat(buffer,yytext);
							if(buffer_size>2)
								yyerror("Ilegal length of character constant");
						}	

{D}+{E}{FS}?		    { count(); yylval.token.dval = atof(yytext); yylval.token.type = DOUBLEVAL; return(CONSTANT); }
{D}*"."{D}+({E})?{FS}?	{ count(); yylval.token.dval = atof(yytext); yylval.token.type = DOUBLEVAL; return(CONSTANT); }
{D}+"."{D}*({E})?{FS}?	{ count(); yylval.token.dval = atof(yytext); yylval.token.type = DOUBLEVAL; return(CONSTANT); }
				
"..."			        { count(); return(ELLIPSIS); }
">>="			        { count(); return(RIGHT_ASSIGN); }
"<<="			        { count(); return(LEFT_ASSIGN); }
"+="			        { count(); return(ADD_ASSIGN); }
"-="			        { count(); return(SUB_ASSIGN); }
"*="			        { count(); return(MUL_ASSIGN); }
"/="			        { count(); return(DIV_ASSIGN); }
"%="			        { count(); return(MOD_ASSIGN); }
"&="			        { count(); return(AND_ASSIGN); }
"^="			        { count(); return(XOR_ASSIGN); }
"|="			        { count(); return(OR_ASSIGN); }
">>"			        { count(); return(RIGHT_OP); }
"<<"			        { count(); return(LEFT_OP); }
"++"			        { count(); return(INC_OP); }
"--"			        { count(); return(DEC_OP); }
"->"			        { count(); return(PTR_OP); }
"&&"			        { count(); return(AND_OP); }
"||"			        { count(); return(OR_OP); }
"<="			        { count(); return(LE_OP); }
">="			        { count(); return(GE_OP); }
"=="			        { count(); return(EQ_OP); }
"!="			        { count(); return(NE_OP); }
";"			            { count(); return(';'); }
("{"|"<%")		        { count(); return('{'); }
("}"|"%>")		        { count(); return('}'); }
","			            { count(); return(','); }
":"			            { count(); return(':'); }
"="			            { count(); return('='); }
"("			            { count(); return('('); }
")"			            { count(); return(')'); }
("["|"<:")		        { count(); return('['); }
("]"|":>")		        { count(); return(']'); }
"."			            { count(); return('.'); }
"&"			            { count(); return('&'); }
"!"			            { count(); return('!'); }
"~"			            { count(); return('~'); }
"-"			            { count(); return('-'); }
"+"			            { count(); return('+'); }
"*"			            { count(); return('*'); }
"/"			            { count(); return('/'); }
"%"			            { count(); return('%'); }
"<"			            { count(); return('<'); }
">"			            { count(); return('>'); }
"^"			            { count(); return('^'); }
"|"			            { count(); return('|'); }
"?"			            { count(); return('?'); }

[ \t\v\n\f]		        { 
							count(); 
							if(yytext[0]=='\n')
								lineno++;
						}
.			            { /* ignore bad characters */ }

%%

void yyerror(const char *msg)
{
	printf("\nError:%s en linea %d columna %d\n", msg, lineno+1, column+1);
	exit(1);
}

void comment()
{
	char c, c1;

loop:
	while ((c = yyinput()) != '*' && c != 0)
		;

	if ((c1 = yyinput()) != '/' && c != 0)
	{
		unput(c1);
		goto loop;
	}
}

void count()
{
	int i;

	for (i = 0; yytext[i] != '\0'; i++)
		if (yytext[i] == '\n')
			column = 0;
		else if (yytext[i] == '\t')
			column += 8 - (column % 8);
		else
			column++;

	/*"ECHO";*/
}

void printchr(char c)
{
	if(c == '\a')
	{
		printf("\\a");
	}
	else if(c == '\b')
	{
		printf("\\b");
	}
	else if(c == '\f')
	{
		printf("\\f");
	}
	else if(c == '\n')
	{
		printf("\\n");
	}
	else if(c == '\r')
	{
		printf("\\r");
	}
	else if(c == '\t')
	{
		printf("\\t");
	}
	else if(c == '\v')
	{
		printf("\\v");
	}
	else 
	{
		if(isprint(c))
			printf("%c",c);
		else
			printf("\\x%02X", c);
	}
}

void printstr(char *str)
{
	char c;
	while((c = *str++) != '\0')
	{
		printchr(c);
	}
}
