COMPILATION_FLAGS=-Wall -Wextra -pedantic 
ARQUIVOS_BINARIOS=./arq_bin

all: prog

prog: musica.o playlist.o projeto.o reprodutor.o sistema.o
	g++ $(ARQUIVOS_BINARIOS)/musica.o $(ARQUIVOS_BINARIOS)/playlist.o $(ARQUIVOS_BINARIOS)/projeto.o $(ARQUIVOS_BINARIOS)/reprodutor.o $(ARQUIVOS_BINARIOS)/sistema.o -o prog.exe

musica.o: musica.cpp musica.h
	g++ -c -o $(ARQUIVOS_BINARIOS)/musica.o musica.cpp $(COMPILATION_FLAGS)

playlist.o: playlist.cpp playlist.h
	g++ -c -o $(ARQUIVOS_BINARIOS)/playlist.o playlist.cpp $(COMPILATION_FLAGS)

projeto.o: projeto.cpp
	g++ -c -o $(ARQUIVOS_BINARIOS)/projeto.o projeto.cpp $(COMPILATION_FLAGS)

reprodutor.o: reprodutor.cpp reprodutor.h
	g++ -c -o $(ARQUIVOS_BINARIOS)/reprodutor.o reprodutor.cpp $(COMPILATION_FLAGS)

sistema.o: sistema.cpp sistema.h
	g++ -c -o $(ARQUIVOS_BINARIOS)/sistema.o sistema.cpp $(COMPILATION_FLAGS)

clean: 
	@del /f /s /q arq_bin\*.o prog.exe >nul

.PHONY: clean all