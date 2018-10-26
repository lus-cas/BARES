CPP = g++
CPPFLAGS = -Wall -std=c++11
BIN = bin/bares
OBJ = bares.o evaluator.o parser.o file.o

build: $(OBJ)
	$(CPP) $(OBJ) -o $(BIN)
	rm -rf build/*.o
	mv *.o build/

bares.o:
	$(CPP) $(CPPFLAGS) -c src/bares.cpp

evaluator.o: include/evaluator.h
	$(CPP) $(CPPFLAGS) -c src/evaluator.cpp

parser.o: include/parser.h
	$(CPP) $(CPPFLAGS) -c src/parser.cpp

file.o: include/file.h
	$(CPP) $(CPPFLAGS) -c src/file.cpp
