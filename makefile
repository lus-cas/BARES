CPP = g++
CPPFLAGS = -Wall -std=c++11
BIN = bin/bares
OBJ = main.o bares.o parser.o file.o

build: $(OBJ)
	$(CPP) $(OBJ) -o $(BIN)
	rm -rf build/*.o
	mv *.o build/

main.o:
	$(CPP) $(CPPFLAGS) -c src/main.cpp

bares.o: include/bares.h
	$(CPP) $(CPPFLAGS) -c src/bares.cpp

parser.o: include/parser.h
	$(CPP) $(CPPFLAGS) -c src/parser.cpp

file.o: include/file.h
	$(CPP) $(CPPFLAGS) -c src/file.cpp
