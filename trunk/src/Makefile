CC      = gcc
LDFLAGS = -g

all: etapa3 

etapa3: pico

doc: Doxyfile $(HEAD1)
	doxygen Doxyfile

pico: lex.yy.c y.tab.c tokens.h node.o lista.o symbol_table.o inherited.o labels.o main-pico.c inherited.o
	$(CC) $(LDFLAGS) -o pico lex.yy.c y.tab.c main-pico.c node.o labels.o lista.o symbol_table.o inherited.o -lfl

lex.yy.c: scanner.l tokens.h
	flex scanner.l;

tokens.h: y.tab.c

y.tab.c: pico.y 
	yacc -d pico.y ; mv y.tab.h tokens.h

inherited.o: inherited.c inherited.h node.o lista.o symbol_table.o
	$(CC) $(LDFLAGS) -c inherited.c

node.o: node.c node.h
	$(CC) $(LDFLAGS) -c node.c

lista.o: lista.c lista.h
	$(CC) $(LDFLAGS) -c lista.c

symbol_table.o: symbol_table.c symbol_table.h
	$(CC) $(LDFLAGS) -c symbol_table.c
	
labels.o: labels.c labels.h
	$(CC) $(LDFLAGS) -c labels.c

clean:
	rm -f *.o lex.yy.? y.tab.? tokens.h pico
