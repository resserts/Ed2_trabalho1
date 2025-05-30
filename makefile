PROJ_NAME=ted
ALUNO=tiagoms
LIBS=-lm
OBJETOS=main.o smutreap.o retangulo.o circulo.o linha.o texto.o svg.o geo.o lista.o boundingBox.o query.o
# compilador
CC=gcc

# Flags

CFLAGS= -g -O0 -std=c99 -fstack-protector-all -Werror=implicit-function-declaration

LDFLAGS=-O0
$(PROJ_NAME): $(OBJETOS)
	$(CC) -o $(PROJ_NAME) $(LDFLAGS) $(OBJETOS) $(LIBS)
%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

#
# COLOCAR DEPENDENCIAS DE CADA MODULO
#
# Exemplo: suponha que o arquivo a.c possua os seguintes includes:
#
# #include "a.h"
# #include "b.h"
# #include "c.h"
#
# a.o: a.h b.h c.h a.c
#
# EMPACOTAR PARA ENTREGA
#
# - se necessario: sudo apt install zip
pack: $(PROJ_NAME)
	rm -f ../$(ALUNO).zip
	echo $(ALUNO)
	date >> .entrega
	cd ..; zip $(ALUNO).zip -r src/*.c src/*.h src/Makefile LEIA-ME.txt .entrega
