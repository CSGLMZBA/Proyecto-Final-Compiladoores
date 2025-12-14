CC = gcc
CFLAGS = -lstdc++
LEX = flex
YACC = bison

all: compiler

compiler: ansic.tab.c lex.yy.c
	$(CC) $(CFLAGS) ansic.tab.c lex.yy.c -o compiler

ansic.tab.c ansic.tab.h: ansic.y
	$(YACC) -d ansic.y

lex.yy.c: ansic.l ansic.tab.h
	$(LEX) ansic.l

clean:
	rm -f ansic.tab.c ansic.tab.h lex.yy.c compiler

test: compiler
	./compiler codigo.c
	./compiler codigo2.c
	./compiler codigo3.c
	./compiler codigo4.c
	./compiler codigo5.c