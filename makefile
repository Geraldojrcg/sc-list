#PROJETO EDB

PROG = driver_list
CC = g++
CPPFLAGS = -O0 -g -std=c++11
OBJS = driver_list.o
HEADER1 = ./include/list.hpp
SRC_DIR     = ./src/
BIN_DIR     = ./bin/

$(PROG): $(OBJS)
	$(CC) $(OBJS) -o $(PROG)
	mv *.o $(PROG) $(BIN_DIR)

driver_list.o: $(HEADER1)
	$(CC) $(CPPFLAGS) -c $(SRC_DIR)driver_list.cpp

clean:
	rm -f $(BIN_DIR)*.o $(PROG)
