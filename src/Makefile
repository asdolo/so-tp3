.PHONY : all clean run new

MPIROOT = /usr

CFLAGS+= -Wall -g $(INCL)
CC=gcc
MPICC=  $(MPIROOT)/bin/mpic++
INCL= -I$(MPIROOT)/include
SRCS= consola.cpp main.cpp nodo.cpp HashMap.cpp
BIN= dist_hashmap

all: dist_hashmap

test-load: $(OBJ) test-load.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ test-load.cpp $(OBJ) $(LDLIBS)
	
test-load-run: test-load dist_hashmap
	rm -f output-load.txt
	cat input-test-load | mpiexec -np 6 ./dist_hashmap
	./test-load

test-add-and-inc: $(OBJ) test-add-and-inc.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ test-add-and-inc.cpp $(OBJ) $(LDLIBS)
	
test-add-and-inc-run: test-add-and-inc dist_hashmap
	rm -f output-add-and-inc.txt
	cat input-test-add-and-inc | mpiexec -np 6 ./dist_hashmap
	./test-add-and-inc

test-member: $(OBJ) test-member.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ test-member.cpp $(OBJ) $(LDLIBS)
	
test-member-run: test-member dist_hashmap
	rm -f output-member.txt
	cat input-test-member | mpiexec -np 6 ./dist_hashmap
	./test-member

test-maximum: $(OBJ) test-maximum.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ test-maximum.cpp $(OBJ) $(LDLIBS)
	
test-maximum-run: test-maximum dist_hashmap
	rm -f output-maximum.txt
	cat input-test-maximum | mpiexec -np 6 ./dist_hashmap
	./test-maximum

$(BIN): $(SRCS)
	$(MPICC) $(CFLAGS) -o $(BIN) $(SRCS)

clean:
	rm -f $(BIN)
	rm -f output-*.txt
	rm -f test-load
	rm -f test-member
	rm -f test-add-and-inc
	rm -f test-maximum

new: clean all
