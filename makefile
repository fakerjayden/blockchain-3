CC=g++
CFLAGS=-c -Wall -std=c++11
LDFLAGS=
SOURCES=run-final.cc block-miner.cc block.cc transaction.cc
OBJECTS=$(SOURCES:.cc=.o)
EXECUTABLE=final

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cc.o:
	$(CC) $(CFLAGS) $< -o $@

#CC=g++
#CFLAGS=-c -Wall -std=c++11
#all: final
#final: run-final.o block-miner.o block.o transaction.o
#	$(CC) $(CFLAGS) run-final.o block-miner.o block.o transaction.o -o final
#
#run-final.o:run-final.cc
#	$(CC) $(CFLAGS) run-final.cc
#
#block-miner.o: block-miner.cc
#	$(CC) $(CFLAGS) block-miner.cc
#
#block.o: block.cc
#	$(CC) $(CFLAGS) block.cc
#
#transaction.o: transaction.cc
#	$(CC) $(CFLAGS) transaction.cc

